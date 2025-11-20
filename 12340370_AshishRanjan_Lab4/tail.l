%{
#include <stdio.h>
#include<stdlib.h>
int flag=0;
int total=0;
%}

%%


[^\n]   {
        if(!flag){

        }
        else{
        if(total<=0){
            printf("%s",yytext);
        }
        }
        }
\n   {
        if(!flag){
            total++;
        }
        else{

        if(flag  && total){
            total--;
        }
        if(total<=0){
            printf("%s",yytext);
        }
        }
    }
%%

int main(int argc, char *argv[]) {
    // while(lines<10)
 
        yylex();
        total-=10;
        flag=1;
        rewind(yyin);
    // }
        yylex();
    return 0;
}

int yywrap() {

    return 1;
}
