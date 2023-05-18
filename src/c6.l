%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc6.h"
#include "y.tab.h"
void yyerror(char *);
int symtable_size = 0;
%}

%%

"for"		    return FOR;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"geti"          return GETI;
"getc"          return GETC;
"gets"          return GETS;
"puti"          return PUTI;
"puti_"         return PUTI_;
"putc"          return PUTC;
"putc_"         return PUTC_;
"puts"          return PUTS;
"puts_"         return PUTS_;

[a-zA-Z][a-zA-Z0-9]{0,19}       { 
                                    yylval.sIndex = get_symtable_ind(yytext);
                                    return VARIABLE;
                                }

\'.\'       {
                yylval.cValue = yytext[1];  // Get match inside ''
                return CHARACTER;
            }

\".*\"      {
                char *yytextTrimmed = remove_first_last_char(yytext);
                yylval.sValue = yytextTrimmed;
                return STRING;
            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[-()<>=+*/;{}.%] {
                return *yytext;
             }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"		return AND;
"||"		return OR;

\/\/.*\n	;	/* skip comments */

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}

char* remove_first_last_char(char* str) {
    size_t len = strlen(str);
    if (len <= 2) {
        return "";
    }
    char* new_str = malloc(len - 1);
    strncpy(new_str, str + 1, len - 2);
    new_str[len - 2] = '\0';
    return new_str;
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
    for (int i = 0; i < symtable_size; i++) {
        if (strcmp(symtable[i], loweredVar) == 0) {
            return i;
        }
    }
    symtable[symtable_size++] = loweredVar;
    return symtable_size - 1;
}
