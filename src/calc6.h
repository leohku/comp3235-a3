typedef enum { typeCon, typeId, typeOpr } nodeEnum;
typedef enum { conTypeInt, conTypeChar, conTypeString } conTypeEnum;

/* variable symtable */
typedef struct {
    char* symbol;
    int ndim;
    int offset;
    int* dims;
} varSymEntry;

typedef struct {
    int width;                  /* width of variables */
    int count;                  /* number of variables */
    varSymEntry variables[100]; /* array of variables, max 100 */
} varSymTable;

/* function symtable */
typedef struct {
    char* symbol;
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
    int i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;

extern char* remove_first_last_char(char* str);
extern char* to_lower(char* str);
extern int get_symtable_ind(char* str);

extern varSymTable globalVarTable;
extern varSymTable localVarTable;
extern funcSymTable funcTable;
