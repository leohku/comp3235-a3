%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "calc6.h"

/* prototypes */
nodeType *ari(nodeType *prev, int value);
nodeType *are(nodeType *prev, nodeType *exp);
nodeType *prm(nodeType *prev, nodeType *param);
nodeType *func(char *name, nodeType *param, nodeType *body);
nodeType *opr(int oper, int nops, ...);
nodeType *id(bool global, char *value);
nodeType *ida(bool global, char *value, nodeType *op);
nodeType *conInt(int value);
nodeType *conChar(char value);
nodeType *conString(char *value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
void yyerror(char *s);

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
%token ARRAY FUNC RETURN CALL
%nonassoc IFX
%nonassoc ELSE

%left AND OR

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%type <nPtr> stmt stmt_list expr array_decl func_decl int_list expr_list expr_list_opt
%type <nPtr> prm_list var_invk func_call array_decl_list array_decl_item

%%

program:
        function
        ;

function:
          function stmt                                 { ex($2); freeNode($2); }
        | function func_decl                            { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                                               { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                          { $$ = $1; }
        | array_decl ';'                                    { $$ = $1; }
	    | GETI '(' var_invk ')' ';'		                    { $$ = opr(GETI, 1, $3); }
        | GETC '(' var_invk ')' ';'		                    { $$ = opr(GETC, 1, $3); }
        | GETS '(' var_invk ')' ';'		                    { $$ = opr(GETS, 1, $3); }
        | PUTI '(' expr ')' ';'		                        { $$ = opr(PUTI, 1, $3); }
        | PUTI_ '(' expr ')' ';'		                    { $$ = opr(PUTI_, 1, $3); }
        | PUTC '(' expr ')' ';'		                        { $$ = opr(PUTC, 1, $3); }
        | PUTC_ '(' expr ')' ';'		                    { $$ = opr(PUTC_, 1, $3); }
        | PUTS '(' expr ')' ';'		                        { $$ = opr(PUTS, 1, $3); }
        | PUTS_ '(' expr ')' ';'		                    { $$ = opr(PUTS_, 1, $3); }
        | var_invk '=' expr ';'                             { $$ = opr('=', 2, $1, $3); }
	    | FOR '(' stmt stmt stmt ')' stmt                   { $$ = opr(FOR, 4, $3, $4, $5, $7); }
        | WHILE '(' expr ')' stmt                           { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX                    { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                    { $$ = opr(IF, 3, $3, $5, $7); }
        | RETURN ';'                                        { $$ = opr(RETURN, 1, NULL); }
        | RETURN expr ';'                                   { $$ = opr(RETURN, 1, $2); }
        | '{' stmt_list '}'                                 { $$ = $2; }
        ;

stmt_list:
          stmt                                          { $$ = $1; }
        | stmt_list stmt                                { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER                                       { $$ = conInt($1); }
        | CHARACTER                                     { $$ = conChar($1); }
        | STRING                                        { $$ = conString($1); }
        | var_invk                                      { $$ = $1; }
        | func_call                                     { $$ = $1; }
        | '-' expr %prec UMINUS                         { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr                                 { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr                                 { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr                                 { $$ = opr('*', 2, $1, $3); }
        | expr '%' expr                                 { $$ = opr('%', 2, $1, $3); }
        | expr '/' expr                                 { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr                                 { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr                                 { $$ = opr('>', 2, $1, $3); }
        | expr GE expr                                  { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr                                  { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr                                  { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr                                  { $$ = opr(EQ, 2, $1, $3); }
        | expr AND expr		                            { $$ = opr(AND, 2, $1, $3); }
        | expr OR expr		                            { $$ = opr(OR, 2, $1, $3); }
        | '(' expr ')'                                  { $$ = $2; }
        ;

array_decl: ARRAY array_decl_list                       { $$ = $2; }
        ;

array_decl_list: array_decl_item                        { $$ = $1; }
        | array_decl_list ',' array_decl_item           { $$ = opr(';', 2, $1, $3); }
        ;

array_decl_item: VARIABLE '[' int_list ']'              { $$ = opr(ARRAY, 2, id(false, $1), $3); }
        | VARIABLE '[' int_list ']' '=' expr            { $$ = opr(ARRAY, 3, id(false, $1), $3, $6); }
        ;

func_decl: FUNC VARIABLE '(' prm_list ')' '{' stmt_list '}' { $$ = func($2, $4, $7); }
        ;

int_list: INTEGER                                       { $$ = ari(NULL, $1); }
        | int_list ',' INTEGER                          { $$ = ari($1, $3); }
        ;

expr_list_opt: /* NULL */                               { $$ = are(NULL, NULL); }
        | expr_list                                     { $$ = $1; }
        ;

expr_list: expr                                         { $$ = are(NULL, $1); }
        | expr_list ',' expr                            { $$ = are($1, $3); }
        ;

prm_list: /* NULL */                                    { $$ = prm(NULL, NULL); }
        | VARIABLE                                      { $$ = prm(NULL, id(false, $1)); }
        | VARIABLE '[' ']'                              { $$ = prm(NULL, ida(false, $1, NULL)); }
        | prm_list ',' VARIABLE                         { $$ = prm($1, id(false, $3)); }
        | prm_list ',' VARIABLE '[' ']'                 { $$ = prm($1, ida(false, $3, NULL)); }
        ;

var_invk: VARIABLE                                      { $$ = id(false, $1); }
        | VARIABLE '[' expr_list ']'                    { $$ = ida(false, $1, $3); }
        | '@' VARIABLE                                  { $$ = id(true, $2); }
        | '@' VARIABLE '[' expr_list ']'                { $$ = ida(true, $2, $4); }

func_call: VARIABLE '(' expr_list_opt ')'               { $$ = opr(CALL, 2, id(false, $1), $3); }
        | '@' VARIABLE '(' expr_list_opt ')'            { $$ = opr(CALL, 2, id(false, $2), $4); }
        ;

%%

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *ari(nodeType *prev, int value) {
    if (value <= 0)
    {
        fprintf(stderr, "illegal array dimension value\n");
        exit(1);
    }

    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(ariNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeAri;
    if (prev == NULL) {
        p->ari.ndim = 1;
        p->ari.width = value;
        p->ari.dims[0] = value;
    } else {
        p->ari.ndim = prev->ari.ndim + 1;
        p->ari.width = value * prev->ari.width;
        p->ari.dims[p->ari.ndim - 1] = value;
        memcpy(p->ari.dims, prev->ari.dims, sizeof(int) * prev->ari.ndim);
    }

    return p;
}

nodeType *are(nodeType *prev, nodeType *exp) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(areNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeAre;
    if (exp == NULL) {
        p->are.ndim = 0;
    } else {
        if (prev == NULL) {
            p->are.ndim = 1;
            p->are.op[0] = exp;
        } else {
            p->are.ndim = prev->are.ndim + 1;
            memcpy(p->are.op, prev->are.op, sizeof(nodeType *) * prev->are.ndim);
            p->are.op[p->are.ndim - 1] = exp;
        }
    }

    return p;
}

nodeType *prm(nodeType *prev, nodeType *param) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(prmNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typePrm;
    if (param == NULL) {
        p->prm.nparams = 0;
    } else {
        if (prev == NULL) {
            p->prm.nparams = 1;
            p->prm.op[0] = param;
        } else {
            p->prm.nparams = prev->prm.nparams + 1;
            memcpy(p->prm.op, prev->prm.op, sizeof(nodeType *) * prev->prm.nparams);
            p->prm.op[p->prm.nparams - 1] = param;
        }
    }

    return p;
}

nodeType *func(char *name, nodeType *param, nodeType *body) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(funcNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeFunc;
    p->func.name = name;
    p->func.param = param;
    p->func.body = body;

    return p;
}

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

nodeType *id(bool global, char *value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.name = value;
    p->id.has_array_expr = false;
    p->id.has_global_decor = global;    /* global: has global '@' decoration */

    return p;
}

nodeType *ida(bool global, char *value, nodeType *op) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.name = value;
    p->id.has_array_expr = true;
    p->id.has_global_decor = global;    /* global: has global '@' decoration */
    p->id.op = op;

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
    printf("yyparse output in progress:\n");
    printf("%s", output_start); /* print output before quitting */
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main(int argc, char **argv) {
extern FILE* yyin;
    yyin = fopen(argv[1], "r");

    // Global variable table initialisation
    globalVarTable.count = 0;
    globalVarTable.width = 0;

    // Function table initialisation
    funcTable.count = 0;

    // Prepare output buffers and pointers
    output_start = malloc(sizeof(char) * 1000000);
    wip = malloc(sizeof(char) * 1000000);
    head = output_start;

    yyparse();

    // Initialise global stack frame
    printf("\tpush\tsp\n");
    printf("\tpush\t%d\n", globalVarTable.width);
    printf("\tadd\n");
    printf("\tpop\tsp\n");

    // Initialise runtime safety stack pointer
    printf("\tpush\t%d\n", STACK_CEIL - 1);
    printf("\tpop\tsb[%d]\n", STACK_CEIL);

    // Print the output
    printf("%s", output_start);

    // Print runtime error labels
    printf("\tjmp\tL999\n");
    printf("L990:\n");
    printf("\tputs\t\"Runtime Error: Division by zero.\\n\"\n");
    printf("\tjmp\tL999\n");
    printf("L991:\n");
    printf("\tputs\t\"Runtime Error: Array index out of bounds.\\n\"\n");
    printf("\tjmp\tL999\n");
    printf("L992:\n");
    printf("\tputs\t\"Runtime Error: Negative array index.\\n\"\n");
    printf("\tjmp\tL999\n");
    printf("L993:\n");
    printf("\tputs\t\"Runtime Error: Array dimension mismatch.\\n\"\n");
    printf("L999:\n");

    return 0;
}
