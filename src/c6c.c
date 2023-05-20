#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calc6.h"
#include "y.tab.h"

/* symbol tables */
varSymTable globalVarTable;
funcSymTable funcTable;
char *to_lower(char *str);
int varlookup(nodeType *p);
int arr_symgen(char *var, nodeType *p);
int func_symgen(char *name, nodeType *p);

static int lbl = 0;
static int scope = 0;   /* 0: global scope, <num>: entry index in funcTable */

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
        int offset = varlookup(p);
        if (offset == -1)
            output += sprintf(output, "\tpush\tsb[ac]\n");
        else
            output += sprintf(output, "\tpush\tsb[%d]\n", offset);
        }
        break;
    case typeOpr:
        switch (p->opr.oper)
        {
        int offset;         /* For storing result of varlookup */
        case ARRAY:
            arr_symgen(p->opr.op[0]->id.name, p->opr.op[1]);
            if (p->opr.nops == 3) {
                ex(p->opr.op[2]);                               /* Prepare the expression value */
                output += sprintf(output, "\tpop\tac\n");
                int base = varlookup(p->opr.op[0]);             /* Compute base pointer */
                for (int i = 0; i < p->opr.op[1]->ari.width; i++) {
                    output += sprintf(output, "\tpush\tac\n");
                    output += sprintf(output, "\tpop\tsb[%i]\n", base + i);
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
            offset = varlookup(p->opr.op[0]);
            if (offset == -1)
                output += sprintf(output, "\tpop\tsb[ac]\n");
            else
                output += sprintf(output, "\tpop\tsb[%d]\n", offset);
            break;
        case GETC:
            output += sprintf(output, "\tgetc\n");
            offset = varlookup(p->opr.op[0]);
            if (offset == -1)
                output += sprintf(output, "\tpop\tsb[ac]\n");
            else
                output += sprintf(output, "\tpop\tsb[%d]\n", offset);
            break;
        case GETS:
            output += sprintf(output, "\tgets\n");
            offset = varlookup(p->opr.op[0]);
            if (offset == -1)
                output += sprintf(output, "\tpop\tsb[ac]\n");
            else
                output += sprintf(output, "\tpop\tsb[%d]\n", offset);
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
            offset = varlookup(p->opr.op[0]);
            if (offset == -1)
                output += sprintf(output, "\tpop\tsb[ac]\n");                  /* offset dynamically calculated */
            else
                output += sprintf(output, "\tpop\tsb[%d]\n", offset);          /* offset statically determined */
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
        case typeFunc:
            lbl1 = lbl++;
            lbl2 = lbl++;
            output += sprintf(output, "\tjmp\tL%03d\n", lbl2);
            output += sprintf(output, "L%03d:\n", lbl1);
            scope = func_symgen(p->func.name, p->func.param);
            // TODO: generate code for function body in WIP buffer
            scope = 0;
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

char *to_lower(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        new_str[i] = tolower(str[i]);
    }
    new_str[len] = '\0';
    return new_str;
}

// returns the offset of the variable in the stack,
// or -1 if an array expression is passed into it and
// dynamic computation is required (even if the value
// inside the [] is static). In this case, the result
// is stored in the ac register.
int varlookup(nodeType *p) {
    char *loweredVar = to_lower(p->id.name);
    for (int i = 0; i < globalVarTable.count; i++) {
        varSymEntry var = globalVarTable.variables[i];
        if (strcmp(var.symbol, loweredVar) == 0) {
            if (p->id.has_array_expr) {
                output += sprintf(output, "\tpush\t%d\n", var.offset);
                for (int j = 0; j < p->id.op->are.ndim; j++) {
                    if (j == 0) {
                        ex(p->id.op->are.op[j]);
                    } else {
                        output += sprintf(output, "\tpush\t%i\n", var.dims[j]);
                        output += sprintf(output, "\tmul\n");
                        ex(p->id.op->are.op[j]);
                        output += sprintf(output, "\tadd\n");
                    }
                }
                output += sprintf(output, "\tadd\n");
                output += sprintf(output, "\tpop\tac\n");
                return -1;
            }
            return var.offset;
        }
    }
    // Declare on first use
    globalVarTable.variables[globalVarTable.count].symbol = loweredVar;
    globalVarTable.variables[globalVarTable.count].offset = globalVarTable.width;
    globalVarTable.count++;
    globalVarTable.width++;
    return globalVarTable.width - 1;
}

int arr_symgen(char *var, nodeType *p) {
    char *loweredVar = to_lower(var);
    for (int i = 0; i < globalVarTable.count; i++) {
        if (strcmp(globalVarTable.variables[i].symbol, loweredVar) == 0) {
            output += sprintf(output, "array \"%s\" already declared\n", var);
        }
    }
    varSymEntry *newEntry = &globalVarTable.variables[globalVarTable.count];
    newEntry->ndim = p->ari.ndim;
    memcpy(newEntry->dims, p->ari.dims, sizeof(int) * p->ari.ndim);
    newEntry->symbol = loweredVar;
    newEntry->offset = globalVarTable.width;
    globalVarTable.count++;
    globalVarTable.width += p->ari.width;
    return globalVarTable.width - p->ari.width;
}

// Creates a new function symbol table entry, populates name
// and parameter table, and returns the index of the new entry
int func_symgen(char *name, nodeType *p) {
    char *loweredName = to_lower(name);
    for (int i = 0; i < funcTable.count; i++) {
        if (strcmp(funcTable.functions[i].symbol, loweredName) == 0) {
            output += sprintf(output, "function \"%s\" already declared\n", name);
        }
    }
    funcSymEntry *newEntry = &funcTable.functions[funcTable.count];
    newEntry->symbol = loweredName;
    newEntry->prmtable.count = p->prm.nparams;
    for (int i = 0; i < p->prm.nparams; i++) {
        newEntry->prmtable.parameters[i].symbol = to_lower(p->prm.op[i]->id.name);
        newEntry->prmtable.parameters[i].is_array = p->prm.op[i]->id.has_array_expr;
    }
    funcTable.count++;
    return funcTable.count - 1;
}
