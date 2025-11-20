%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);

int temp_count = 0;
int label_count = 0;





char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

char* new_label() {
    char *label = (char*)malloc(10);
    sprintf(label, "L%d", label_count++);
    return label;
}

%}

%union {
    int num;
    float fnum;
    char *str;
    struct {
        char *true_list;
        char *false_list;
        char *code;
    } bexpr;
    struct {
        int count;
    } args;
}

%token <num> NUM
%token <fnum> FNUM
%token <str> ID





%token INT FLOAT TRUE FALSE NOT AND OR
%token IF THEN ELSE WHILE DO
%token LE GE EQ NE LT GT





%type <str> expr term factor relexpr type idlist
%type <bexpr> boolexpr
%type <args> argnlist

%left OR
%left AND
%left EQ NE




%left LT GT LE GE
%left '+' '-'
%left '*' '/'
%right NOT
%right UMINUS

%%

program:
    stmts
    ;

stmts:
    stmts stmt
    | stmt
    ;

stmt:
    decln
    | assign
    | if_stmt
    | whilesmt
    | boolsmt
    | fnc_call
    ;

decln:
    type idlist ';'
    {
    }
    ;

type:
    INT     { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    ;










idlist:
    idlist ',' ID
    {
        insertSymbol($3, $<str>0, 0);
        $$ = $3;
    }
    | ID
    {
        insertSymbol($1, $<str>0, 0);
        $$ = $1;
    }
    ;

assign:
    ID '=' expr ';'
    {
        Symbol* sym = lookupSymbol($1);
        if (sym == NULL) {
            printf("Error: Variable '%s' not declared!\n", $1);
            exit(1);
        }
        printf("%s = %s\n", $1, $3);
    }
    ;










if_stmt:
    IF '(' boolexpr ')' THEN '{' stmts '}'
    {
        char *l_true = new_label();
        char *l_false = new_label();
        char *l_next = new_label();

        printf("if %s goto %s\n", $3.code, l_true);
        printf("goto %s\n", l_false);
        printf("%s:\n", l_true);
        printf("goto %s\n", l_next);
        printf("%s:\n", l_false);
        printf("%s:\n", l_next);
        printf("\n");
    }







    | IF '(' boolexpr ')' THEN '{' stmts '}' ELSE '{' stmts '}'
    {
        char *l_true = new_label();
        char *l_false = new_label();
        char *l_next = new_label();

        printf("if %s goto %s\n", $3.code, l_true);
        printf("goto %s\n", l_false);
        printf("%s:\n", l_true);
        printf("goto %s\n", l_next);
        printf("%s:\n", l_false);
        printf("%s:\n", l_next);
        printf("\n");
    }
    ;





whilesmt:
    WHILE '(' boolexpr ')' DO '{' stmts '}'
    {
        char *l_begin = new_label();
        char *l_true = new_label();
        char *l_false = new_label();




        printf("%s:\n", l_begin);
        printf("if %s goto %s\n", $3.code, l_true);
        printf("goto %s\n", l_false);
        printf("%s:\n", l_true);
        printf("goto %s\n", l_begin);
        printf("%s:\n", l_false);
        printf("\n");
    }
    ;











boolsmt:
    boolexpr ';'
    {
        printf("if %s goto %s\n", $1.code, $1.true_list);
        printf("goto %s\n", $1.false_list);
        printf("%s:\n", $1.true_list);
        printf("%s:\n", $1.false_list);
        printf("\n");
    }
    ;

expr:
    expr '+' term
    {
        char *temp = new_temp();
        printf("%s = %s + %s\n", temp, $1, $3);
        $$ = temp;
    }





    | expr '-' term
    {
        char *temp = new_temp();
        printf("%s = %s - %s\n", temp, $1, $3);
        $$ = temp;
    }
    | term
    {
        $$ = $1;
    }
    ;

term:
    term '*' factor
    {
        char *temp = new_temp();
        printf("%s = %s * %s\n", temp, $1, $3);
        $$ = temp;
    }
    | term '/' factor
    {
        char *temp = new_temp();
        printf("%s = %s / %s\n", temp, $1, $3);
        $$ = temp;
    }
    | factor
    {
        $$ = $1;
    }
    ;

factor:
    '(' expr ')'
    {
        $$ = $2;
    }
    | '-' factor %prec UMINUS
    {
        char *temp = new_temp();
        printf("%s = -%s\n", temp, $2);
        $$ = temp;
    }
    | ID
    {
        Symbol* sym = lookupSymbol($1);
        if (sym == NULL) {
            printf("Error: Variable '%s' not declared!\n", $1);
            exit(1);
        }
        $$ = $1;
    }
    | NUM
    {
        char *temp = (char*)malloc(20);
        sprintf(temp, "%d", $1);
        $$ = temp;
    }
    | FNUM
    {
        char *temp = (char*)malloc(20);
        sprintf(temp, "%.2f", $1);
        $$ = temp;
    }
    ;

boolexpr:
    boolexpr OR boolexpr
    {
        printf("// Short-circuit OR\n");
        printf("if %s goto %s\n", $1.code, $1.true_list);
        printf("if %s goto %s\n", $3.code, $3.true_list);
        printf("goto %s\n", $3.false_list);

        $$.true_list = new_label();
        $$.false_list = new_label();
        $$.code = new_temp();
    }




    | boolexpr AND boolexpr
    {
        printf("// Short-circuit AND\n");
        printf("if %s goto %s\n", $1.code, $3.true_list);
        printf("goto %s\n", $1.false_list);

        $$.true_list = new_label();
        $$.false_list = new_label();
        $$.code = new_temp();
    }






    | NOT boolexpr
    {
        $$.true_list = $2.false_list;
        $$.false_list = $2.true_list;
        $$.code = $2.code;
    }
    | relexpr
    {
        $$.true_list = new_label();
        $$.false_list = new_label();
        $$.code = $1;
        printf("if %s goto %s\n", $1, $$.true_list);
        printf("goto %s\n", $$.false_list);
    }




    | TRUE
    {
        $$.true_list = new_label();
        $$.false_list = new_label();
        $$.code = "true";
        printf("goto %s\n", $$.true_list);
    }
    | FALSE
    {
        $$.true_list = new_label();
        $$.false_list = new_label();
        $$.code = "false";
        printf("goto %s\n", $$.false_list);
    }
    | '(' boolexpr ')'
    {
        $$ = $2;
    }
    ;

relexpr:







    expr LT expr
    {
        char *temp = new_temp();
        printf("%s = %s < %s\n", temp, $1, $3);
        $$ = temp;
    }
    | expr GT expr
    {
        char *temp = new_temp();
        printf("%s = %s > %s\n", temp, $1, $3);
        $$ = temp;
    }


    
    | expr LE expr
    {
        char *temp = new_temp();
        printf("%s = %s <= %s\n", temp, $1, $3);
        $$ = temp;
    }





    | expr GE expr
    {
        char *temp = new_temp();
        printf("%s = %s >= %s\n", temp, $1, $3);
        $$ = temp;
    }
    | expr EQ expr
    {
        char *temp = new_temp();
        printf("%s = %s == %s\n", temp, $1, $3);
        $$ = temp;
    }





    | expr NE expr
    {
        char *temp = new_temp();
        printf("%s = %s != %s\n", temp, $1, $3);
        $$ = temp;
    }
    ;

fnc_call:
    ID '(' argnlist ')' ';'
    {
        printf("call %s, %d\n", $1, $3.count);
    }
    ;

argnlist:
    expr
    {
        printf("param %s\n", $1);
        $$.count = 1;
    }
    | argnlist ',' expr
    {
        printf("param %s\n", $3);
        $$.count = $1.count + 1;
    }
    | /* empty */
    {
        $$.count = 0;
    }
    ;

%%









void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char **argv) {
    printf("Three Address Code Generator \n\n");

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
            return 1;
        }
        yyin = file;
        printf("Reading from file: %s\n\n", argv[1]);
    } else {
        printf("Enter your code (Ctrl+D to end):\n\n");
    }

    yyparse();

    if (argc > 1) fclose(yyin);
    return 0;
}
