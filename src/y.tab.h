/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    IFX = 275,                     /* IFX  */
    ELSE = 276,                    /* ELSE  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    GE = 279,                      /* GE  */
    LE = 280,                      /* LE  */
    EQ = 281,                      /* EQ  */
    NE = 282,                      /* NE  */
    UMINUS = 283                   /* UMINUS  */
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
#define IFX 275
#define ELSE 276
#define AND 277
#define OR 278
#define GE 279
#define LE 280
#define EQ 281
#define NE 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "c6.y"

    int iValue;                 /* integer value */
    char cValue;                /* character value */
    char *sValue;               /* string value */
    nodeType *nPtr;             /* node pointer */

#line 130 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
