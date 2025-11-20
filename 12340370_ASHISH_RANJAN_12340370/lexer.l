%{
	#include<stdio.h> 
	#include<string.h> 
	#include "y.tab.h"
%}

%%
int     { return INT; }
>	{return GT;}
=	{return EQ;}
<	{return LT;}
!	{return NOT;}
+	{return ADD;}
-	{return SUB;}
*	{return MUL;}
/	{return DIV;}
[%]	{return MODULO;}
float   { return FLOAT; }
true {return TRUE_;}
false {return FALSE_;}
| {return OR;}
& {return AND;}
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }
;       { return ';'; }
,       { return ','; }
[ \t\n] ;
.       ;
%%
//char    { return CHAR; }

int yywrap() {
    return 1;
}

