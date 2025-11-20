%{
#include <stdio.h>
int lines=0;
%}

%%


.   {printf("%s",yytext);}
%%

int main(int argc, char *argv[]) {
    // while(lines<10)
        yylex();
    // }
    return 0;
}

int yywrap() {

    return 1;
}
