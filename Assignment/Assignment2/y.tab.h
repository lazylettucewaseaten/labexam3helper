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
    INT = 258,                     /* INT  */
    DOUBLE = 259,                  /* DOUBLE  */
    BOOL = 260,                    /* BOOL  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    MAIN = 263,                    /* MAIN  */
    ROUNDLBRACKET = 264,           /* ROUNDLBRACKET  */
    ROUNDRBRACKET = 265,           /* ROUNDRBRACKET  */
    SEMICOLON = 266,               /* SEMICOLON  */
    FOR = 267,                     /* FOR  */
    BOOLEAN = 268,                 /* BOOLEAN  */
    STRING_LITERAL = 269,          /* STRING_LITERAL  */
    IDENTIFIER = 270,              /* IDENTIFIER  */
    MULTIPLITIVE = 271,            /* MULTIPLITIVE  */
    ADDITIVE = 272,                /* ADDITIVE  */
    RELATIONAL = 273,              /* RELATIONAL  */
    EQUALITY = 274,                /* EQUALITY  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    ASSIGNMENT = 277,              /* ASSIGNMENT  */
    NEW = 278,                     /* NEW  */
    CURLYRBRACKET = 279,           /* CURLYRBRACKET  */
    CURLYLBRACKET = 280,           /* CURLYLBRACKET  */
    CLASS = 281,                   /* CLASS  */
    NUMBER = 282,                  /* NUMBER  */
    COMMA = 283,                   /* COMMA  */
    NEWARRAY = 284,                /* NEWARRAY  */
    UNARY = 285,                   /* UNARY  */
    RETURN = 286,                  /* RETURN  */
    BREAK = 287,                   /* BREAK  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    DO = 290,                      /* DO  */
    WHILE = 291,                   /* WHILE  */
    SQUARERBRACKET = 292,          /* SQUARERBRACKET  */
    DOT = 293,                     /* DOT  */
    SQUARELBRACKET = 294,          /* SQUARELBRACKET  */
    IF_WITHOUT_ELSE = 295          /* IF_WITHOUT_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define DOUBLE 259
#define BOOL 260
#define STRING 261
#define VOID 262
#define MAIN 263
#define ROUNDLBRACKET 264
#define ROUNDRBRACKET 265
#define SEMICOLON 266
#define FOR 267
#define BOOLEAN 268
#define STRING_LITERAL 269
#define IDENTIFIER 270
#define MULTIPLITIVE 271
#define ADDITIVE 272
#define RELATIONAL 273
#define EQUALITY 274
#define AND 275
#define OR 276
#define ASSIGNMENT 277
#define NEW 278
#define CURLYRBRACKET 279
#define CURLYLBRACKET 280
#define CLASS 281
#define NUMBER 282
#define COMMA 283
#define NEWARRAY 284
#define UNARY 285
#define RETURN 286
#define BREAK 287
#define IF 288
#define ELSE 289
#define DO 290
#define WHILE 291
#define SQUARERBRACKET 292
#define DOT 293
#define SQUARELBRACKET 294
#define IF_WITHOUT_ELSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
