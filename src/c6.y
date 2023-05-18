%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "calc6.h"


/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(char *value);
nodeType *conInt(int value);
nodeType *conChar(char value);
nodeType *conString(char *value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
void yyerror(char *s);
char *to_lower(char *str);
int get_symtable_ind(char *var);
%}

%union {
    int iValue;                 /* integer value */
    char cValue;                /* character value */
    char *sValue;               /* string value */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTEGER
%token <cValue> CHARACTER
%token <sValue> STRING
%token <sValue> VARIABLE
%token FOR WHILE IF GETI GETC GETS PUTI PUTI_ PUTC PUTC_ PUTS PUTS_
%token ARRAY
%nonassoc IFX
%nonassoc ELSE

%left AND OR

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                                       { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                  { $$ = $1; }
	    | GETI '(' VARIABLE ')' ';'		            { $$ = opr(GETI, 1, id($3)); }
        | GETC '(' VARIABLE ')' ';'		            { $$ = opr(GETC, 1, id($3)); }
        | GETS '(' VARIABLE ')' ';'		            { $$ = opr(GETS, 1, id($3)); }
        | PUTI '(' expr ')' ';'		                { $$ = opr(PUTI, 1, $3); }
        | PUTI_ '(' expr ')' ';'		            { $$ = opr(PUTI_, 1, $3); }
        | PUTC '(' expr ')' ';'		                { $$ = opr(PUTC, 1, $3); }
        | PUTC_ '(' expr ')' ';'		            { $$ = opr(PUTC_, 1, $3); }
        | PUTS '(' expr ')' ';'		                { $$ = opr(PUTS, 1, $3); }
        | PUTS_ '(' expr ')' ';'		            { $$ = opr(PUTS_, 1, $3); }
        | VARIABLE '=' expr ';'                     { $$ = opr('=', 2, id($1), $3); }
        /* | ARRAY VARIABLE '[' INTEGER ']' ';'        { $$ = opr(ARRAY, 0); } */
	    | FOR '(' stmt stmt stmt ')' stmt           { $$ = opr(FOR, 4, $3, $4, $5, $7); }
        | WHILE '(' expr ')' stmt                   { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX            { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt            { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                         { $$ = $2; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER               { $$ = conInt($1); }
        | CHARACTER             { $$ = conChar($1); }
        | STRING                { $$ = conString($1); }
        | VARIABLE              { $$ = id($1); }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '%' expr         { $$ = opr('%', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
        | expr AND expr		    { $$ = opr(AND, 2, $1, $3); }
        | expr OR expr		    { $$ = opr(OR, 2, $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        ;

%%

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *conInt(int value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.conType = conTypeInt;
    p->con.intValue = value;

    return p;
}

nodeType *conChar(char value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.conType = conTypeChar;
    p->con.charValue = value;

    return p;
}

nodeType *conString(char *value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.conType = conTypeString;
    p->con.strValue = value;

    return p;
}

nodeType *id(char *value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = get_symtable_ind(value);

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
        (nops - 1) * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
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

int get_symtable_ind(char *var) {
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

int main(int argc, char **argv) {
extern FILE* yyin;
    yyin = fopen(argv[1], "r");

    // Global variable table initialisation
    globalVarTable.count = 0;
    globalVarTable.width = 0;

    // Function table initialisation
    funcTable.count = 0;

    // Stack pointer initialisation hack
    printf("\tpush\tsp\n");
    printf("\tpush\t10000\n");
    printf("\tadd\n");
    printf("\tpop\tsp\n");

    yyparse();
    return 0;
}
