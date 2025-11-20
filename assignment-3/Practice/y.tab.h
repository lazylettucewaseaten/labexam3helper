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
    ID = 258,                      /* ID  */
    NUM = 259,                     /* NUM  */
    FNUM = 260,                    /* FNUM  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    CHAR = 263,                    /* CHAR  */
    VOID = 264,                    /* VOID  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    RETURN = 268,                  /* RETURN  */
    MAIN = 269,                    /* MAIN  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    MULT = 272,                    /* MULT  */
    DIV = 273,                     /* DIV  */
    MOD = 274,                     /* MOD  */
    ASSIGN = 275,                  /* ASSIGN  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    LT = 278,                      /* LT  */
    LE = 279,                      /* LE  */
    GT = 280,                      /* GT  */
    GE = 281,                      /* GE  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    NOT = 284,                     /* NOT  */
    LPAREN = 285,                  /* LPAREN  */
    RPAREN = 286,                  /* RPAREN  */
    LBRACE = 287,                  /* LBRACE  */
    RBRACE = 288,                  /* RBRACE  */
    LBRACK = 289,                  /* LBRACK  */
    RBRACK = 290,                  /* RBRACK  */
    SEMI = 291,                    /* SEMI  */
    COMMA = 292,                   /* COMMA  */
    LOWER_THAN_ELSE = 293,         /* LOWER_THAN_ELSE  */
    UMINUS = 294                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define NUM 259
#define FNUM 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define VOID 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define RETURN 268
#define MAIN 269
#define PLUS 270
#define MINUS 271
#define MULT 272
#define DIV 273
#define MOD 274
#define ASSIGN 275
#define EQ 276
#define NE 277
#define LT 278
#define LE 279
#define GT 280
#define GE 281
#define AND 282
#define OR 283
#define NOT 284
#define LPAREN 285
#define RPAREN 286
#define LBRACE 287
#define RBRACE 288
#define LBRACK 289
#define RBRACK 290
#define SEMI 291
#define COMMA 292
#define LOWER_THAN_ELSE 293
#define UMINUS 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser.y"

    char *str;
    struct {
        char *addr;
    } expr;
    struct {
        char *start;
        char *end;
        char *inc;
    } loop_labels;

#line 157 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
