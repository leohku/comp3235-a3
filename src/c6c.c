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

static int lbl;

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
            printf("\tpush\t%d\n", p->con.intValue);
            break;
        case conTypeChar:
            printf("\tpush\t'%c'\n", p->con.charValue);
            break;
        case conTypeString:
            printf("\tpush\t\"%s\"\n", p->con.strValue);
            break;
        }
        break;
    case typeId:
        {
        int offset = varlookup(p);
        if (offset == -1)
            printf("\tpush\tsb[ac]\n");
        else
            printf("\tpush\tsb[%d]\n", offset);
        }
        break;
    case typeOpr:
        switch (p->opr.oper)
        {
        case ARRAY:
            arr_symgen(p->opr.op[0]->id.name, p->opr.op[1]);
            if (p->opr.nops == 3) {
                ex(p->opr.op[2]);                               /* Prepare the expression value */
                printf("\tpop\tac\n");
                int base = varlookup(p->opr.op[0]);             /* Compute base pointer */
                for (int i = 0; i < p->opr.op[1]->ari.width; i++) {
                    printf("\tpush\tac\n");
                    printf("\tpop\tsb[%i]\n", base + i);
                }
            }
            break;
        case FOR:
            ex(p->opr.op[0]);
            printf("L%03d:\n", lblx = lbl++);
            ex(p->opr.op[1]);
            printf("\tj0\tL%03d\n", lbly = lbl++);
            ex(p->opr.op[3]);
            ex(p->opr.op[2]);
            printf("\tjmp\tL%03d\n", lblx);
            printf("L%03d:\n", lbly);
            break;
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
            printf("\tj0\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2)
            {
                /* if else */
                printf("\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            }
            else
            {
                /* if */
                printf("\tj0\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("L%03d:\n", lbl1);
            }
            break;
        case GETI:
            printf("\tgeti\n");
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]));
            break;
        case GETC:
            printf("\tgetc\n");
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]));
            break;
        case GETS:
            printf("\tgets\n");
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]));
            break;
        case PUTI:
            ex(p->opr.op[0]);
            printf("\tputi\n");
            break;
        case PUTI_:
            ex(p->opr.op[0]);
            printf("\tputi_\n");
            break;
        case PUTC:
            ex(p->opr.op[0]);
            printf("\tputc\n");
            break;
        case PUTC_:
            ex(p->opr.op[0]);
            printf("\tputc_\n");
            break;
        case PUTS:
            ex(p->opr.op[0]);
            printf("\tputs\n");
            break;
        case PUTS_:
            ex(p->opr.op[0]);
            printf("\tputs_\n");
            break;
        case '=':
            ex(p->opr.op[1]);
            int offset = varlookup(p->opr.op[0]);
            if (offset == -1)
                printf("\tpop\tsb[ac]\n");                  /* offset dynamically calculated */
            else
                printf("\tpop\tsb[%d]\n", offset);          /* offset statically determined */
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            printf("\tneg\n");
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch (p->opr.oper)
            {
            case '+':
                printf("\tadd\n");
                break;
            case '-':
                printf("\tsub\n");
                break;
            case '*':
                printf("\tmul\n");
                break;
            case '/':
                printf("\tdiv\n");
                break;
            case '%':
                printf("\tmod\n");
                break;
            case '<':
                printf("\tcompLT\n");
                break;
            case '>':
                printf("\tcompGT\n");
                break;
            case GE:
                printf("\tcompGE\n");
                break;
            case LE:
                printf("\tcompLE\n");
                break;
            case NE:
                printf("\tcompNE\n");
                break;
            case EQ:
                printf("\tcompEQ\n");
                break;
            case AND:
                printf("\tand\n");
                break;
            case OR:
                printf("\tor\n");
                break;
            }
        }
        case typeAri:
        case typeAre:
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
// dynamic computation is required. In this case, the
// result is stored in the ac register.
int varlookup(nodeType *p) {
    char *loweredVar = to_lower(p->id.name);
    for (int i = 0; i < globalVarTable.count; i++) {
        varSymEntry var = globalVarTable.variables[i];
        if (strcmp(var.symbol, loweredVar) == 0) {
            if (p->id.has_array_expr) {
                printf("\tpush\t%d\n", var.offset);
                for (int j = 0; j < p->id.op->are.ndim; j++) {
                    if (j == 0) {
                        ex(p->id.op->are.op[j]);
                    } else {
                        printf("\tpush\t%i\n", var.dims[j]);
                        printf("\tmul\n");
                        ex(p->id.op->are.op[j]);
                        printf("\tadd\n");
                    }
                }
                printf("\tadd\n");
                printf("\tpop\tac\n");
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
            printf("Error: array \"%s\" already declared\n", var);
            exit(1);
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
