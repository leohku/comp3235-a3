#include <stdbool.h>

typedef enum { typeCon, typeId, typeOpr, typeAri, typeAre } nodeEnum;
typedef enum { conTypeInt, conTypeChar, conTypeString } conTypeEnum;

/* variable symtable */
typedef struct {
    char *symbol;
    int ndim;                   /* 0 if variable, 1 or higher if array */
    int offset;
    int dims[10];
} varSymEntry;

typedef struct {
    int width;                  /* width of variables */
    int count;                  /* number of variables */
    varSymEntry variables[100]; /* array of variables, max 100 */
} varSymTable;

/* function symtable */
typedef struct {
    char *symbol;
    varSymTable argtable;
    varSymTable vartable;
} funcSymEntry;

typedef struct {
    int count;                      /* number of functions */
    funcSymEntry functions[100];    /* array of functions, max 100 */
} funcSymTable;

/* constants */
typedef struct {
    conTypeEnum conType;
    int intValue;                  /* value of constant */
    char charValue;
    char *strValue;
} conNodeType;

/* identifiers */
typedef struct {
    char *name;                     /* variable name */
    bool has_array_expr;            /* has array expression */
    struct nodeTypeTag *op;         /* array expressions */
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

typedef struct {
    int ndim;
    int width;
    int dims[10];
} ariNodeType;                  /* array initializer integer list */

typedef struct {
    int ndim;
    struct nodeTypeTag *op[10];
} areNodeType;                  /* array invokation expression list */

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
        ariNodeType ari;        /* array initializer */
        areNodeType are;        /* array invokation */
    };
} nodeType;

extern char *output;
extern char *wip;
extern char *wip_start;
extern varSymTable globalVarTable;
extern varSymTable localVarTable;
extern funcSymTable funcTable;
