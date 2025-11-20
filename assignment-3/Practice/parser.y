%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

int yylex();
void yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;

int temp_count = 0;
int label_count = 0;
int current_scope = 0;
char *current_type = NULL;

char* new_temp() {
    char *temp = (char*)malloc(20);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

void emit(const char *op, const char *arg1, const char *arg2, const char *result) {
    if (arg1 && arg2)
        printf("%s = %s %s %s\n", result, arg1, op, arg2);
    else if (arg1)
        printf("%s = %s %s\n", result, op, arg1);
    else
        printf("%s %s\n", op, result);
}

void emit_label(const char *label) {
    printf("%s:\n", label);
}

void emit_goto(const char *label) {
    printf("goto %s\n", label);
}

void emit_if(const char *cond, const char *label) {
    printf("if %s goto %s\n", cond, label);
}

void emit_return(const char *val) {
    if (val)
        printf("return %s\n", val);
    else
        printf("return\n");
}

void check_declared(char* name) {
    Symbol* sym = lookupSymbol(name);
    if (sym == NULL) {
        printf("Error: Variable '%s' not declared before use\n", name);
        exit(1);
    }
}


%}

%union {
    char *str;
    struct {
        char *addr;
    } expr;
    struct {
        char *start;
        char *end;
        char *inc;
    } loop_labels;
}

%token <str> ID NUM FNUM
%token INT FLOAT CHAR VOID
%token IF ELSE WHILE RETURN MAIN
%token PLUS MINUS MULT DIV MOD
%token ASSIGN EQ NE LT LE GT GE
%token AND OR NOT
%token LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK
%token SEMI COMMA

%type <expr> expr logical_or_expr logical_and_expr equality_expr 
%type <expr> relational_expr additive_expr multiplicative_expr
%type <expr> unary_expr primary_expr postfix_expr
%type <str> type if_prefix
%type <loop_labels> while_prefix

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGN
%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT UMINUS

%%

program:
    type MAIN LPAREN RPAREN {
        printf("func main:\n");
    } compound_stmt {
        printf("endfunc\n\n");
    }
    ;

type:
    INT     { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    | CHAR  { $$ = strdup("char"); }
    | VOID  { $$ = strdup("void"); }
    ;

compound_stmt:
    LBRACE stmt_list RBRACE
    | LBRACE RBRACE
    ;

stmt_list:
    stmt_list stmt
    | stmt
    ;

stmt:
    expr_stmt
    | compound_stmt
    | selection_stmt
    | iteration_stmt
    | jump_stmt
    | var_declaration
    ;

var_declaration:
    type {
        if (current_type) free(current_type);
        current_type = $1;
    } declarator_list SEMI {
        free(current_type);
        current_type = NULL;
    }
    ;

declarator_list:
    declarator
    | declarator_list COMMA declarator
    ;

declarator:
    ID {
        insertSymbol($1, current_type, current_scope);
        printf("%s:\n", $1);
        free($1);
    }
    | ID ASSIGN expr {
        insertSymbol($1, current_type, current_scope);
        printf("%s:\n", $1);
        emit("", $3.addr, NULL, $1);
        free($1);
    }
    | ID LBRACK NUM RBRACK {
        insertSymbol($1, current_type, current_scope);
        printf("%s[%s]:\n", $1, $3);
        free($1);
        free($3);
    }
    ;

expr_stmt:
    expr SEMI
    | SEMI
    ;

selection_stmt:
    if_prefix stmt %prec LOWER_THAN_ELSE {
        emit_label($1);
        free($1);
    }
    | if_prefix stmt ELSE {
        char *end_label = new_label();
        emit_goto(end_label);
        emit_label($1);
        $<str>$ = end_label;
        free($1);
    } stmt {
        emit_label($<str>4);
        free($<str>4);
    }
    ;

if_prefix:
    IF LPAREN expr RPAREN {
        char *true_label = new_label();
        char *false_label = new_label();
        emit_if($3.addr, true_label);
        emit_goto(false_label);
        emit_label(true_label);
        $$ = false_label;
    }
    ;

iteration_stmt:
    while_prefix stmt {
        // $1 is the while_prefix struct
        emit_goto($1.start); // Jump back to condition check
        emit_label($1.end);  // Emit label for after the loop
        free($1.start);
        free($1.end);
    }
    ;

while_prefix:
    WHILE LPAREN expr RPAREN {
        // This action happens after the condition (expr $3) is parsed.
        $$.start = new_label();
        $$.end = new_label();
        $$.inc = NULL; // Not used for while loops

        emit_label($$.start); // Label for start of condition check

        char* body_label = new_label();
        emit_if($3.addr, body_label); // If condition true, goto body
        emit_goto($$.end);            // Else, goto end of loop
        emit_label(body_label);       // Label for start of body
    }
    ;

jump_stmt:
    RETURN expr SEMI {
        emit_return($2.addr);
    }
    | RETURN SEMI {
        emit_return(NULL);
    }
    ;

expr:
    ID ASSIGN expr {
        check_declared($1);
        $$.addr = $1;
        emit("", $3.addr, NULL, $1);
    }
    | ID LBRACK expr RBRACK ASSIGN expr {
        check_declared($1);
        printf("%s[%s] = %s\n", $1, $3.addr, $6.addr);
        $$.addr = (char *) strdup($6.addr);
        free($1);
    }
    | logical_or_expr {
        $$ = $1;
    }
    ;

logical_or_expr:
    logical_or_expr OR logical_and_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("||", $1.addr, $3.addr, temp);
    }
    | logical_and_expr {
        $$ = $1;
    }
    ;

logical_and_expr:
    logical_and_expr AND equality_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("&&", $1.addr, $3.addr, temp);
    }
    | equality_expr {
        $$ = $1;
    }
    ;

equality_expr:
    equality_expr EQ relational_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("==", $1.addr, $3.addr, temp);
    }
    | equality_expr NE relational_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("!=", $1.addr, $3.addr, temp);
    }
    | relational_expr {
        $$ = $1;
    }
    ;

relational_expr:
    relational_expr LT additive_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("<", $1.addr, $3.addr, temp);
    }
    | relational_expr LE additive_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("<=", $1.addr, $3.addr, temp);
    }
    | relational_expr GT additive_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit(">", $1.addr, $3.addr, temp);
    }
    | relational_expr GE additive_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit(">=", $1.addr, $3.addr, temp);
    }
    | additive_expr {
        $$ = $1;
    }
    ;

additive_expr:
    additive_expr PLUS multiplicative_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("+", $1.addr, $3.addr, temp);
    }
    | additive_expr MINUS multiplicative_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("-", $1.addr, $3.addr, temp);
    }
    | multiplicative_expr {
        $$ = $1;
    }
    ;

multiplicative_expr:
    multiplicative_expr MULT unary_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("*", $1.addr, $3.addr, temp);
    }
    | multiplicative_expr DIV unary_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("/", $1.addr, $3.addr, temp);
    }
    | multiplicative_expr MOD unary_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("%", $1.addr, $3.addr, temp);
    }
    | unary_expr {
        $$ = $1;
    }
    ;

unary_expr:
    MINUS unary_expr %prec UMINUS {
        char *temp = new_temp();
        $$.addr = temp;
        emit("-", $2.addr, NULL, temp);
    }
    | NOT unary_expr {
        char *temp = new_temp();
        $$.addr = temp;
        emit("!", $2.addr, NULL, temp);
    }
    | primary_expr {
        $$ = $1;
    }
    | postfix_expr {
        $$ = $1;
    }
    ;

primary_expr:
    ID {
        check_declared($1);
        $$.addr = $1;
    }
    | NUM {
        $$.addr = $1;
    }
    | FNUM {
        $$.addr = $1;
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    ;

postfix_expr:
    ID LBRACK expr RBRACK {
        check_declared($1);
        char *temp = new_temp();
        printf("%s = %s[%s]\n", temp, $1, $3.addr);
        $$.addr = temp;
        free($1);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    printf("========== THREE ADDRESS CODE ==========\n\n");
    yyparse();
    
    return 0;
}