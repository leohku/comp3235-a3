#include <stdbool.h>

typedef enum { typeCon, typeId, typeOpr, typeAri, typeAre, typePrm, typeFunc } nodeEnum;
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

/* parameter symtable */
typedef struct {
    char *symbol;
    bool is_array;
} prmSymEntry;

typedef struct {
    int count;                  /* number of parameters */
    prmSymEntry parameters[10]; /* array of parameters, max 10 */
} prmSymTable;

/* function symtable */
typedef struct {
    char *symbol;
    prmSymTable prmtable;
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
    bool has_global_decor;          /* has global '@' decoration */
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

typedef struct {
    int nparams;
    struct nodeTypeTag *op[10];
} prmNodeType;                  /* function definition parameter list */

typedef struct {
    char *name;
    struct nodeTypeTag *param;
    struct nodeTypeTag *body;
} funcNodeType;                 /* function definition */

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
        prmNodeType prm;        /* function definition parameter list */
        funcNodeType func;      /* function definition */
    };
} nodeType;

/* return type for table search */
typedef struct {
    bool found;
    char *reg;
    int offset;                 /* -1: in ac, else statically determined */
} tableSearchResult;

extern char *head;
extern char *output_start;
extern char *output_saved;
extern char *wip;
extern varSymTable globalVarTable;
extern funcSymTable funcTable;
