#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "calc6.h"
#include "y.tab.h"

/* symbol tables */
varSymTable globalVarTable;
funcSymTable funcTable;
char *to_lower(char *str);
tableSearchResult *searchVarTable(nodeType *p, varSymTable *table, bool is_global);
tableSearchResult *searchPrmTable(nodeType *p, prmSymTable *table);
char *varlookup(nodeType *p);
int arr_symgen(char *var, nodeType *p);
int func_symgen(char *name, nodeType *p);

/* output buffers and pointers */
char *head;
char *output_start;
char *output_saved;
char *wip;

static int lbl = 0;
static int scope = -1; /* -1: global scope, <num>: entry index in funcTable */

int ex(nodeType *p)
{
    int lblx, lbly, lbl1, lbl2;
    char *rpos; /* register position */

    if (!p)
        return 0;
    switch (p->type)
    {
    case typeCon:
        switch (p->con.conType)
        {
        case conTypeInt:
            head += sprintf(head, "\tpush\t%d\n", p->con.intValue);
            break;
        case conTypeChar:
            head += sprintf(head, "\tpush\t'%c'\n", p->con.charValue);
            break;
        case conTypeString:
            head += sprintf(head, "\tpush\t\"%s\"\n", p->con.strValue);
            break;
        }
        break;
    case typeId:
    {
        rpos = varlookup(p);
        head += sprintf(head, "\tpush\t%s\n", rpos);
    }
    break;
    case typeOpr:
        switch (p->opr.oper)
        {
        case ARRAY:
        {
            int offset = scope == -1 ? 0 : funcTable.functions[scope].prmtable.count;
            int base = arr_symgen(p->opr.op[0]->id.name, p->opr.op[1]) + offset;
            if (p->opr.nops == 3)
            {
                ex(p->opr.op[2]); /* Prepare the expression value */
                head += sprintf(head, "\tpop\tac\n");
                for (int i = 0; i < p->opr.op[1]->ari.width; i++)
                {
                    head += sprintf(head, "\tpush\tac\n");
                    head += sprintf(head, "\tpop\t%s[%i]\n", scope == -1 ? "sb" : "fp", base + i);
                }
            }
        }
        break;
        case FOR:
            ex(p->opr.op[0]);
            head += sprintf(head, "L%03d:\n", lblx = lbl++);
            ex(p->opr.op[1]);
            head += sprintf(head, "\tj0\tL%03d\n", lbly = lbl++);
            ex(p->opr.op[3]);
            ex(p->opr.op[2]);
            head += sprintf(head, "\tjmp\tL%03d\n", lblx);
            head += sprintf(head, "L%03d:\n", lbly);
            break;
        case WHILE:
            head += sprintf(head, "L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
            head += sprintf(head, "\tj0\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            head += sprintf(head, "\tjmp\tL%03d\n", lbl1);
            head += sprintf(head, "L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2)
            {
                /* if else */
                head += sprintf(head, "\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                head += sprintf(head, "\tjmp\tL%03d\n", lbl2 = lbl++);
                head += sprintf(head, "L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                head += sprintf(head, "L%03d:\n", lbl2);
            }
            else
            {
                /* if */
                head += sprintf(head, "\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                head += sprintf(head, "L%03d:\n", lbl1);
            }
            break;
        case GETI:
            head += sprintf(head, "\tgeti\n");
            rpos = varlookup(p->opr.op[0]);
            head += sprintf(head, "\tpop\t%s\n", rpos);
            break;
        case GETC:
            head += sprintf(head, "\tgetc\n");
            rpos = varlookup(p->opr.op[0]);
            head += sprintf(head, "\tpop\t%s\n", rpos);
            break;
        case GETS:
            head += sprintf(head, "\tgets\n");
            rpos = varlookup(p->opr.op[0]);
            head += sprintf(head, "\tpop\t%s\n", rpos);
            break;
        case PUTI:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputi\n");
            break;
        case PUTI_:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputi_\n");
            break;
        case PUTC:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputc\n");
            break;
        case PUTC_:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputc_\n");
            break;
        case PUTS:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputs\n");
            break;
        case PUTS_:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tputs_\n");
            break;
        case '=':
            ex(p->opr.op[1]);
            rpos = varlookup(p->opr.op[0]);
            head += sprintf(head, "\tpop\t%s\n", rpos);
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            head += sprintf(head, "\tneg\n");
            break;
        case RETURN:
            if (scope == -1) {
                fprintf(stderr, "Error: return statement outside function\n");
                exit(1);
            }
            if (p->opr.op[0] != NULL) {
                ex(p->opr.op[0]);
            }
            head += sprintf(head, "\tret\n");
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch (p->opr.oper)
            {
            case '+':
                head += sprintf(head, "\tadd\n");
                break;
            case '-':
                head += sprintf(head, "\tsub\n");
                break;
            case '*':
                head += sprintf(head, "\tmul\n");
                break;
            case '/':
                head += sprintf(head, "\tdiv\n");
                break;
            case '%':
                head += sprintf(head, "\tmod\n");
                break;
            case '<':
                head += sprintf(head, "\tcompLT\n");
                break;
            case '>':
                head += sprintf(head, "\tcompGT\n");
                break;
            case GE:
                head += sprintf(head, "\tcompGE\n");
                break;
            case LE:
                head += sprintf(head, "\tcompLE\n");
                break;
            case NE:
                head += sprintf(head, "\tcompNE\n");
                break;
            case EQ:
                head += sprintf(head, "\tcompEQ\n");
                break;
            case AND:
                head += sprintf(head, "\tand\n");
                break;
            case OR:
                head += sprintf(head, "\tor\n");
                break;
            }
        }
        break;
    case typeFunc:
        lbl1 = lbl++;
        lbl2 = lbl++;
        head += sprintf(head, "\tjmp\tL%03d\n", lbl2);
        head += sprintf(head, "L%03d:\n", lbl1);

        scope = func_symgen(p->func.name, p->func.param);
        int temp = scope;
        output_saved = head;
        head = wip;
        ex(p->func.body);   /* generate function body in WIP buffer */
        scope = -1;
        head = output_saved;

        int param_count = funcTable.functions[temp].prmtable.count;
        int var_width = funcTable.functions[temp].vartable.width;
        head += sprintf(head, "\tvar %i,%i\n", param_count, var_width); /* generate var statement in output buffer */

        head += sprintf(head, "%s", wip);   /* copy WIP buffer to output buffer */

        head += sprintf(head, "\tret\n");
        head += sprintf(head, "L%03d:\n", lbl2);
        break;
    case typeAri:
    case typeAre:
    case typePrm:
        // Won't be running ex() on these node types
        break;
    }
    return 0;
}

char *to_lower(char *str)
{
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        new_str[i] = tolower(str[i]);
    }
    new_str[len] = '\0';
    return new_str;
}

tableSearchResult *searchVarTable(nodeType *p, varSymTable *table, bool is_global)
{
    tableSearchResult *result = malloc(sizeof(tableSearchResult));
    result->reg = is_global ? "sb" : "fp";
    int param_offset = is_global ? 0 : funcTable.functions[scope].prmtable.count;

    char *loweredVar = to_lower(p->id.name);
    for (int i = 0; i < table->count; i++)
    {
        varSymEntry *var = &table->variables[i];
        if (strcmp(var->symbol, loweredVar) == 0)
        {
            result->found = true;
            if (p->id.has_array_expr)
            {
                if (var->ndim == 0)
                {
                    fprintf(stderr, "%s is not an array\n", var->symbol);
                    exit(1);
                }
                head += sprintf(head, "\tpush\t%d\n", var->offset + param_offset);
                for (int j = 0; j < p->id.op->are.ndim; j++)
                {
                    if (j == 0)
                    {
                        ex(p->id.op->are.op[j]);
                    }
                    else
                    {
                        head += sprintf(head, "\tpush\t%i\n", var->dims[j]);
                        head += sprintf(head, "\tmul\n");
                        ex(p->id.op->are.op[j]);
                        head += sprintf(head, "\tadd\n");
                    }
                }
                head += sprintf(head, "\tadd\n");
                head += sprintf(head, "\tpop\tac\n");
                result->offset = -1; /* offset dynamically calculated */
            }
            else
            {
                result->offset = var->offset + param_offset; /* offset statically determined */
            }
            return result;
        }
    }
    result->found = false; /* not found */
    return result;
}

tableSearchResult *searchPrmTable(nodeType *p, prmSymTable *table)
{
    tableSearchResult *result = malloc(sizeof(tableSearchResult));

    char *loweredVar = to_lower(p->id.name);
    for (int i = 0; i < table->count; i++)
    {
        prmSymEntry *var = &table->parameters[i];
        if (strcmp(var->symbol, loweredVar) == 0)
        {
            result->found = true;
            if (p->id.has_array_expr)
            {
                if (var->is_array == false)
                {
                    fprintf(stderr, "%s is not an array\n", var->symbol);
                    exit(1);
                }
                if (p->id.op->are.ndim != 1)
                {
                    fprintf(stderr, "n-d array indexing not supported for parameters yet\n");
                    exit(1);
                }
                head += sprintf(head, "\tpush\tfp[%d]\n", i);
                ex(p->id.op->are.op[0]);
                head += sprintf(head, "\tadd\n");
                head += sprintf(head, "\tpop\tac\n");
                result->offset = -1; /* offset dynamically calculated */
                result->reg = "sb";
                return result;
            }
            else if (var->is_array == true)
            { /* auto de-referencing case */
                head += sprintf(head, "\tpush\tfp[%d]\n", i);
                head += sprintf(head, "\tpop\tac\n");
                result->offset = -1; /* offset dynamically calculated */
                result->reg = "sb";
                return result;
            }
            else
            {
                result->offset = i; /* offset statically determined */
                result->reg = "fp";
                return result;
            }
        }
    }
    result->found = false; /* not found */
    return result;
}

char *varlookup(nodeType *p)
{
    tableSearchResult *t;
    char *r = malloc(20);

    // TODO: Add or case to support @ syntax
    if (scope == -1)
    {
        t = searchVarTable(p, &globalVarTable, true);
        if (t->found)
        {
            if (t->offset == -1)
            {
                sprintf(r, "%s[%s]", t->reg, "ac");
            }
            else
            {
                sprintf(r, "%s[%d]", t->reg, t->offset);
            }
            return r;
        }
    }
    else
    {
        // Search local vartable
        t = searchVarTable(p, &funcTable.functions[scope].vartable, false);
        if (t->found)
        {
            if (t->offset == -1)
            {
                sprintf(r, "%s[%s]", t->reg, "ac"); /* fp[ac] */
            }
            else
            {
                sprintf(r, "%s[%d]", t->reg, t->offset); /* fp[<offset>] */
            }
            return r;
        }
        // Search local prmtable
        t = searchPrmTable(p, &funcTable.functions[scope].prmtable);
        if (t->found)
        {
            if (t->offset == -1)
            {
                sprintf(r, "%s[%s]", t->reg, "ac"); /* sb[ac], pass by reference */
            }
            else
            {
                sprintf(r, "%s[%d]", t->reg, t->offset); /* fp[<offset>], pass by value */
            }
            return r;
        }
        // Search global vartable
        t = searchVarTable(p, &globalVarTable, true);
        if (t->found)
        {
            if (t->offset == -1)
            {
                sprintf(r, "%s[%s]", t->reg, "ac"); /* sb[ac] */
            }
            else
            {
                sprintf(r, "%s[%d]", t->reg, t->offset); /* sb[<offset>] */
            }
            return r;
        }
    }

    // Declare on first use
    varSymTable *table = scope == -1 ? &globalVarTable : &funcTable.functions[scope].vartable;
    varSymEntry *newEntry = &table->variables[table->count];
    newEntry->symbol = to_lower(p->id.name);
    newEntry->ndim = 0;
    newEntry->offset = table->width;
    table->count++;
    table->width++;
    int actual_offset = newEntry->offset + (scope == -1 ? 0 : funcTable.functions[scope].prmtable.count);
    sprintf(r, "%s[%d]", scope == -1 ? "sb" : "fp", actual_offset);
    return r;
}

int arr_symgen(char *var, nodeType *p)
{
    varSymTable *table = scope == -1 ? &globalVarTable : &funcTable.functions[scope].vartable;
    char *loweredVar = to_lower(var);
    for (int i = 0; i < table->count; i++)
    {
        if (strcmp(table->variables[i].symbol, loweredVar) == 0)
        {
            fprintf(stderr, "array \"%s\" already declared\n", var);
            exit(1);
        }
    }
    varSymEntry *newEntry = &table->variables[table->count];
    newEntry->symbol = loweredVar;
    newEntry->ndim = p->ari.ndim;
    memcpy(newEntry->dims, p->ari.dims, sizeof(int) * p->ari.ndim);
    newEntry->offset = table->width;
    table->count++;
    table->width += p->ari.width;
    return newEntry->offset;
}

// Creates a new function symbol table entry, populates name
// and parameter table, and returns the index of the new entry
int func_symgen(char *name, nodeType *p)
{
    char *loweredName = to_lower(name);
    for (int i = 0; i < funcTable.count; i++)
    {
        if (strcmp(funcTable.functions[i].symbol, loweredName) == 0)
        {
            fprintf(stderr, "function \"%s\" already declared\n", name);
            exit(1);
        }
    }
    funcSymEntry *newEntry = &funcTable.functions[funcTable.count];
    newEntry->symbol = loweredName;
    newEntry->prmtable.count = p->prm.nparams;
    for (int i = 0; i < p->prm.nparams; i++)
    {
        newEntry->prmtable.parameters[i].symbol = to_lower(p->prm.op[i]->id.name);
        newEntry->prmtable.parameters[i].is_array = p->prm.op[i]->id.has_array_expr;
    }
    funcTable.count++;
    return funcTable.count - 1;
}
