%{
#include<stdio.h>
%}
%%
"void"             {printf("Keyword : %s\n" ,yytext);}
"int"               {printf("Keyword : %s\n" ,yytext);}
"double"                {printf("Keyword : %s\n" ,yytext);}
"bool"                  {printf("Keyword : %s\n" ,yytext);}
"string"                    {printf("Keyword : %s\n" ,yytext);}
"extends"                   {printf("Keyword : %s\n" ,yytext);}
"implements"                    {printf("Keyword:%s" ,yytext);}
"for"                   {printf("Keyword : %s\n" ,yytext);}
"while"                 {printf("Keyword : %s\n" ,yytext);}
"ReadInteger"                   {printf("Keyword : %s\n" ,yytext);}
"ReadLine"                  {printf("Keyword : %s\n" ,yytext);}
"class"                 {printf("Keyword : %s\n" ,yytext);}
"interface"                     {printf("Keyword : %s\n" ,yytext);}
"if"                    {printf("Keyword : %s\n" ,yytext);}
"else"                  {printf("Keyword : %s\n" ,yytext);}
"return"                    {printf("Keyword : %s\n" ,yytext);}
"null"                  {printf("Keyword : %s\n" ,yytext);}
"this"                  {printf("Keyword : %s\n" ,yytext);}
"break"                     {printf("Keyword : %s\n" ,yytext);}
"New"                   {printf("Keyword : %s\n" ,yytext);}
"NewArray"                  {printf("Keyword : %s\n" ,yytext);}
"Print"                 {printf("Keyword : %s\n" ,yytext);}

("true"|"false") {printf("Boolean : %s\n",yytext);}

[0-9]+|0[xX][a-fA-F0-9]+ {printf("Integer : %s\n",yytext);}
 
[0-9]+\.[0-9]+([Ee][+-]?[0-9]+)? {printf("Double : %s\n",yytext);}

\.[0-9]+([Ee][-+]?[0-9]+)? {printf("(%s) is not a valid double as there should be a number before the dot\n", yytext);} 



[a-zA-Z][a-zA-Z0-9_]*      {if(strlen(yytext)<=31) printf("Identifier : %s\n",yytext);
    else{
        printf("Too long identifier not permitted more than 31 %s\n",yytext);
    }
    }


[_][a-zA-Z0-9_]* {printf("(%s) this is not a valid identifier \n", yytext);} 

\"[^\n\"]*\" {printf("%s String\n",yytext);}

"=="|"!="|"<="|">="|"+"|"-"|"*"|"/"|"%"|"<"|">"|"="|"|"|"&&"|"||"|"!"|";"|","|"."|"[]"|"()" {printf("Operators : %s\n", yytext);}

"//"[^\n]* {printf("Single Line Comments : %s\n",yytext);}

"/*"([^*]|\*+[^*/])*\*+"/"  { printf("Multiline Comment: %s\n", yytext);}

[ \n\t]+               

   
%%


int yywrap(){
    return 1;
}
int main(){
    yylex();
    return 0;
}


//our  assignment made by bhomia and ranjan