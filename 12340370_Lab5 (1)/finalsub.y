%{
#include <stdio.h>
#include <stdlib.h>
int flag=0;
%}

%token int_ float_ double_ char_ var comma colon  integer equate add sub mul DIV  lbracket rbracket for_ incre decre lt gt lte gte eqe ne lbrace rbrace

%left lt gt lte gte eqe ne
%left add sub
%left mul DIV
%right equate
%left incre decre

%%

mainprogram: firstcall
	   |
	   ;
	   
	   
firstcall:
	firstcall state
	| state
	;
	
state:
	declaration
	| ass_stmt colon{
		printf("\n valid assignment statement\n");
	}
	| for_statement
	;
	
	

declaration: dtype vlist colon
           {
               printf("valid variable declaration\n");
           }
           ;

dtype: int_
        | float_
        | double_
        | char_
        ;

vlist: var
             | vlist comma var
             ;


ass_stmt: var equate expr
               ;





for_statement:
    for_ lbracket for_expr colon for_expr colon for_expr rbracket body
        {
            printf("valid for loop statement\n");
        }
    ;

for_expr:
    expr
    | ass_stmt
    | 
    ;

body:
    ass_stmt colon
    
    ;

expr:
    expr add expr
    | expr sub expr
    | expr mul expr
    | expr DIV expr
    | expr lt expr
    | expr gt expr
    | expr lte expr
    | expr gte expr
    | expr eqe expr
    | expr ne expr
    | lbracket expr rbracket
    | var
    | integer
    | var incre
    | var decre
    | incre var
    | decre var
    ;



%%








void main() {
    printf("enter your code:\n");
    yyparse();
}


void  yyerror(){
	flag=1;
	printf("\nSyntax eror\n");
}

