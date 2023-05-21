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

static int lbl = 0;
static int scope = -1; /* -1: global scope, <num>: entry index in funcTable */

int ex(nodeType *p)
{
    int lblx, lbly, lbl1, lbl2;

    if (!p)
        return 0;
    switch (p->type)
    {
    case typeCon:
        switch (p->con.conType)
        {
        case conTypeInt:
            output += sprintf(output, "\tpush\t%d\n", p->con.intValue);
            break;
        case conTypeChar:
            output += sprintf(output, "\tpush\t'%c'\n", p->con.charValue);
            break;
        case conTypeString:
            output += sprintf(output, "\tpush\t\"%s\"\n", p->con.strValue);
            break;
        }
        break;
    case typeId:
    {
        output += sprintf(output, "\tpush\t%s\n", varlookup(p));
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
                output += sprintf(output, "\tpop\tac\n");
                for (int i = 0; i < p->opr.op[1]->ari.width; i++)
                {
                    output += sprintf(output, "\tpush\tac\n");
                    output += sprintf(output, "\tpop\t%s[%i]\n", scope == -1 ? "sb" : "fp", base + i);
                }
            }
        }
        break;
        case FOR:
            ex(p->opr.op[0]);
            output += sprintf(output, "L%03d:\n", lblx = lbl++);
            ex(p->opr.op[1]);
            output += sprintf(output, "\tj0\tL%03d\n", lbly = lbl++);
            ex(p->opr.op[3]);
            ex(p->opr.op[2]);
            output += sprintf(output, "\tjmp\tL%03d\n", lblx);
            output += sprintf(output, "L%03d:\n", lbly);
            break;
        case WHILE:
            output += sprintf(output, "L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
            output += sprintf(output, "\tj0\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            output += sprintf(output, "\tjmp\tL%03d\n", lbl1);
            output += sprintf(output, "L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2)
            {
                /* if else */
                output += sprintf(output, "\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                output += sprintf(output, "\tjmp\tL%03d\n", lbl2 = lbl++);
                output += sprintf(output, "L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                output += sprintf(output, "L%03d:\n", lbl2);
            }
            else
            {
                /* if */
                output += sprintf(output, "\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                output += sprintf(output, "L%03d:\n", lbl1);
            }
            break;
        case GETI:
            output += sprintf(output, "\tgeti\n");
            output += sprintf(output, "\tpop\t%s\n", varlookup(p->opr.op[0]));
            break;
        case GETC:
            output += sprintf(output, "\tgetc\n");
            output += sprintf(output, "\tpop\t%s\n", varlookup(p->opr.op[0]));
            break;
        case GETS:
            output += sprintf(output, "\tgets\n");
            output += sprintf(output, "\tpop\t%s\n", varlookup(p->opr.op[0]));
            break;
        case PUTI:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputi\n");
            break;
        case PUTI_:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputi_\n");
            break;
        case PUTC:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputc\n");
            break;
        case PUTC_:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputc_\n");
            break;
        case PUTS:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputs\n");
            break;
        case PUTS_:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tputs_\n");
            break;
        case '=':
            ex(p->opr.op[1]);
            output += sprintf(output, "\tpop\t%s\n", varlookup(p->opr.op[0]));
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            output += sprintf(output, "\tneg\n");
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch (p->opr.oper)
            {
            case '+':
                output += sprintf(output, "\tadd\n");
                break;
            case '-':
                output += sprintf(output, "\tsub\n");
                break;
            case '*':
                output += sprintf(output, "\tmul\n");
                break;
            case '/':
                output += sprintf(output, "\tdiv\n");
                break;
            case '%':
                output += sprintf(output, "\tmod\n");
                break;
            case '<':
                output += sprintf(output, "\tcompLT\n");
                break;
            case '>':
                output += sprintf(output, "\tcompGT\n");
                break;
            case GE:
                output += sprintf(output, "\tcompGE\n");
                break;
            case LE:
                output += sprintf(output, "\tcompLE\n");
                break;
            case NE:
                output += sprintf(output, "\tcompNE\n");
                break;
            case EQ:
                output += sprintf(output, "\tcompEQ\n");
                break;
            case AND:
                output += sprintf(output, "\tand\n");
                break;
            case OR:
                output += sprintf(output, "\tor\n");
                break;
            }
        }
        break;
    case typeFunc:
        lbl1 = lbl++;
        lbl2 = lbl++;
        output += sprintf(output, "\tjmp\tL%03d\n", lbl2);
        output += sprintf(output, "L%03d:\n", lbl1);
        scope = func_symgen(p->func.name, p->func.param);
        // Generate function body in WIP buffer
        ex(p->func.body);
        // TODO: Generate var line

        scope = -1;
        // TODO: Write WIP buffer to output buffer

        output += sprintf(output, "\tret\n");
        output += sprintf(output, "L%03d:\n", lbl2);
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
                output += sprintf(output, "\tpush\t%d\n", var->offset);
                for (int j = 0; j < p->id.op->are.ndim; j++)
                {
                    if (j == 0)
                    {
                        ex(p->id.op->are.op[j]);
                    }
                    else
                    {
                        output += sprintf(output, "\tpush\t%i\n", var->dims[j]);
                        output += sprintf(output, "\tmul\n");
                        ex(p->id.op->are.op[j]);
                        output += sprintf(output, "\tadd\n");
                    }
                }
                output += sprintf(output, "\tadd\n");
                output += sprintf(output, "\tpop\tac\n");
                result->offset = -1; /* offset dynamically calculated */
            }
            else
            {
                result->offset = var->offset; /* offset statically determined */
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
                output += sprintf(output, "\tpush\tfp[%d]\n", i);
                ex(p->id.op->are.op[0]);
                output += sprintf(output, "\tadd\n");
                output += sprintf(output, "\tpop\tac\n");
                result->offset = -1; /* offset dynamically calculated */
                result->reg = "sb";
                return result;
            }
            else if (var->is_array == true)
            { /* auto de-referencing case */
                output += sprintf(output, "\tpush\tfp[%d]\n", i);
                output += sprintf(output, "\tpop\tac\n");
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
                // Need to add offset of arguments to ac
                output += sprintf(output, "\tpush\tac\n");
                output += sprintf(output, "\tpush\t%d\n", funcTable.functions[scope].prmtable.count);
                output += sprintf(output, "\tadd\n");
                output += sprintf(output, "\tpop\tac\n");
                sprintf(r, "%s[%s]", t->reg, "ac"); /* fp[ac] */
            }
            else
            {
                sprintf(r, "%s[%d]", t->reg, t->offset + funcTable.functions[scope].prmtable.count); /* fp[<offset>] */
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
    sprintf(r, "%s[%d]", scope == -1 ? "sb" : "fp", newEntry->offset);
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
