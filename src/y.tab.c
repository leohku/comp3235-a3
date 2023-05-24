/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c6.y"

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


#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    CHARACTER = 259,               /* CHARACTER  */
    STRING = 260,                  /* STRING  */
    VARIABLE = 261,                /* VARIABLE  */
    FOR = 262,                     /* FOR  */
    WHILE = 263,                   /* WHILE  */
    IF = 264,                      /* IF  */
    GETI = 265,                    /* GETI  */
    GETC = 266,                    /* GETC  */
    GETS = 267,                    /* GETS  */
    PUTI = 268,                    /* PUTI  */
    PUTI_ = 269,                   /* PUTI_  */
    PUTC = 270,                    /* PUTC  */
    PUTC_ = 271,                   /* PUTC_  */
    PUTS = 272,                    /* PUTS  */
    PUTS_ = 273,                   /* PUTS_  */
    ARRAY = 274,                   /* ARRAY  */
    FUNC = 275,                    /* FUNC  */
    RETURN = 276,                  /* RETURN  */
    CALL = 277,                    /* CALL  */
    IFX = 278,                     /* IFX  */
    ELSE = 279,                    /* ELSE  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    GE = 282,                      /* GE  */
    LE = 283,                      /* LE  */
    EQ = 284,                      /* EQ  */
    NE = 285,                      /* NE  */
    UMINUS = 286                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define CHARACTER 259
#define STRING 260
#define VARIABLE 261
#define FOR 262
#define WHILE 263
#define IF 264
#define GETI 265
#define GETC 266
#define GETS 267
#define PUTI 268
#define PUTI_ 269
#define PUTC 270
#define PUTC_ 271
#define PUTS 272
#define PUTS_ 273
#define ARRAY 274
#define FUNC 275
#define RETURN 276
#define CALL 277
#define IFX 278
#define ELSE 279
#define AND 280
#define OR 281
#define GE 282
#define LE 283
#define EQ 284
#define NE 285
#define UMINUS 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "c6.y"

    int iValue;                 /* integer value */
    char cValue;                /* character value */
    char *sValue;               /* string value */
    nodeType *nPtr;             /* node pointer */

#line 218 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_VARIABLE = 6,                   /* VARIABLE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_GETI = 10,                      /* GETI  */
  YYSYMBOL_GETC = 11,                      /* GETC  */
  YYSYMBOL_GETS = 12,                      /* GETS  */
  YYSYMBOL_PUTI = 13,                      /* PUTI  */
  YYSYMBOL_PUTI_ = 14,                     /* PUTI_  */
  YYSYMBOL_PUTC = 15,                      /* PUTC  */
  YYSYMBOL_PUTC_ = 16,                     /* PUTC_  */
  YYSYMBOL_PUTS = 17,                      /* PUTS  */
  YYSYMBOL_PUTS_ = 18,                     /* PUTS_  */
  YYSYMBOL_ARRAY = 19,                     /* ARRAY  */
  YYSYMBOL_FUNC = 20,                      /* FUNC  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_CALL = 22,                      /* CALL  */
  YYSYMBOL_IFX = 23,                       /* IFX  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '@'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_stmt_list = 53,                 /* stmt_list  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_array_decl = 55,                /* array_decl  */
  YYSYMBOL_array_decl_list = 56,           /* array_decl_list  */
  YYSYMBOL_array_decl_item = 57,           /* array_decl_item  */
  YYSYMBOL_func_decl = 58,                 /* func_decl  */
  YYSYMBOL_int_list = 59,                  /* int_list  */
  YYSYMBOL_expr_list_opt = 60,             /* expr_list_opt  */
  YYSYMBOL_expr_list = 61,                 /* expr_list  */
  YYSYMBOL_prm_list = 62,                  /* prm_list  */
  YYSYMBOL_var_invk = 63,                  /* var_invk  */
  YYSYMBOL_func_call = 64                  /* func_call  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      40,    41,    35,    33,    45,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      32,    42,    31,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    59,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    88,    89,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   115,   118,
     119,   122,   123,   126,   129,   130,   133,   134,   137,   138,
     141,   142,   143,   144,   145,   148,   149,   150,   151,   153,
     154
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "CHARACTER",
  "STRING", "VARIABLE", "FOR", "WHILE", "IF", "GETI", "GETC", "GETS",
  "PUTI", "PUTI_", "PUTC", "PUTC_", "PUTS", "PUTS_", "ARRAY", "FUNC",
  "RETURN", "CALL", "IFX", "ELSE", "AND", "OR", "GE", "LE", "EQ", "NE",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'", "'('",
  "')'", "'='", "'{'", "'}'", "','", "'['", "']'", "'@'", "$accept",
  "program", "function", "stmt", "stmt_list", "expr", "array_decl",
  "array_decl_list", "array_decl_item", "func_decl", "int_list",
  "expr_list_opt", "expr_list", "prm_list", "var_invk", "func_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -39,     5,   188,   -39,   -39,   -39,   -39,   -38,   -36,   -14,
      -8,    -7,    -4,     2,    10,    12,    13,    14,    17,    18,
      29,    38,     7,    99,   -39,    99,   326,    39,   -39,   503,
      20,   -39,    23,   -39,    99,    99,   326,    99,    99,    -5,
      -5,    -5,    99,    99,    99,    99,    99,    99,    21,    30,
     -39,    36,   -39,   518,   -39,   -39,   350,   -39,   234,   -37,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   -39,   -39,    99,   151,    25,    32,   -20,
     326,   367,   384,    33,    74,    40,    41,    42,   401,   418,
     435,   452,   469,   486,    82,    29,    93,   -39,   -39,   -39,
     -39,    99,    99,    79,    79,   -19,   -19,   -19,   -19,   -19,
     -19,   -15,   -15,   -39,   -39,   -39,   533,   -39,    99,   -39,
     326,   326,   326,    54,    78,    83,    84,    90,    91,    92,
      95,    96,    97,   -39,   -17,   -39,    75,   -22,   100,   -16,
     -39,   151,   101,   -39,   108,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   134,    98,   102,   103,   132,   -39,
     -39,   326,   326,   -39,    99,   -39,   326,   104,   -39,   -39,
     151,   280,   105,   -39,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,    28,    29,    30,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     3,     0,
       0,     4,    31,    32,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,    23,     0,    31,    33,     0,    26,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,    58,     0,    57,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    24,    47,    25,
      27,    56,     0,    45,    46,    41,    42,    44,    43,    40,
      39,    34,    35,    36,    38,    37,     0,    69,     0,    66,
       0,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,    50,    61,     0,     0,     0,
      18,    59,     0,    20,    21,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    51,     0,     0,     0,    70,
      68,     0,     0,    55,     0,    62,     0,    63,    19,    22,
      52,     0,     0,    53,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,     4,   -23,    26,   -39,   -39,    50,   -39,
     -39,    47,   -28,   -39,    -2,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    57,    58,    29,    30,    49,    50,    31,
     134,    77,    78,   137,    54,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    83,    34,   101,    36,     3,    28,    79,    35,   102,
       4,     5,     6,     7,    68,    69,    70,    71,    72,   157,
      70,    71,    72,   158,    32,   118,    37,   119,   154,   118,
     155,   160,    38,    39,    32,    48,    40,    85,    86,    87,
      80,    23,    41,    84,    51,    59,    52,    25,    53,    55,
      42,    56,    43,    44,    45,    27,    32,    46,    47,    74,
      76,    76,   100,    81,    82,    75,   117,    94,    88,    89,
      90,    91,    92,    93,   139,    95,    96,   118,    32,    35,
     123,   124,   125,   126,   120,   133,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   136,
     102,   116,     4,     5,     6,     7,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   145,    32,    32,
      32,   156,   146,   147,   142,   143,   144,    76,    76,   148,
     149,   150,   162,    23,   151,   152,   153,   163,   167,    25,
     164,   159,   161,   171,   141,   135,   166,    27,   138,   165,
     172,     0,   174,     0,     0,     0,     0,     0,     0,    32,
      32,     0,     0,     0,    32,   168,   169,     0,     0,    32,
       0,     0,     0,     0,     0,   100,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
     170,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,    24,    25,     0,
       0,    26,     0,     0,     0,     0,    27,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,    24,    25,     0,     0,    26,    99,     0,
       0,     0,    27,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,    24,
      25,     0,     0,    26,   173,     0,     0,     0,    27,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,    24,    25,     0,     0,    26,
       0,     0,     0,     0,    27,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
       0,    98,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,   121,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,     0,   122,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,     0,   127,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,     0,   128,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,     0,   129,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,   130,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,     0,
     131,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,     0,   132,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,    97,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,   140
};

static const yytype_int16 yycheck[] =
{
       2,     6,    40,    40,    40,     0,     2,    35,    46,    46,
       3,     4,     5,     6,    33,    34,    35,    36,    37,    41,
      35,    36,    37,    45,    26,    45,    40,    47,    45,    45,
      47,    47,    40,    40,    36,     6,    40,    39,    40,    41,
      36,    34,    40,    48,     6,     6,    39,    40,    22,    23,
      40,    25,    40,    40,    40,    48,    58,    40,    40,    39,
      34,    35,    58,    37,    38,    42,    41,    46,    42,    43,
      44,    45,    46,    47,   102,    45,    40,    45,    80,    46,
       6,    41,    41,    41,    80,     3,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     6,
      46,    75,     3,     4,     5,     6,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    39,   120,   121,
     122,    46,    39,    39,   120,   121,   122,   101,   102,    39,
      39,    39,    24,    34,    39,    39,    39,     3,     6,    40,
      42,    41,    41,   166,   118,    95,    43,    48,   101,    47,
      46,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   161,   162,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   171,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
     164,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    41,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    41,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    34,    39,    40,    43,    48,    52,    54,
      55,    58,    63,    64,    40,    46,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,     6,    56,
      57,     6,    39,    54,    63,    54,    54,    52,    53,     6,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    39,    39,    42,    54,    60,    61,    61,
      52,    54,    54,     6,    48,    63,    63,    63,    54,    54,
      54,    54,    54,    54,    46,    45,    40,    39,    41,    44,
      52,    40,    46,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    41,    45,    47,
      52,    41,    41,     6,    41,    41,    41,    41,    41,    41,
      41,    41,    41,     3,    59,    57,     6,    62,    60,    61,
      39,    54,    52,    52,    52,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    45,    47,    46,    41,    45,    41,
      47,    41,    24,     3,    42,    47,    43,     6,    52,    52,
      54,    53,    46,    44,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     2,     2,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     7,
       5,     5,     7,     2,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       3,     4,     6,     8,     1,     3,     0,     1,     1,     3,
       0,     1,     3,     3,     5,     1,     4,     2,     5,     4,
       5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* function: function stmt  */
#line 59 "c6.y"
                                                        { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1445 "y.tab.c"
    break;

  case 4: /* function: function func_decl  */
#line 60 "c6.y"
                                                        { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1451 "y.tab.c"
    break;

  case 6: /* stmt: ';'  */
#line 65 "c6.y"
                                                            { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1457 "y.tab.c"
    break;

  case 7: /* stmt: expr ';'  */
#line 66 "c6.y"
                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1463 "y.tab.c"
    break;

  case 8: /* stmt: array_decl ';'  */
#line 67 "c6.y"
                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1469 "y.tab.c"
    break;

  case 9: /* stmt: GETI '(' var_invk ')' ';'  */
#line 68 "c6.y"
                                                                    { (yyval.nPtr) = opr(GETI, 1, (yyvsp[-2].nPtr)); }
#line 1475 "y.tab.c"
    break;

  case 10: /* stmt: GETC '(' var_invk ')' ';'  */
#line 69 "c6.y"
                                                                    { (yyval.nPtr) = opr(GETC, 1, (yyvsp[-2].nPtr)); }
#line 1481 "y.tab.c"
    break;

  case 11: /* stmt: GETS '(' var_invk ')' ';'  */
#line 70 "c6.y"
                                                                    { (yyval.nPtr) = opr(GETS, 1, (yyvsp[-2].nPtr)); }
#line 1487 "y.tab.c"
    break;

  case 12: /* stmt: PUTI '(' expr ')' ';'  */
#line 71 "c6.y"
                                                                { (yyval.nPtr) = opr(PUTI, 1, (yyvsp[-2].nPtr)); }
#line 1493 "y.tab.c"
    break;

  case 13: /* stmt: PUTI_ '(' expr ')' ';'  */
#line 72 "c6.y"
                                                                    { (yyval.nPtr) = opr(PUTI_, 1, (yyvsp[-2].nPtr)); }
#line 1499 "y.tab.c"
    break;

  case 14: /* stmt: PUTC '(' expr ')' ';'  */
#line 73 "c6.y"
                                                                { (yyval.nPtr) = opr(PUTC, 1, (yyvsp[-2].nPtr)); }
#line 1505 "y.tab.c"
    break;

  case 15: /* stmt: PUTC_ '(' expr ')' ';'  */
#line 74 "c6.y"
                                                                    { (yyval.nPtr) = opr(PUTC_, 1, (yyvsp[-2].nPtr)); }
#line 1511 "y.tab.c"
    break;

  case 16: /* stmt: PUTS '(' expr ')' ';'  */
#line 75 "c6.y"
                                                                { (yyval.nPtr) = opr(PUTS, 1, (yyvsp[-2].nPtr)); }
#line 1517 "y.tab.c"
    break;

  case 17: /* stmt: PUTS_ '(' expr ')' ';'  */
#line 76 "c6.y"
                                                                    { (yyval.nPtr) = opr(PUTS_, 1, (yyvsp[-2].nPtr)); }
#line 1523 "y.tab.c"
    break;

  case 18: /* stmt: var_invk '=' expr ';'  */
#line 77 "c6.y"
                                                            { (yyval.nPtr) = opr('=', 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1529 "y.tab.c"
    break;

  case 19: /* stmt: FOR '(' stmt stmt stmt ')' stmt  */
#line 78 "c6.y"
                                                                { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-4].nPtr), (yyvsp[-3].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1535 "y.tab.c"
    break;

  case 20: /* stmt: WHILE '(' expr ')' stmt  */
#line 79 "c6.y"
                                                            { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1541 "y.tab.c"
    break;

  case 21: /* stmt: IF '(' expr ')' stmt  */
#line 80 "c6.y"
                                                            { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1547 "y.tab.c"
    break;

  case 22: /* stmt: IF '(' expr ')' stmt ELSE stmt  */
#line 81 "c6.y"
                                                            { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1553 "y.tab.c"
    break;

  case 23: /* stmt: RETURN ';'  */
#line 82 "c6.y"
                                                            { (yyval.nPtr) = opr(RETURN, 1, NULL); }
#line 1559 "y.tab.c"
    break;

  case 24: /* stmt: RETURN expr ';'  */
#line 83 "c6.y"
                                                            { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 1565 "y.tab.c"
    break;

  case 25: /* stmt: '{' stmt_list '}'  */
#line 84 "c6.y"
                                                            { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1571 "y.tab.c"
    break;

  case 26: /* stmt_list: stmt  */
#line 88 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1577 "y.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt  */
#line 89 "c6.y"
                                                        { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1583 "y.tab.c"
    break;

  case 28: /* expr: INTEGER  */
#line 93 "c6.y"
                                                        { (yyval.nPtr) = conInt((yyvsp[0].iValue)); }
#line 1589 "y.tab.c"
    break;

  case 29: /* expr: CHARACTER  */
#line 94 "c6.y"
                                                        { (yyval.nPtr) = conChar((yyvsp[0].cValue)); }
#line 1595 "y.tab.c"
    break;

  case 30: /* expr: STRING  */
#line 95 "c6.y"
                                                        { (yyval.nPtr) = conString((yyvsp[0].sValue)); }
#line 1601 "y.tab.c"
    break;

  case 31: /* expr: var_invk  */
#line 96 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1607 "y.tab.c"
    break;

  case 32: /* expr: func_call  */
#line 97 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1613 "y.tab.c"
    break;

  case 33: /* expr: '-' expr  */
#line 98 "c6.y"
                                                        { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1619 "y.tab.c"
    break;

  case 34: /* expr: expr '+' expr  */
#line 99 "c6.y"
                                                        { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1625 "y.tab.c"
    break;

  case 35: /* expr: expr '-' expr  */
#line 100 "c6.y"
                                                        { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1631 "y.tab.c"
    break;

  case 36: /* expr: expr '*' expr  */
#line 101 "c6.y"
                                                        { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1637 "y.tab.c"
    break;

  case 37: /* expr: expr '%' expr  */
#line 102 "c6.y"
                                                        { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1643 "y.tab.c"
    break;

  case 38: /* expr: expr '/' expr  */
#line 103 "c6.y"
                                                        { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1649 "y.tab.c"
    break;

  case 39: /* expr: expr '<' expr  */
#line 104 "c6.y"
                                                        { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1655 "y.tab.c"
    break;

  case 40: /* expr: expr '>' expr  */
#line 105 "c6.y"
                                                        { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1661 "y.tab.c"
    break;

  case 41: /* expr: expr GE expr  */
#line 106 "c6.y"
                                                        { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1667 "y.tab.c"
    break;

  case 42: /* expr: expr LE expr  */
#line 107 "c6.y"
                                                        { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1673 "y.tab.c"
    break;

  case 43: /* expr: expr NE expr  */
#line 108 "c6.y"
                                                        { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1679 "y.tab.c"
    break;

  case 44: /* expr: expr EQ expr  */
#line 109 "c6.y"
                                                        { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1685 "y.tab.c"
    break;

  case 45: /* expr: expr AND expr  */
#line 110 "c6.y"
                                                            { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1691 "y.tab.c"
    break;

  case 46: /* expr: expr OR expr  */
#line 111 "c6.y"
                                                            { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1697 "y.tab.c"
    break;

  case 47: /* expr: '(' expr ')'  */
#line 112 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1703 "y.tab.c"
    break;

  case 48: /* array_decl: ARRAY array_decl_list  */
#line 115 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1709 "y.tab.c"
    break;

  case 49: /* array_decl_list: array_decl_item  */
#line 118 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1715 "y.tab.c"
    break;

  case 50: /* array_decl_list: array_decl_list ',' array_decl_item  */
#line 119 "c6.y"
                                                        { (yyval.nPtr) = opr(';', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1721 "y.tab.c"
    break;

  case 51: /* array_decl_item: VARIABLE '[' int_list ']'  */
#line 122 "c6.y"
                                                        { (yyval.nPtr) = opr(ARRAY, 2, id(false, (yyvsp[-3].sValue)), (yyvsp[-1].nPtr)); }
#line 1727 "y.tab.c"
    break;

  case 52: /* array_decl_item: VARIABLE '[' int_list ']' '=' expr  */
#line 123 "c6.y"
                                                        { (yyval.nPtr) = opr(ARRAY, 3, id(false, (yyvsp[-5].sValue)), (yyvsp[-3].nPtr), (yyvsp[0].nPtr)); }
#line 1733 "y.tab.c"
    break;

  case 53: /* func_decl: FUNC VARIABLE '(' prm_list ')' '{' stmt_list '}'  */
#line 126 "c6.y"
                                                            { (yyval.nPtr) = func((yyvsp[-6].sValue), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr)); }
#line 1739 "y.tab.c"
    break;

  case 54: /* int_list: INTEGER  */
#line 129 "c6.y"
                                                        { (yyval.nPtr) = ari(NULL, (yyvsp[0].iValue)); }
#line 1745 "y.tab.c"
    break;

  case 55: /* int_list: int_list ',' INTEGER  */
#line 130 "c6.y"
                                                        { (yyval.nPtr) = ari((yyvsp[-2].nPtr), (yyvsp[0].iValue)); }
#line 1751 "y.tab.c"
    break;

  case 56: /* expr_list_opt: %empty  */
#line 133 "c6.y"
                                                        { (yyval.nPtr) = are(NULL, NULL); }
#line 1757 "y.tab.c"
    break;

  case 57: /* expr_list_opt: expr_list  */
#line 134 "c6.y"
                                                        { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1763 "y.tab.c"
    break;

  case 58: /* expr_list: expr  */
#line 137 "c6.y"
                                                        { (yyval.nPtr) = are(NULL, (yyvsp[0].nPtr)); }
#line 1769 "y.tab.c"
    break;

  case 59: /* expr_list: expr_list ',' expr  */
#line 138 "c6.y"
                                                        { (yyval.nPtr) = are((yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1775 "y.tab.c"
    break;

  case 60: /* prm_list: %empty  */
#line 141 "c6.y"
                                                        { (yyval.nPtr) = prm(NULL, NULL); }
#line 1781 "y.tab.c"
    break;

  case 61: /* prm_list: VARIABLE  */
#line 142 "c6.y"
                                                        { (yyval.nPtr) = prm(NULL, id(false, (yyvsp[0].sValue))); }
#line 1787 "y.tab.c"
    break;

  case 62: /* prm_list: VARIABLE '[' ']'  */
#line 143 "c6.y"
                                                        { (yyval.nPtr) = prm(NULL, ida(false, (yyvsp[-2].sValue), NULL)); }
#line 1793 "y.tab.c"
    break;

  case 63: /* prm_list: prm_list ',' VARIABLE  */
#line 144 "c6.y"
                                                        { (yyval.nPtr) = prm((yyvsp[-2].nPtr), id(false, (yyvsp[0].sValue))); }
#line 1799 "y.tab.c"
    break;

  case 64: /* prm_list: prm_list ',' VARIABLE '[' ']'  */
#line 145 "c6.y"
                                                        { (yyval.nPtr) = prm((yyvsp[-4].nPtr), ida(false, (yyvsp[-2].sValue), NULL)); }
#line 1805 "y.tab.c"
    break;

  case 65: /* var_invk: VARIABLE  */
#line 148 "c6.y"
                                                        { (yyval.nPtr) = id(false, (yyvsp[0].sValue)); }
#line 1811 "y.tab.c"
    break;

  case 66: /* var_invk: VARIABLE '[' expr_list ']'  */
#line 149 "c6.y"
                                                        { (yyval.nPtr) = ida(false, (yyvsp[-3].sValue), (yyvsp[-1].nPtr)); }
#line 1817 "y.tab.c"
    break;

  case 67: /* var_invk: '@' VARIABLE  */
#line 150 "c6.y"
                                                        { (yyval.nPtr) = id(true, (yyvsp[0].sValue)); }
#line 1823 "y.tab.c"
    break;

  case 68: /* var_invk: '@' VARIABLE '[' expr_list ']'  */
#line 151 "c6.y"
                                                        { (yyval.nPtr) = ida(true, (yyvsp[-3].sValue), (yyvsp[-1].nPtr)); }
#line 1829 "y.tab.c"
    break;

  case 69: /* func_call: VARIABLE '(' expr_list_opt ')'  */
#line 153 "c6.y"
                                                        { (yyval.nPtr) = opr(CALL, 2, id(false, (yyvsp[-3].sValue)), (yyvsp[-1].nPtr)); }
#line 1835 "y.tab.c"
    break;

  case 70: /* func_call: '@' VARIABLE '(' expr_list_opt ')'  */
#line 154 "c6.y"
                                                        { (yyval.nPtr) = opr(CALL, 2, id(false, (yyvsp[-3].sValue)), (yyvsp[-1].nPtr)); }
#line 1841 "y.tab.c"
    break;


#line 1845 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 157 "c6.y"


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
