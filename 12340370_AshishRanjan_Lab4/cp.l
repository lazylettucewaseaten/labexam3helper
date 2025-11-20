%{
#include<stdio.h>
#include<stdlib.h>
FILE *yyin,*yyout;
%}


%%
. {fprintf(yyout,"%s",yytext);}
%%

int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Error in usage pass it like cp [source] [dest]\n");
        return 0;
    }
    yyin=fopen(argv[1],"r");
    yyout=fopen(argv[2],"w");
    
    // yyout=dest;
    yylex();
    fclose(yyin);fclose(yyout);
    return 0;
}

int yywrap(){
    return 1;
}