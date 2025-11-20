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
#line 1 "temp.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);

int temp_count=0;
int label_count=0;

char* new_temp(){
    char *temp=(char*)malloc(10);
    sprintf(temp,"t%d",temp_count++);
    return temp;
}

char* new_label(){
    char *label=(char*)malloc(10);
    sprintf(label,"L%d",label_count++);
    return label;
}


#line 99 "y.tab.c"

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

#line 264 "y.tab.c"

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
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_ROUNDLBRACKET = 8,              /* ROUNDLBRACKET  */
  YYSYMBOL_ROUNDRBRACKET = 9,              /* ROUNDRBRACKET  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_BOOLEAN = 12,                   /* BOOLEAN  */
  YYSYMBOL_MULTIPLITIVE = 13,              /* MULTIPLITIVE  */
  YYSYMBOL_ADDITIVE = 14,                  /* ADDITIVE  */
  YYSYMBOL_RELATIONAL = 15,                /* RELATIONAL  */
  YYSYMBOL_EQUALITY = 16,                  /* EQUALITY  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_ASSIGNMENT = 19,                /* ASSIGNMENT  */
  YYSYMBOL_NEW = 20,                       /* NEW  */
  YYSYMBOL_CURLYRBRACKET = 21,             /* CURLYRBRACKET  */
  YYSYMBOL_CURLYLBRACKET = 22,             /* CURLYLBRACKET  */
  YYSYMBOL_CLASS = 23,                     /* CLASS  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_NEWARRAY = 25,                  /* NEWARRAY  */
  YYSYMBOL_UNARY = 26,                     /* UNARY  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_DO = 31,                        /* DO  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_SQUARERBRACKET = 33,            /* SQUARERBRACKET  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_SQUARELBRACKET = 35,            /* SQUARELBRACKET  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_LT = 37,                        /* LT  */
  YYSYMBOL_GT = 38,                        /* GT  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_GE = 40,                        /* GE  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_NE = 42,                        /* NE  */
  YYSYMBOL_MAIN = 43,                      /* MAIN  */
  YYSYMBOL_TRUELIT = 44,                   /* TRUELIT  */
  YYSYMBOL_FALSELIT = 45,                  /* FALSELIT  */
  YYSYMBOL_IDENTIFIER = 46,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 47,                    /* NUMBER  */
  YYSYMBOL_FNUMBER = 48,                   /* FNUMBER  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_UMINUS = 53,                    /* UMINUS  */
  YYSYMBOL_UNOT = 54,                      /* UNOT  */
  YYSYMBOL_IF_WITHOUT_ELSE = 55,           /* IF_WITHOUT_ELSE  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_FuncMain = 58,                  /* FuncMain  */
  YYSYMBOL_VarDecl = 59,                   /* VarDecl  */
  YYSYMBOL_idlist = 60,                    /* idlist  */
  YYSYMBOL_idlistarr = 61,                 /* idlistarr  */
  YYSYMBOL_type = 62,                      /* type  */
  YYSYMBOL_ExpressionMain = 63,            /* ExpressionMain  */
  YYSYMBOL_Expression = 64,                /* Expression  */
  YYSYMBOL_OptionalExp = 65,               /* OptionalExp  */
  YYSYMBOL_Lvalue = 66,                    /* Lvalue  */
  YYSYMBOL_AssignExp = 67,                 /* AssignExp  */
  YYSYMBOL_OperatorExp = 68,               /* OperatorExp  */
  YYSYMBOL_OperatorTerm = 69,              /* OperatorTerm  */
  YYSYMBOL_OperatorOperand = 70,           /* OperatorOperand  */
  YYSYMBOL_BooleanExp = 71,                /* BooleanExp  */
  YYSYMBOL_booleanExp = 72,                /* booleanExp  */
  YYSYMBOL_RelationalExp = 73,             /* RelationalExp  */
  YYSYMBOL_Stmts = 74,                     /* Stmts  */
  YYSYMBOL_Statement = 75,                 /* Statement  */
  YYSYMBOL_if_pref = 76,                   /* if_pref  */
  YYSYMBOL_ConditionalStmt = 77,           /* ConditionalStmt  */
  YYSYMBOL_78_1 = 78,                      /* @1  */
  YYSYMBOL_LoopStmt = 79,                  /* LoopStmt  */
  YYSYMBOL_whilestart = 80,                /* whilestart  */
  YYSYMBOL_whilecond = 81,                 /* whilecond  */
  YYSYMBOL_WhileStmt = 82                  /* WhileStmt  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    51,    49,     2,    50,     2,    52,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    53,    54,    55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    76,    80,    82,    85,    95,   105,   115,
     126,   126,   129,   131,   133,   135,   138,   144,   163,   169,
     175,   180,   186,   192,   199,   205,   209,   215,   221,   227,
     236,   247,   251,   257,   263,   269,   273,   277,   280,   286,
     292,   298,   304,   310,   317,   326,   326,   326,   328,   332,
     333,   336,   347,   351,   351,   363,   368,   373,   382
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "BOOL",
  "STRING", "VOID", "ROUNDLBRACKET", "ROUNDRBRACKET", "SEMICOLON", "FOR",
  "BOOLEAN", "MULTIPLITIVE", "ADDITIVE", "RELATIONAL", "EQUALITY", "AND",
  "OR", "ASSIGNMENT", "NEW", "CURLYRBRACKET", "CURLYLBRACKET", "CLASS",
  "COMMA", "NEWARRAY", "UNARY", "RETURN", "BREAK", "IF", "ELSE", "DO",
  "WHILE", "SQUARERBRACKET", "DOT", "SQUARELBRACKET", "NOT", "LT", "GT",
  "LE", "GE", "EQ", "NE", "MAIN", "TRUELIT", "FALSELIT", "IDENTIFIER",
  "NUMBER", "FNUMBER", "'+'", "'-'", "'*'", "'/'", "UMINUS", "UNOT",
  "IF_WITHOUT_ELSE", "$accept", "program", "FuncMain", "VarDecl", "idlist",
  "idlistarr", "type", "ExpressionMain", "Expression", "OptionalExp",
  "Lvalue", "AssignExp", "OperatorExp", "OperatorTerm", "OperatorOperand",
  "BooleanExp", "booleanExp", "RelationalExp", "Stmts", "Statement",
  "if_pref", "ConditionalStmt", "@1", "LoopStmt", "whilestart",
  "whilecond", "WhileStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -37,    17,   -46,    16,   -46,    27,    18,    35,   -46,
     -46,    62,    36,   -46,    62,   -46,   -46,   -15,   -46,   -46,
      26,    35,     8,   -46,   -46,    49,    42,   -46,   101,   -40,
     -46,   -46,     9,   -46,    44,    35,    46,   -46,   -46,    58,
     -46,    40,    95,     1,    62,   101,   -46,    30,    26,   -46,
     -46,    43,    -2,    -1,   -46,    78,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    62,    62,   -46,   -46,
      55,    62,    67,   -46,   -46,    12,    57,    -8,    45,   -46,
      47,   -46,    48,   -46,   -34,   -34,   -34,   -34,   -34,   -34,
     -40,   -40,   -46,   -46,   -46,    94,    74,    79,    55,   -46,
     -46,    80,   -46,    81,    85,   -46,    96,   -46,    71,   -46,
     -46,    86,    98,   -46,    55,   100,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,    47,    10,
      11,     0,     0,    56,     0,    35,    36,    29,    27,    28,
       0,    47,     0,    16,    12,     0,     0,    13,    14,    21,
      24,    15,    31,    38,     0,    47,     0,    49,    50,     0,
      55,    29,     0,     0,     0,     0,    34,     0,     0,    26,
      46,     7,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    45,
       0,     0,     0,    25,    37,     0,     0,     0,     0,     4,
       0,     5,     0,    18,    39,    40,    41,    42,    43,    44,
      19,    20,    22,    23,    33,    32,     0,     0,     0,    51,
      30,     0,     6,     0,    52,    57,     0,     9,     0,    53,
      58,     0,     0,     8,     0,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,   -46,   -46,   -46,    72,   -46,   -46,
     -46,   -46,   -11,   -31,   -13,   -46,    -9,   -46,    -7,   -45,
     -46,   -46,   -46,   -46,   -46,   -46,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    21,    52,    53,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   112,    38,    39,    72,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    73,    43,    45,   -17,    46,     4,    49,    79,    81,
      74,    64,    65,     1,    50,    62,    63,     5,    66,    67,
      47,    99,    80,    82,     6,    96,    66,    67,    69,    66,
      67,    90,    91,    45,    48,    75,     7,    77,     9,    10,
       8,    62,    63,    11,    44,    84,    85,    86,    87,    88,
      89,    92,    93,   106,    51,    45,    45,    94,    95,    54,
      45,    55,    97,    11,    12,    68,    71,    13,    70,   115,
      11,    14,    41,    18,    19,    47,    20,    76,    78,    15,
      16,    17,    18,    19,    12,    20,    11,    13,   105,    98,
     100,    14,   101,   102,   103,   104,    66,    67,    14,    15,
      16,    17,    18,    19,    73,    20,    15,    16,    41,    18,
      19,    66,    20,   107,    14,   109,   108,   110,   111,   113,
     114,   116,    15,    16,    17,    18,    19,    83,    20,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
      62,    63
};

static const yytype_int8 yycheck[] =
{
      11,     9,    11,    14,    19,    14,    43,    20,    10,    10,
       9,    51,    52,     7,    21,    49,    50,     0,    17,    18,
      35,     9,    24,    24,     8,    70,    17,    18,    35,    17,
      18,    62,    63,    44,     8,    44,     9,    48,     3,     4,
      22,    49,    50,     8,     8,    56,    57,    58,    59,    60,
      61,    64,    65,    98,    46,    66,    67,    66,    67,    10,
      71,    19,    71,     8,    29,    21,     8,    32,    22,   114,
       8,    36,    46,    47,    48,    35,    50,    47,    35,    44,
      45,    46,    47,    48,    29,    50,     8,    32,     9,    22,
      33,    36,    47,    46,    46,    21,    17,    18,    36,    44,
      45,    46,    47,    48,     9,    50,    44,    45,    46,    47,
      48,    17,    50,    33,    36,    30,    35,    21,    47,    33,
      22,    21,    44,    45,    46,    47,    48,    55,    50,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    37,    38,
      39,    40,    41,    42,    49,    50,    -1,    -1,    -1,    -1,
      49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    57,    58,    43,     0,     8,     9,    22,     3,
       4,     8,    29,    32,    36,    44,    45,    46,    47,    48,
      50,    59,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    79,    80,
      82,    46,    68,    72,     8,    68,    72,    35,     8,    70,
      74,    46,    60,    61,    10,    19,    37,    38,    39,    40,
      41,    42,    49,    50,    51,    52,    17,    18,    21,    74,
      22,     8,    81,     9,     9,    72,    47,    68,    35,    10,
      24,    10,    24,    63,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    72,    72,    75,    72,    22,     9,
      33,    47,    46,    46,    21,     9,    75,    33,    35,    30,
      21,    47,    78,    33,    22,    75,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    66,    67,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    76,    77,    78,    77,    79,    80,    81,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     7,     3,     3,     3,     1,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     2,     1,     1,     1,
       4,     1,     3,     3,     2,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     2,     2,     0,     2,     1,
       1,     4,     4,     0,     9,     1,     1,     3,     5
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
  case 4: /* VarDecl: type idlist SEMICOLON  */
#line 80 "temp.y"
                              {}
#line 1410 "y.tab.c"
    break;

  case 5: /* VarDecl: type idlistarr SEMICOLON  */
#line 82 "temp.y"
                                {}
#line 1416 "y.tab.c"
    break;

  case 6: /* idlist: idlist COMMA IDENTIFIER  */
#line 85 "temp.y"
                                 {
    Symbol* sym=lookupSymbol((yyvsp[0].str));
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",(yyvsp[0].str));
                exit(1);
            }
     insertSymbol((yyvsp[0].str),(yyvsp[-3].str),0);
        (yyval.str)=(yyvsp[0].str);
}
#line 1430 "y.tab.c"
    break;

  case 7: /* idlist: IDENTIFIER  */
#line 95 "temp.y"
          {
    Symbol* sym=lookupSymbol((yyvsp[0].str));
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",(yyvsp[0].str));
                exit(1);
            }
     insertSymbol((yyvsp[0].str),(yyvsp[-1].str),0);
        (yyval.str)=(yyvsp[0].str);
}
#line 1444 "y.tab.c"
    break;

  case 8: /* idlistarr: idlistarr COMMA IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET  */
#line 105 "temp.y"
                                                                              {
    Symbol* sym=lookupSymbol((yyvsp[-3].str));
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",(yyvsp[-3].str));
                exit(1);
            }
     insertSymbol((yyvsp[-3].str),(yyvsp[-6].str),0);
        (yyval.str)=(yyvsp[-3].str);
}
#line 1458 "y.tab.c"
    break;

  case 9: /* idlistarr: IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET  */
#line 115 "temp.y"
                                                {
    Symbol* sym=lookupSymbol((yyvsp[-3].str));
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",(yyvsp[-3].str));
                exit(1);
            }
     insertSymbol((yyvsp[-3].str),(yyvsp[-4].str),0);
        (yyval.str)=(yyvsp[-3].str);
}
#line 1472 "y.tab.c"
    break;

  case 10: /* type: INT  */
#line 126 "temp.y"
           {(yyval.str)=strdup("int");}
#line 1478 "y.tab.c"
    break;

  case 11: /* type: FLOAT  */
#line 126 "temp.y"
                                       {(yyval.str)=strdup("float");}
#line 1484 "y.tab.c"
    break;

  case 12: /* ExpressionMain: Expression  */
#line 129 "temp.y"
              {(yyval.str)=(yyvsp[0].str);}
#line 1490 "y.tab.c"
    break;

  case 13: /* ExpressionMain: AssignExp  */
#line 131 "temp.y"
             {(yyval.str)=(yyvsp[0].str);}
#line 1496 "y.tab.c"
    break;

  case 14: /* Expression: OperatorExp  */
#line 133 "temp.y"
               {(yyval.str)=(yyvsp[0].str);}
#line 1502 "y.tab.c"
    break;

  case 15: /* Expression: BooleanExp  */
#line 135 "temp.y"
              {(yyval.str)=(yyvsp[0].str);}
#line 1508 "y.tab.c"
    break;

  case 16: /* OptionalExp: ExpressionMain  */
#line 138 "temp.y"
                      {(yyval.str)=(yyvsp[0].str);}
#line 1514 "y.tab.c"
    break;

  case 17: /* Lvalue: IDENTIFIER  */
#line 144 "temp.y"
                {
        Symbol* sym=lookupSymbol((yyvsp[0].str));
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",(yyvsp[0].str));
            exit(1);
        }
        (yyval.str)=(yyvsp[0].str);
      }
#line 1527 "y.tab.c"
    break;

  case 18: /* AssignExp: Lvalue ASSIGNMENT ExpressionMain  */
#line 163 "temp.y"
                                        {
        printf("%s=%s\n",(yyvsp[-2].str),(yyvsp[0].str));
    }
#line 1535 "y.tab.c"
    break;

  case 19: /* OperatorExp: OperatorExp '+' OperatorTerm  */
#line 169 "temp.y"
                                {
        char *temp=new_temp();
        printf("%s=%s+%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1545 "y.tab.c"
    break;

  case 20: /* OperatorExp: OperatorExp '-' OperatorTerm  */
#line 175 "temp.y"
                                {
        char *temp=new_temp();
        printf("%s=%s-%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1555 "y.tab.c"
    break;

  case 21: /* OperatorExp: OperatorTerm  */
#line 180 "temp.y"
                  {
        (yyval.str)=(yyvsp[0].str);
    }
#line 1563 "y.tab.c"
    break;

  case 22: /* OperatorTerm: OperatorTerm '*' OperatorOperand  */
#line 186 "temp.y"
                                    {
        char *temp=new_temp();
        printf("%s=%s*%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1573 "y.tab.c"
    break;

  case 23: /* OperatorTerm: OperatorTerm '/' OperatorOperand  */
#line 192 "temp.y"
                                    {
        char *temp=new_temp();
        printf("%s=%s/%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1583 "y.tab.c"
    break;

  case 24: /* OperatorTerm: OperatorOperand  */
#line 199 "temp.y"
                   {
        (yyval.str)=(yyvsp[0].str);
    }
#line 1591 "y.tab.c"
    break;

  case 25: /* OperatorOperand: ROUNDLBRACKET OperatorExp ROUNDRBRACKET  */
#line 205 "temp.y"
                                            {
        (yyval.str)=(yyvsp[-1].str);
    }
#line 1599 "y.tab.c"
    break;

  case 26: /* OperatorOperand: '-' OperatorOperand  */
#line 209 "temp.y"
                                    {
        char *temp=new_temp();
        printf("%s=-%s\n",temp,(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1609 "y.tab.c"
    break;

  case 27: /* OperatorOperand: NUMBER  */
#line 215 "temp.y"
           {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%d",(yyvsp[0].num));
        (yyval.str)=temp;
    }
#line 1619 "y.tab.c"
    break;

  case 28: /* OperatorOperand: FNUMBER  */
#line 221 "temp.y"
            {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%.2f",(yyvsp[0].fnum));
        (yyval.str)=temp;
    }
#line 1629 "y.tab.c"
    break;

  case 29: /* OperatorOperand: IDENTIFIER  */
#line 227 "temp.y"
              {
        Symbol* sym=lookupSymbol((yyvsp[0].str));
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",(yyvsp[0].str));
            exit(1);
        }
        (yyval.str)=(yyvsp[0].str);
    }
#line 1642 "y.tab.c"
    break;

  case 30: /* OperatorOperand: IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET  */
#line 236 "temp.y"
                                                    {
        Symbol* sym=lookupSymbol((yyvsp[-3].str));
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",(yyvsp[-3].str));
            exit(1);
        }
        (yyval.str)=(yyvsp[-3].str);
    }
#line 1655 "y.tab.c"
    break;

  case 31: /* BooleanExp: booleanExp  */
#line 247 "temp.y"
              {
        
    }
#line 1663 "y.tab.c"
    break;

  case 32: /* booleanExp: booleanExp OR booleanExp  */
#line 251 "temp.y"
                             {
        char *temp=new_temp();
        printf("%s=%s||%s\n",temp,(yyvsp[-2].b).place,(yyvsp[0].b).place);
        (yyval.b).place=temp;
        (yyval.b).code="";
    }
#line 1674 "y.tab.c"
    break;

  case 33: /* booleanExp: booleanExp AND booleanExp  */
#line 257 "temp.y"
                               {
        char *temp=new_temp();
        printf("%s=%s&&%s\n",temp,(yyvsp[-2].b).place,(yyvsp[0].b).place);
        (yyval.b).place=temp;
        (yyval.b).code="";
    }
#line 1685 "y.tab.c"
    break;

  case 34: /* booleanExp: NOT booleanExp  */
#line 263 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=!%s\n",temp,(yyvsp[0].b).place);
        (yyval.b).place=temp;
        (yyval.b).code="";
    }
#line 1696 "y.tab.c"
    break;

  case 35: /* booleanExp: TRUELIT  */
#line 269 "temp.y"
            {
        (yyval.b).place=strdup("true");
        (yyval.b).code="";
    }
#line 1705 "y.tab.c"
    break;

  case 36: /* booleanExp: FALSELIT  */
#line 273 "temp.y"
             {
            (yyval.b).place=strdup("false");
        (yyval.b).code="";
    }
#line 1714 "y.tab.c"
    break;

  case 37: /* booleanExp: ROUNDLBRACKET booleanExp ROUNDRBRACKET  */
#line 277 "temp.y"
                                             { 
        (yyval.b)=(yyvsp[-1].b);
    }
#line 1722 "y.tab.c"
    break;

  case 38: /* booleanExp: RelationalExp  */
#line 280 "temp.y"
                    {
        (yyval.b).place=(yyvsp[0].str);
        (yyval.b).code="";
    }
#line 1731 "y.tab.c"
    break;

  case 39: /* RelationalExp: OperatorExp LT OperatorExp  */
#line 286 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s<%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1741 "y.tab.c"
    break;

  case 40: /* RelationalExp: OperatorExp GT OperatorExp  */
#line 292 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s>%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1751 "y.tab.c"
    break;

  case 41: /* RelationalExp: OperatorExp LE OperatorExp  */
#line 298 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s<=%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1761 "y.tab.c"
    break;

  case 42: /* RelationalExp: OperatorExp GE OperatorExp  */
#line 304 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s>=%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1771 "y.tab.c"
    break;

  case 43: /* RelationalExp: OperatorExp EQ OperatorExp  */
#line 310 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s==%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1781 "y.tab.c"
    break;

  case 44: /* RelationalExp: OperatorExp NE OperatorExp  */
#line 317 "temp.y"
                              {
        char *temp=new_temp();
        printf("%s=%s!=%s\n",temp,(yyvsp[-2].str),(yyvsp[0].str));
        (yyval.str)=temp;
    }
#line 1791 "y.tab.c"
    break;

  case 48: /* Statement: OptionalExp SEMICOLON  */
#line 328 "temp.y"
                                    { 
    (yyval.str)=(yyvsp[-1].str);
}
#line 1799 "y.tab.c"
    break;

  case 49: /* Statement: ConditionalStmt  */
#line 332 "temp.y"
                {(yyval.str)=(yyvsp[0].str);}
#line 1805 "y.tab.c"
    break;

  case 50: /* Statement: LoopStmt  */
#line 333 "temp.y"
            {(yyval.str)=(yyvsp[0].str);}
#line 1811 "y.tab.c"
    break;

  case 51: /* if_pref: IF ROUNDLBRACKET booleanExp ROUNDRBRACKET  */
#line 336 "temp.y"
                                                    {
    char * true_label=new_label();
    char * false_label=new_label();

    printf("if %s goto %s\n",(yyvsp[-1].b).place,true_label);
    printf("goto %s\n",false_label);
    printf("%s : \n",true_label);
    (yyval.str)=false_label;
    
}
#line 1826 "y.tab.c"
    break;

  case 52: /* ConditionalStmt: if_pref CURLYLBRACKET Statement CURLYRBRACKET  */
#line 347 "temp.y"
                                                                                         {
   printf("%s :\n",(yyvsp[-3].str));
}
#line 1834 "y.tab.c"
    break;

  case 53: /* @1: %empty  */
#line 351 "temp.y"
                                                    {
    char* ifexit=new_label();
    printf("goto %s :\n",ifexit);
    printf("%s :\n",(yyvsp[-4].str));
    (yyval.str)=ifexit;

}
#line 1846 "y.tab.c"
    break;

  case 54: /* ConditionalStmt: if_pref CURLYLBRACKET Statement CURLYRBRACKET ELSE @1 CURLYLBRACKET Statement CURLYRBRACKET  */
#line 357 "temp.y"
                                        {
    char *ifexit=(yyvsp[-3].str);
    printf("%s :\n",ifexit);
}
#line 1855 "y.tab.c"
    break;

  case 55: /* LoopStmt: WhileStmt  */
#line 363 "temp.y"
                      {
    (yyval.str)=(yyvsp[0].str);
}
#line 1863 "y.tab.c"
    break;

  case 56: /* whilestart: WHILE  */
#line 368 "temp.y"
                   {
    char* whilebegin=new_label();
    printf("%s : \n",whilebegin);
    (yyval.str)=whilebegin;
}
#line 1873 "y.tab.c"
    break;

  case 57: /* whilecond: ROUNDLBRACKET booleanExp ROUNDRBRACKET  */
#line 373 "temp.y"
                                                   {
    char* condtrue=new_label();
    char* condfalse=new_label();
    printf("if %s goto %s\n",(yyvsp[-1].b).place,condtrue);
    printf("goto %s \n",condfalse);
    printf("%s :\n",condtrue);
    (yyval.str)=condfalse;
}
#line 1886 "y.tab.c"
    break;

  case 58: /* WhileStmt: whilestart whilecond CURLYLBRACKET Statement CURLYRBRACKET  */
#line 382 "temp.y"
                                                                      {
   printf("goto %s\n",(yyvsp[-4].str));
   printf("%s : \n",(yyvsp[-3].str));
}
#line 1895 "y.tab.c"
    break;


#line 1899 "y.tab.c"

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

#line 387 "temp.y"



int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }

    if (yyparse() == 0) {
        printf("Parsing Successfull.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}

void yyerror(const char *s) {
    printf("Sematics Error: %s\n", s);
    printf("Exiting the analysis \n");
    exit(1);
} 







