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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

int yylex();
void yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;

int temp_count = 0;
int label_count = 0;
int current_scope = 0;
char *current_type = NULL;

char* new_temp() {
    char *temp = (char*)malloc(20);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

void emit(const char *op, const char *arg1, const char *arg2, const char *result) {
    if (arg1 && arg2)
        printf("%s = %s %s %s\n", result, arg1, op, arg2);
    else if (arg1)
        printf("%s = %s %s\n", result, op, arg1);
    else
        printf("%s %s\n", op, result);
}

void emit_label(const char *label) {
    printf("%s:\n", label);
}

void emit_goto(const char *label) {
    printf("goto %s\n", label);
}

void emit_if(const char *cond, const char *label) {
    printf("if %s goto %s\n", cond, label);
}

void emit_return(const char *val) {
    if (val)
        printf("return %s\n", val);
    else
        printf("return\n");
}

void check_declared(char* name) {
    Symbol* sym = lookupSymbol(name);
    if (sym == NULL) {
        printf("Error: Variable '%s' not declared before use\n", name);
        exit(1);
    }
}



#line 138 "y.tab.c"

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

#line 281 "y.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_FNUM = 5,                       /* FNUM  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MULT = 17,                      /* MULT  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LPAREN = 30,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 31,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 32,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 34,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 35,                    /* RBRACK  */
  YYSYMBOL_SEMI = 36,                      /* SEMI  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_LOWER_THAN_ELSE = 38,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_UMINUS = 39,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_type = 43,                      /* type  */
  YYSYMBOL_compound_stmt = 44,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 45,                 /* stmt_list  */
  YYSYMBOL_stmt = 46,                      /* stmt  */
  YYSYMBOL_var_declaration = 47,           /* var_declaration  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_declarator_list = 49,           /* declarator_list  */
  YYSYMBOL_declarator = 50,                /* declarator  */
  YYSYMBOL_expr_stmt = 51,                 /* expr_stmt  */
  YYSYMBOL_selection_stmt = 52,            /* selection_stmt  */
  YYSYMBOL_53_3 = 53,                      /* @3  */
  YYSYMBOL_if_prefix = 54,                 /* if_prefix  */
  YYSYMBOL_iteration_stmt = 55,            /* iteration_stmt  */
  YYSYMBOL_while_prefix = 56,              /* while_prefix  */
  YYSYMBOL_jump_stmt = 57,                 /* jump_stmt  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_logical_or_expr = 59,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 60,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 61,             /* equality_expr  */
  YYSYMBOL_relational_expr = 62,           /* relational_expr  */
  YYSYMBOL_additive_expr = 63,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 64,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 65,                /* unary_expr  */
  YYSYMBOL_primary_expr = 66,              /* primary_expr  */
  YYSYMBOL_postfix_expr = 67               /* postfix_expr  */
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   109,   117,   118,   119,   120,   124,   125,
     129,   130,   134,   135,   136,   137,   138,   139,   143,   143,
     153,   154,   158,   163,   169,   178,   179,   183,   187,   187,
     200,   211,   221,   237,   240,   246,   251,   257,   263,   268,
     274,   279,   285,   290,   295,   301,   306,   311,   316,   321,
     327,   332,   337,   343,   348,   353,   358,   364,   369,   374,
     377,   383,   387,   390,   393,   399
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "FNUM",
  "INT", "FLOAT", "CHAR", "VOID", "IF", "ELSE", "WHILE", "RETURN", "MAIN",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "ASSIGN", "EQ", "NE", "LT", "LE",
  "GT", "GE", "AND", "OR", "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "SEMI", "COMMA", "LOWER_THAN_ELSE", "UMINUS",
  "$accept", "program", "$@1", "type", "compound_stmt", "stmt_list",
  "stmt", "var_declaration", "$@2", "declarator_list", "declarator",
  "expr_stmt", "selection_stmt", "@3", "if_prefix", "iteration_stmt",
  "while_prefix", "jump_stmt", "expr", "logical_or_expr",
  "logical_and_expr", "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "primary_expr", "postfix_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,   -27,   -27,   -27,   -27,     2,    49,   -27,   -10,    41,
     -27,     5,     6,   -27,   -13,   -27,   -27,    50,    53,    46,
     110,   110,   113,   -27,   -27,   -27,   -27,    61,   -27,   -27,
     -27,   -27,    95,   -27,    95,   -27,    52,    57,    65,    19,
      20,    32,    15,   -27,   -27,   -27,   113,   113,   113,   113,
     -27,    59,    62,   -27,   -27,    75,   106,   -27,   -27,    99,
     -27,   -27,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   -27,    77,    88,    89,   -27,
     113,   -27,    -3,    23,   -27,   -27,    65,    19,    20,    20,
      32,    32,    32,    32,    15,    15,   -27,   -27,   -27,   101,
     -27,   -27,    87,   113,   119,   -27,   106,    95,   113,   -27,
     -27,    93,   -27,   -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     5,     6,     7,     0,     0,     1,     0,     0,
       2,     0,     0,     3,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     9,    26,    18,    13,     0,    11,    17,
      12,    14,     0,    15,     0,    16,     0,    37,    39,    41,
      44,    49,    52,    56,    59,    60,     0,     0,     0,     0,
      34,     0,    61,    57,    58,     0,     0,     8,    10,    27,
      31,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,    33,
       0,    64,    22,     0,    20,    28,    38,    40,    42,    43,
      45,    46,    47,    48,    50,    51,    53,    54,    55,    65,
      30,    32,     0,     0,     0,    19,     0,     0,     0,    65,
      23,     0,    21,    29,    36,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   -27,   130,   121,   -27,   -26,   -27,   -27,   -27,
      27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -19,   -27,
      72,    73,    14,   -14,    16,   -16,   -27,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,    11,    25,    26,    27,    28,    29,    56,    83,
      84,    30,    31,   107,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    58,     7,    55,    53,    54,    59,    46,    60,    14,
      15,    16,     1,     2,     3,     4,    17,   103,    18,    19,
       9,    47,    20,     1,     2,     3,     4,    75,    76,    77,
      78,   104,    72,    73,    74,    21,    22,    12,    12,    23,
      64,    65,    24,    66,    67,    68,    69,    70,    71,    14,
      15,    16,    90,    91,    92,    93,    96,    97,    98,   105,
     106,   102,    20,     8,    14,    15,    16,     1,     2,     3,
       4,    17,    10,    18,    19,    21,    22,    20,    88,    89,
      48,   113,    50,    49,   110,    62,    94,    95,    61,   114,
      21,    22,    63,    12,    57,    79,    80,    24,    14,    15,
      16,     1,     2,     3,     4,    17,    81,    18,    19,    82,
      85,    20,    99,    52,    15,    16,    14,    15,    16,   100,
     101,   108,   109,   111,    21,    22,    20,    12,   115,    20,
       6,    24,    13,   112,    86,     0,    87,     0,     0,    21,
      22,     0,    21,    22
};

static const yytype_int8 yycheck[] =
{
      19,    27,     0,    22,    20,    21,    32,    20,    34,     3,
       4,     5,     6,     7,     8,     9,    10,    20,    12,    13,
      30,    34,    16,     6,     7,     8,     9,    46,    47,    48,
      49,    34,    17,    18,    19,    29,    30,    32,    32,    33,
      21,    22,    36,    23,    24,    25,    26,    15,    16,     3,
       4,     5,    66,    67,    68,    69,    72,    73,    74,    36,
      37,    80,    16,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    31,    12,    13,    29,    30,    16,    64,    65,
      30,   107,    36,    30,   103,    28,    70,    71,    36,   108,
      29,    30,    27,    32,    33,    36,    34,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    31,    12,    13,     3,
      11,    16,    35,     3,     4,     5,     3,     4,     5,    31,
      31,    20,    35,     4,    29,    30,    16,    32,    35,    16,
       0,    36,    11,   106,    62,    -1,    63,    -1,    -1,    29,
      30,    -1,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    41,    43,     0,    14,    30,
      31,    42,    32,    44,     3,     4,     5,    10,    12,    13,
      16,    29,    30,    33,    36,    43,    44,    45,    46,    47,
      51,    52,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    20,    34,    30,    30,
      36,    58,     3,    65,    65,    58,    48,    33,    46,    46,
      46,    36,    28,    27,    21,    22,    23,    24,    25,    26,
      15,    16,    17,    18,    19,    58,    58,    58,    58,    36,
      34,    31,     3,    49,    50,    11,    60,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    35,
      31,    31,    58,    20,    34,    36,    37,    53,    20,    35,
      58,     4,    50,    46,    58,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    48,    47,
      49,    49,    50,    50,    50,    51,    51,    52,    53,    52,
      54,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     1,     1,     1,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     3,     1,     3,     4,     2,     1,     2,     0,     5,
       4,     2,     4,     3,     2,     3,     6,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     3,     4
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
  case 2: /* $@1: %empty  */
#line 109 "parser.y"
                            {
        printf("func main:\n");
    }
#line 1411 "y.tab.c"
    break;

  case 3: /* program: type MAIN LPAREN RPAREN $@1 compound_stmt  */
#line 111 "parser.y"
                    {
        printf("endfunc\n\n");
    }
#line 1419 "y.tab.c"
    break;

  case 4: /* type: INT  */
#line 117 "parser.y"
            { (yyval.str) = strdup("int"); }
#line 1425 "y.tab.c"
    break;

  case 5: /* type: FLOAT  */
#line 118 "parser.y"
            { (yyval.str) = strdup("float"); }
#line 1431 "y.tab.c"
    break;

  case 6: /* type: CHAR  */
#line 119 "parser.y"
            { (yyval.str) = strdup("char"); }
#line 1437 "y.tab.c"
    break;

  case 7: /* type: VOID  */
#line 120 "parser.y"
            { (yyval.str) = strdup("void"); }
#line 1443 "y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 143 "parser.y"
         {
        if (current_type) free(current_type);
        current_type = (yyvsp[0].str);
    }
#line 1452 "y.tab.c"
    break;

  case 19: /* var_declaration: type $@2 declarator_list SEMI  */
#line 146 "parser.y"
                           {
        free(current_type);
        current_type = NULL;
    }
#line 1461 "y.tab.c"
    break;

  case 22: /* declarator: ID  */
#line 158 "parser.y"
       {
        insertSymbol((yyvsp[0].str), current_type, current_scope);
        printf("%s:\n", (yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1471 "y.tab.c"
    break;

  case 23: /* declarator: ID ASSIGN expr  */
#line 163 "parser.y"
                     {
        insertSymbol((yyvsp[-2].str), current_type, current_scope);
        printf("%s:\n", (yyvsp[-2].str));
        emit("", (yyvsp[0].expr).addr, NULL, (yyvsp[-2].str));
        free((yyvsp[-2].str));
    }
#line 1482 "y.tab.c"
    break;

  case 24: /* declarator: ID LBRACK NUM RBRACK  */
#line 169 "parser.y"
                           {
        insertSymbol((yyvsp[-3].str), current_type, current_scope);
        printf("%s[%s]:\n", (yyvsp[-3].str), (yyvsp[-1].str));
        free((yyvsp[-3].str));
        free((yyvsp[-1].str));
    }
#line 1493 "y.tab.c"
    break;

  case 27: /* selection_stmt: if_prefix stmt  */
#line 183 "parser.y"
                                         {
        emit_label((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1502 "y.tab.c"
    break;

  case 28: /* @3: %empty  */
#line 187 "parser.y"
                          {
        char *end_label = new_label();
        emit_goto(end_label);
        emit_label((yyvsp[-2].str));
        (yyval.str) = end_label;
        free((yyvsp[-2].str));
    }
#line 1514 "y.tab.c"
    break;

  case 29: /* selection_stmt: if_prefix stmt ELSE @3 stmt  */
#line 193 "parser.y"
           {
        emit_label((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1523 "y.tab.c"
    break;

  case 30: /* if_prefix: IF LPAREN expr RPAREN  */
#line 200 "parser.y"
                          {
        char *true_label = new_label();
        char *false_label = new_label();
        emit_if((yyvsp[-1].expr).addr, true_label);
        emit_goto(false_label);
        emit_label(true_label);
        (yyval.str) = false_label;
    }
#line 1536 "y.tab.c"
    break;

  case 31: /* iteration_stmt: while_prefix stmt  */
#line 211 "parser.y"
                      {
        // $1 is the while_prefix struct
        emit_goto((yyvsp[-1].loop_labels).start); // Jump back to condition check
        emit_label((yyvsp[-1].loop_labels).end);  // Emit label for after the loop
        free((yyvsp[-1].loop_labels).start);
        free((yyvsp[-1].loop_labels).end);
    }
#line 1548 "y.tab.c"
    break;

  case 32: /* while_prefix: WHILE LPAREN expr RPAREN  */
#line 221 "parser.y"
                             {
        // This action happens after the condition (expr $3) is parsed.
        (yyval.loop_labels).start = new_label();
        (yyval.loop_labels).end = new_label();
        (yyval.loop_labels).inc = NULL; // Not used for while loops

        emit_label((yyval.loop_labels).start); // Label for start of condition check

        char* body_label = new_label();
        emit_if((yyvsp[-1].expr).addr, body_label); // If condition true, goto body
        emit_goto((yyval.loop_labels).end);            // Else, goto end of loop
        emit_label(body_label);       // Label for start of body
    }
#line 1566 "y.tab.c"
    break;

  case 33: /* jump_stmt: RETURN expr SEMI  */
#line 237 "parser.y"
                     {
        emit_return((yyvsp[-1].expr).addr);
    }
#line 1574 "y.tab.c"
    break;

  case 34: /* jump_stmt: RETURN SEMI  */
#line 240 "parser.y"
                  {
        emit_return(NULL);
    }
#line 1582 "y.tab.c"
    break;

  case 35: /* expr: ID ASSIGN expr  */
#line 246 "parser.y"
                   {
        check_declared((yyvsp[-2].str));
        (yyval.expr).addr = (yyvsp[-2].str);
        emit("", (yyvsp[0].expr).addr, NULL, (yyvsp[-2].str));
    }
#line 1592 "y.tab.c"
    break;

  case 36: /* expr: ID LBRACK expr RBRACK ASSIGN expr  */
#line 251 "parser.y"
                                        {
        check_declared((yyvsp[-5].str));
        printf("%s[%s] = %s\n", (yyvsp[-5].str), (yyvsp[-3].expr).addr, (yyvsp[0].expr).addr);
        (yyval.expr).addr = (char *) strdup((yyvsp[0].expr).addr);
        free((yyvsp[-5].str));
    }
#line 1603 "y.tab.c"
    break;

  case 37: /* expr: logical_or_expr  */
#line 257 "parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1611 "y.tab.c"
    break;

  case 38: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 263 "parser.y"
                                        {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("||", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1621 "y.tab.c"
    break;

  case 39: /* logical_or_expr: logical_and_expr  */
#line 268 "parser.y"
                       {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1629 "y.tab.c"
    break;

  case 40: /* logical_and_expr: logical_and_expr AND equality_expr  */
#line 274 "parser.y"
                                       {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("&&", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1639 "y.tab.c"
    break;

  case 41: /* logical_and_expr: equality_expr  */
#line 279 "parser.y"
                    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1647 "y.tab.c"
    break;

  case 42: /* equality_expr: equality_expr EQ relational_expr  */
#line 285 "parser.y"
                                     {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("==", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1657 "y.tab.c"
    break;

  case 43: /* equality_expr: equality_expr NE relational_expr  */
#line 290 "parser.y"
                                       {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("!=", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1667 "y.tab.c"
    break;

  case 44: /* equality_expr: relational_expr  */
#line 295 "parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1675 "y.tab.c"
    break;

  case 45: /* relational_expr: relational_expr LT additive_expr  */
#line 301 "parser.y"
                                     {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("<", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1685 "y.tab.c"
    break;

  case 46: /* relational_expr: relational_expr LE additive_expr  */
#line 306 "parser.y"
                                       {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("<=", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1695 "y.tab.c"
    break;

  case 47: /* relational_expr: relational_expr GT additive_expr  */
#line 311 "parser.y"
                                       {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit(">", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1705 "y.tab.c"
    break;

  case 48: /* relational_expr: relational_expr GE additive_expr  */
#line 316 "parser.y"
                                       {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit(">=", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1715 "y.tab.c"
    break;

  case 49: /* relational_expr: additive_expr  */
#line 321 "parser.y"
                    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1723 "y.tab.c"
    break;

  case 50: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 327 "parser.y"
                                           {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("+", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1733 "y.tab.c"
    break;

  case 51: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 332 "parser.y"
                                              {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("-", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1743 "y.tab.c"
    break;

  case 52: /* additive_expr: multiplicative_expr  */
#line 337 "parser.y"
                          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1751 "y.tab.c"
    break;

  case 53: /* multiplicative_expr: multiplicative_expr MULT unary_expr  */
#line 343 "parser.y"
                                        {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("*", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1761 "y.tab.c"
    break;

  case 54: /* multiplicative_expr: multiplicative_expr DIV unary_expr  */
#line 348 "parser.y"
                                         {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("/", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1771 "y.tab.c"
    break;

  case 55: /* multiplicative_expr: multiplicative_expr MOD unary_expr  */
#line 353 "parser.y"
                                         {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("%", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
    }
#line 1781 "y.tab.c"
    break;

  case 56: /* multiplicative_expr: unary_expr  */
#line 358 "parser.y"
                 {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1789 "y.tab.c"
    break;

  case 57: /* unary_expr: MINUS unary_expr  */
#line 364 "parser.y"
                                  {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("-", (yyvsp[0].expr).addr, NULL, temp);
    }
#line 1799 "y.tab.c"
    break;

  case 58: /* unary_expr: NOT unary_expr  */
#line 369 "parser.y"
                     {
        char *temp = new_temp();
        (yyval.expr).addr = temp;
        emit("!", (yyvsp[0].expr).addr, NULL, temp);
    }
#line 1809 "y.tab.c"
    break;

  case 59: /* unary_expr: primary_expr  */
#line 374 "parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1817 "y.tab.c"
    break;

  case 60: /* unary_expr: postfix_expr  */
#line 377 "parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1825 "y.tab.c"
    break;

  case 61: /* primary_expr: ID  */
#line 383 "parser.y"
       {
        check_declared((yyvsp[0].str));
        (yyval.expr).addr = (yyvsp[0].str);
    }
#line 1834 "y.tab.c"
    break;

  case 62: /* primary_expr: NUM  */
#line 387 "parser.y"
          {
        (yyval.expr).addr = (yyvsp[0].str);
    }
#line 1842 "y.tab.c"
    break;

  case 63: /* primary_expr: FNUM  */
#line 390 "parser.y"
           {
        (yyval.expr).addr = (yyvsp[0].str);
    }
#line 1850 "y.tab.c"
    break;

  case 64: /* primary_expr: LPAREN expr RPAREN  */
#line 393 "parser.y"
                         {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1858 "y.tab.c"
    break;

  case 65: /* postfix_expr: ID LBRACK expr RBRACK  */
#line 399 "parser.y"
                          {
        check_declared((yyvsp[-3].str));
        char *temp = new_temp();
        printf("%s = %s[%s]\n", temp, (yyvsp[-3].str), (yyvsp[-1].expr).addr);
        (yyval.expr).addr = temp;
        free((yyvsp[-3].str));
    }
#line 1870 "y.tab.c"
    break;


#line 1874 "y.tab.c"

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

#line 408 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    printf("========== THREE ADDRESS CODE ==========\n\n");
    yyparse();
    
    return 0;
}
