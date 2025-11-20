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
    FLOAT = 259,                   /* FLOAT  */
    BOOL = 260,                    /* BOOL  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    ROUNDLBRACKET = 263,           /* ROUNDLBRACKET  */
    ROUNDRBRACKET = 264,           /* ROUNDRBRACKET  */
    SEMICOLON = 265,               /* SEMICOLON  */
    FOR = 266,                     /* FOR  */
    BOOLEAN = 267,                 /* BOOLEAN  */
    MULTIPLITIVE = 268,            /* MULTIPLITIVE  */
    ADDITIVE = 269,                /* ADDITIVE  */
    RELATIONAL = 270,              /* RELATIONAL  */
    EQUALITY = 271,                /* EQUALITY  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    ASSIGNMENT = 274,              /* ASSIGNMENT  */
    NEW = 275,                     /* NEW  */
    CURLYRBRACKET = 276,           /* CURLYRBRACKET  */
    CURLYLBRACKET = 277,           /* CURLYLBRACKET  */
    CLASS = 278,                   /* CLASS  */
    COMMA = 279,                   /* COMMA  */
    NEWARRAY = 280,                /* NEWARRAY  */
    UNARY = 281,                   /* UNARY  */
    RETURN = 282,                  /* RETURN  */
    BREAK = 283,                   /* BREAK  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    DO = 286,                      /* DO  */
    WHILE = 287,                   /* WHILE  */
    SQUARERBRACKET = 288,          /* SQUARERBRACKET  */
    DOT = 289,                     /* DOT  */
    SQUARELBRACKET = 290,          /* SQUARELBRACKET  */
    NOT = 291,                     /* NOT  */
    LT = 292,                      /* LT  */
    GT = 293,                      /* GT  */
    LE = 294,                      /* LE  */
    GE = 295,                      /* GE  */
    EQ = 296,                      /* EQ  */
    NE = 297,                      /* NE  */
    MAIN = 298,                    /* MAIN  */
    TRUELIT = 299,                 /* TRUELIT  */
    FALSELIT = 300,                /* FALSELIT  */
    IDENTIFIER = 301,              /* IDENTIFIER  */
    NUMBER = 302,                  /* NUMBER  */
    FNUMBER = 303,                 /* FNUMBER  */
    UMINUS = 304,                  /* UMINUS  */
    UNOT = 305,                    /* UNOT  */
    IF_WITHOUT_ELSE = 306          /* IF_WITHOUT_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define VOID 262
#define ROUNDLBRACKET 263
#define ROUNDRBRACKET 264
#define SEMICOLON 265
#define FOR 266
#define BOOLEAN 267
#define MULTIPLITIVE 268
#define ADDITIVE 269
#define RELATIONAL 270
#define EQUALITY 271
#define AND 272
#define OR 273
#define ASSIGNMENT 274
#define NEW 275
#define CURLYRBRACKET 276
#define CURLYLBRACKET 277
#define CLASS 278
#define COMMA 279
#define NEWARRAY 280
#define UNARY 281
#define RETURN 282
#define BREAK 283
#define IF 284
#define ELSE 285
#define DO 286
#define WHILE 287
#define SQUARERBRACKET 288
#define DOT 289
#define SQUARELBRACKET 290
#define NOT 291
#define LT 292
#define GT 293
#define LE 294
#define GE 295
#define EQ 296
#define NE 297
#define MAIN 298
#define TRUELIT 299
#define FALSELIT 300
#define IDENTIFIER 301
#define NUMBER 302
#define FNUMBER 303
#define UMINUS 304
#define UNOT 305
#define IF_WITHOUT_ELSE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "temp.y"

    int num;
    float fnum;
    char *str;
    struct {
        char* place;
        char* code;
    } b;

#line 179 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
