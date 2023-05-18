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
int varlookup(char *var);
int arr_symgen(char *var, int size);

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
        printf("\tpush\tsb[%d]\n", varlookup(p->id.name));
        break;
    case typeOpr:
        switch (p->opr.oper)
        {
        case ARRAY:
            arr_symgen(p->opr.op[0]->id.name, p->opr.op[1]->con.intValue);
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
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]->id.name));
            break;
        case GETC:
            printf("\tgetc\n");
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]->id.name));
            break;
        case GETS:
            printf("\tgets\n");
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]->id.name));
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
            printf("\tpop\tsb[%d]\n", varlookup(p->opr.op[0]->id.name));
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

int varlookup(char *var) {
    char *loweredVar = to_lower(var);
    for (int i = 0; i < globalVarTable.count; i++) {
        if (strcmp(globalVarTable.variables[i].symbol, loweredVar) == 0) {
            return i;
        }
    }
    globalVarTable.variables[globalVarTable.count].symbol = loweredVar;
    globalVarTable.variables[globalVarTable.count].offset = globalVarTable.width;
    globalVarTable.count++;
    globalVarTable.width++;
    return globalVarTable.width - 1;
}

int arr_symgen(char *var, int size) {
    char *loweredVar = to_lower(var);
    for (int i = 0; i < globalVarTable.count; i++) {
        if (strcmp(globalVarTable.variables[i].symbol, loweredVar) == 0) {
            printf("Error: array \"%s\" already declared\n", var);
            exit(1);
        }
    }
    // TODO: ndim and dims when we support multidimensional arrays
    globalVarTable.variables[globalVarTable.count].symbol = loweredVar;
    globalVarTable.variables[globalVarTable.count].offset = globalVarTable.width;
    globalVarTable.count++;
    globalVarTable.width += size;
    return globalVarTable.width - size;
}
