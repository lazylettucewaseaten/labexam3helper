%{
#include "y.tab.h"
%}


%%
"="                     { return equate; }
"/"                     { return DIV; }
"*"                     { return mul; }
"-"                     { return sub; }
"+"                     { return add; }
"("                     { return lbracket; }
")"                     { return rbracket; }
"for" 			{ return for_; }
"++" {return incre;}
"--" {return decre;}
"<" {return lt;}
">" {return gt;}
"<=" {return lte;}
">=" {return gte;}
"==" {return eqe;}
"!=" {return ne;}
"{" {return lbrace;}
"}" {return rbrace;}
"int"       { return int_; }
"float"     { return float_; }
"double"    { return double_; }
"char"      { return char_; }
","         { return comma; }
";"         { return colon; }
[a-zA-Z_][a-zA-Z0-9_]*  { return var; }
[0-9]+                  { return integer; }
[ \t\n]     \
.           { return yytext[0]; }
%%


int yywrap(){
	return 1;
}
