%{
#include <stdio.h>
int lines=0;
%}

%%


[^\n]   {printf("%s",yytext);}
\n            {
     lines++;printf("\n");
                if(lines>=10){
                    yyterminate();
                }
}
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
