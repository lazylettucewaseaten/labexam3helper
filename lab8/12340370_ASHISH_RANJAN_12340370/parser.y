%{
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

%}

%union{
    int num;
    float fnum;
    char *str;
}

%token<num> NUM
%token<fnum> FNUM
%token<str> ID
%token INT FLOAT TRUE FALSE NOT AND OR
%token LE GE EQ NE LT GT

%type<str> expr term fact boolean rel datatype idlist

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left '+' '-'
%left '*' '/'
%right NOT
%right UMINUS

%%

prog:
    stmtlist
    ;

stmtlist: stmtlist stmt | stmt ;

stmt: decl | var_asgn | boolean_stmt ;

decl:
    datatype idlist ';' ;

datatype: INT {$$=strdup("int");} | FLOAT {$$=strdup("float");} ;

idlist: idlist ',' ID {
        insertSymbol($3,$<str>0,0);
        $$=$3;
    } | ID {
        insertSymbol($1,$<str>0,0);
        $$=$1;
    }
    ;

var_asgn:
    ID '=' expr ';' {
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
            printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        printf("%s=%s\n",$1,$3);

    } | ID '=' boolean ';' {
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
            printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        printf("%s=%s\n",$1,$3);
    }
    ;

boolean_stmt:
    boolean ';' {
        printf("Result:%s\n",$1);
    }
    ;

expr:
    expr '+' term {
        char *temp=new_temp();
        printf("%s=%s+%s\n",temp,$1,$3);
        $$=temp;
    } | expr '-' term {
        char *temp=new_temp();
        printf("%s=%s-%s\n",temp,$1,$3);
        $$=temp;
    } | term {
        $$=$1;
    }
    ;

term:
    term '*' fact {
        char *temp=new_temp();
        printf("%s=%s*%s\n",temp,$1,$3);
        $$=temp;
    } | term '/' fact {
        char *temp=new_temp();
        printf("%s=%s/%s\n",temp,$1,$3);
        $$=temp;
    } | fact {
        $$=$1;
    } ;

fact:
    '(' expr ')'{
        $$=$2;
    } | '-' fact %prec UMINUS {
        char *temp=new_temp();
        printf("%s=-%s\n",temp,$2);
        $$=temp;
    } | ID {
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
            printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        $$=$1;
    } | NUM  {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%d",$1);
        $$=temp;
    } | FNUM {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%.2f",$1);
        $$=temp;
    }
    ;

boolean:
    boolean OR boolean {
        char *temp=new_temp();
        printf("%s=%s||%s\n",temp,$1,$3);
        $$=temp;
    } | boolean AND boolean {
        char *temp=new_temp();
        printf("%s=%s&&%s\n",temp,$1,$3);
        $$=temp;
    } | NOT boolean {
        char *temp=new_temp();
        printf("%s=!%s\n",temp,$2);
        $$=temp;
    } | rel
    {
        $$=$1;
    } | TRUE
    {
        $$=strdup("true");
    } | FALSE
    {
        $$=strdup("false");
    } | '(' boolean ')'
    {
        $$=$2;
    }
    ;

rel:
    expr LT expr
    {
        char *temp=new_temp();
        printf("%s=%s<%s\n",temp,$1,$3);
        $$=temp;
    }| expr GT expr
    {
        char *temp=new_temp();
        printf("%s=%s>%s\n",temp,$1,$3);
        $$=temp;
    }| expr LE expr
    {
        char *temp=new_temp();
        printf("%s=%s<=%s\n",temp,$1,$3);
        $$=temp;
    }| expr GE expr
    {
        char *temp=new_temp();
        printf("%s=%s>=%s\n",temp,$1,$3);
        $$=temp;
    }| expr EQ expr
    {
        char *temp=new_temp();
        printf("%s=%s==%s\n",temp,$1,$3);
        $$=temp;
    }| expr NE expr
    {
        char *temp=new_temp();
        printf("%s=%s!=%s\n",temp,$1,$3);
        $$=temp;
    }
    ;

%%

void yyerror(const char *s){
    fprintf(stderr,"Error:%s\n",s);
}

int main(int argc,char **argv){
    printf("Three Address Code Generator\n");
    if(argc>1){
        FILE *file=fopen(argv[1],"r");
        if(!file){
            fprintf(stderr,"cannot openfile '%s'\n",argv[1]);
            return 1;
        }
        yyin=file;
    }else{
        printf("Enter your code :\n\n");
    }
    yyparse();
    if(argc>1) fclose(yyin);
}

