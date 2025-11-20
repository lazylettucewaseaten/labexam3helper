%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
int yylex();             // Prototype for the lexer function
void yyerror(const char *);
char currentType[20];

int temp_count=0;
int label_count=1;

char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}
char* new_Label() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "l%d", label_count++);
    return temp;
}



%}

%union{
    char * str;
}
%token<str> FNUM NUM IDENTIFIER TVALUE FVALUE
%token INT FLOAT EE GE LE LT GT OR AND NOT
%type <str>  term Expr BooleanExpr


%left '+' '-'
%left '*' '/'


%nonassoc NOT           // Unary NOT has highest precedence and is non-associative (often treated as right-associative in expression rules)
%left AND               // Logical AND (&&)
%left OR
%left LE GE LT GT       // Relational operators
%left EE                // Equality operator (==)


%%
program : stmts ;

stmts: stmts stmt 
        |stmt;
stmt : declStmt | AssignStmt | BooleanExpr ';'   ; 


declStmt : type idlist ';' ;

type :     INT {strcpy(currentType ,"int");};  
    | FLOAT {strcpy(currentType , "float");};

idlist : idlist ',' term {
        insertSymbol($3 ,currentType ,0); // Left recursion is preffered  kyuki ussee line mai aaenge
    }
    | term { 
        insertSymbol($1 ,currentType ,0);
    }
    ;

term : IDENTIFIER {$$ = $1;};

AssignStmt : IDENTIFIER '=' Expr ';' { 
     Symbol* sym =lookupSymbol($1);
    if(sym == NULL)
    {
        printf("Identifier Not declared\n");
    }
    printf("%s = %s\n" ,$1 ,$3);
} ;


Expr : 
    Expr '+' Expr{
        char * temp = new_temp();
        printf("%s = %s + %s\n" ,temp,$1 ,$3);
        $$ =temp;
    } 
    | Expr '-' Expr{
        char * temp = new_temp();
        printf("%s = %s - %s\n" ,temp,$1 ,$3);
        $$ =temp;
    }  
    | Expr '*' Expr{
        char * temp = new_temp();
        printf("%s = %s * %s\n" ,temp,$1 ,$3);
        $$ =temp;
    }  
    | Expr '/' Expr{
        char * temp = new_temp();
        printf("%s = %s / %s\n" ,temp,$1 ,$3);
        $$ =temp;
    }  
    | IDENTIFIER {
         Symbol* sym =lookupSymbol($1);
    if(sym == NULL)
    {
        printf("Identifier Not declared\n");
    }
    $$ = $1;
    }
    ;

BooleanExpr : BooleanExpr AND BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                printf("%s : %s = %s and %s \n " ,lt ,temp ,$1 ,$3);
                $$ = temp;
                
             }
             | BooleanExpr OR BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                printf("%s : %s = %s or %s \n " ,lt ,temp ,$1 ,$3);
                $$ = temp;
                
             }
             | NOT BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                printf("%s : %s = not %s \n " ,lt ,temp ,$2);
                $$ = temp;
                
             }
            | BooleanExpr EE BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                char * lt1 = new_Label();
                char * lt2 = new_Label();
                char * lt3 = new_Label();
                char * lt4 = new_Label();
                label_count--;
                printf("%s : if %s == %s  goto %s \n " ,lt ,$1 ,$3 ,lt3);
                printf("%s : %s = 0 \n " ,lt1 ,temp);
                printf("%s : goto %s \n " ,lt2 ,lt4);
                printf("%s : %s = 1 \n " ,lt3 ,temp );
                $$ = temp;
                
             }
            | BooleanExpr LE BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                char * lt1 = new_Label();
                char * lt2 = new_Label();
                char * lt3 = new_Label();
                char * lt4 = new_Label();
                label_count--;
                printf("%s : if %s <= %s  goto %s \n " ,lt ,$1 ,$3 ,lt3);
                printf("%s : %s = 0 \n " ,lt1 ,temp);
                printf("%s : goto %s \n " ,lt2 ,lt4);
                printf("%s : %s = 1 \n " ,lt3 ,temp );
                $$ = temp;
                
             }
            | BooleanExpr GE BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                char * lt1 = new_Label();
                char * lt2 = new_Label();
                char * lt3 = new_Label();
                char * lt4 = new_Label();
                label_count--;
                printf("%s : if %s >= %s  goto %s \n " ,lt ,$1 ,$3 ,lt3);
                printf("%s : %s = 0 \n " ,lt1 ,temp);
                printf("%s : goto %s \n " ,lt2 ,lt4);
                printf("%s : %s = 1 \n " ,lt3 ,temp );
                $$ = temp;
                
             }
            | BooleanExpr GT BooleanExpr{
                 
               char * temp = new_temp();
                char * lt = new_Label();
                char * lt1 = new_Label();
                char * lt2 = new_Label();
                char * lt3 = new_Label();
                char * lt4 = new_Label();
                label_count--;
                printf("%s : if %s > %s  goto %s \n " ,lt ,$1 ,$3 ,lt3);
                printf("%s : %s = 0 \n " ,lt1 ,temp);
                printf("%s : goto %s \n " ,lt2 ,lt4);
                printf("%s : %s = 1 \n " ,lt3 ,temp );
                $$ = temp;
                
             }
            | BooleanExpr LT BooleanExpr{
                 
                char * temp = new_temp();
                char * lt = new_Label();
                char * lt1 = new_Label();
                char * lt2 = new_Label();
                char * lt3 = new_Label();
                char * lt4 = new_Label();
                label_count--;
                printf("%s : if %s < %s  goto %s \n " ,lt ,$1 ,$3 ,lt3);
                printf("%s : %s = 0 \n " ,lt1 ,temp);
                printf("%s : goto %s \n " ,lt2 ,lt4);
                printf("%s : %s = 1 \n " ,lt3 ,temp );
                $$ = temp;
                
             }
             |TVALUE {
                $$ = $1;
                char * temp = new_temp();
                char * lt = new_Label();
                printf("%s : %s  = %s\n" ,lt ,temp ,$1);
                }
             |FVALUE {
                $$ = $1;
                char * temp = new_temp();
                char * lt = new_Label();
                printf("%s : %s  = %s\n" ,lt ,temp ,$1);
                }
            | IDENTIFIER {
                
                    Symbol* sym =lookupSymbol($1);
                if(sym == NULL)
                {
                    printf("Identifier Not declared\n");
                }
                $$ = $1;
                
            }
             ;
%%


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression (e.g., a = b + c * d):\n");
    yyparse();
    return 0;
}