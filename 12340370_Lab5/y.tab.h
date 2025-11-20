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
    int_ = 258,                    /* int_  */
    float_ = 259,                  /* float_  */
    double_ = 260,                 /* double_  */
    char_ = 261,                   /* char_  */
    var = 262,                     /* var  */
    comma = 263,                   /* comma  */
    colon = 264,                   /* colon  */
    integer = 265,                 /* integer  */
    equate = 266,                  /* equate  */
    add = 267,                     /* add  */
    sub = 268,                     /* sub  */
    mul = 269,                     /* mul  */
    DIV = 270,                     /* DIV  */
    lbracket = 271,                /* lbracket  */
    rbracket = 272,                /* rbracket  */
    for_ = 273,                    /* for_  */
    incre = 274,                   /* incre  */
    decre = 275,                   /* decre  */
    lt = 276,                      /* lt  */
    gt = 277,                      /* gt  */
    lte = 278,                     /* lte  */
    gte = 279,                     /* gte  */
    eqe = 280,                     /* eqe  */
    ne = 281,                      /* ne  */
    lbrace = 282,                  /* lbrace  */
    rbrace = 283                   /* rbrace  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define int_ 258
#define float_ 259
#define double_ 260
#define char_ 261
#define var 262
#define comma 263
#define colon 264
#define integer 265
#define equate 266
#define add 267
#define sub 268
#define mul 269
#define DIV 270
#define lbracket 271
#define rbracket 272
#define for_ 273
#define incre 274
#define decre 275
#define lt 276
#define gt 277
#define lte 278
#define gte 279
#define eqe 280
#define ne 281
#define lbrace 282
#define rbrace 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
