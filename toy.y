%define parse.error verbose

%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);

  #include <stdlib.h>
  #include <string.h>
  #include "sym.h"

  int printg(){
    printf("blah");
    return 0;
  }


%}

%union{
  char* str;
  int val;
}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN ELSE FOR RETURN MOD INT;
%token AND OR NOT;
%token <str> ID;
%token <val> NUMBER;
%token STRING COMMENT;
%token EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV DOT COMMA ASSIGN LT GT;

%type <val> type;
%type <val> declaration;
%type <val> struct_;
%type <val> proc;
%type <val> l_exp;
%type <val> Name;
%type <val> exp;
%type <val> int_literal;
%type <val> stmt;
%type <val> stmt_seq;




%%
input:	/* empty*/
	|input line {}
	;

line: EOL
	|pgm EOL {}
	;

pgm2: 
| proc pgm2 { }
| struct_ pgm2 { }
;

pgm: proc pgm2 { if($1 == 1){printf("-----------------------------Valid Proc\n");} else {printf("-----------------------------Invalid Proc\n"); } }
| struct_ { if($1 == 1){printf("-----------------------------Valid Struct\n");} else {printf("-----------------------------Invalid Struct\n"); } }
;


exp: /* nothing */ { $$ = 1; }
 | int_literal { $$ = $1; }
 ;

int_literal: NUMBER {$$ = $1;} 
;

type : INT { $$ = 4; }
 | BOOL { $$ = 5; }
 | STRING { $$ = 6; }
 | ID { }
;

declaration: type ID { if($1 != 0) { if(add_to_scope($1, $2) == 1){ $$ = 1; } else { $$ = 0;} } else {$$ = 0;}}
| declaration COMMA declaration { if($1 == 0 || $3 == 0) { $$ = 0; } else {$$ = 1;}  } 
;


return_type : type | VOID 
;

struct_ : STRUCT Name OB declaration CB { new_scope(); if($4 == 1 && $2 == 1){ $$ = 1; } else {$$ = 0;}  } 
; 

l_exp : ID  {  }
| ID DOT l_exp { }
;

intern_scope_then: THEN { add_internal_scope(); }
;

intern_scope_else: ELSE { delete_scope(); add_internal_scope(); }
;

stmt : FOR OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt 
  | IF OP exp CP intern_scope_then stmt { delete_scope(); if($6 == 0) { $$ = 0; } else { $$ = 1; } }
  | IF OP exp CP intern_scope_then stmt intern_scope_else stmt { delete_scope(); if($6 == 0 || $8 == 0) { $$ = 0; } else { $$ = 1; } }
  | PRINTF OP STRING CP SEMICOLON { $$ = 1; }
  | RETURN exp SEMICOLON  { $$ = 1; }
  | OB stmt_seq CB { $$ = $2; }
  | type ID SEMICOLON { if(add_to_scope($1, $2) == 0) { $$ = 0; } else { $$ = 1; } }
  | l_exp ASSIGN exp SEMICOLON {}
;

stmt_seq : /* empty */
 | stmt stmt_seq { if($1 == 0 || $2 == 0) { $$ = 0; } else { $$ = 1;}}
 ;

Name : ID { if(add_name($1) == 1){ $$ = 1; } else {$$ = 0;} }
;

proc : return_type Name OP declaration CP OB stmt_seq CB { print_symbol_table(); new_scope(); if($4 == 1 && $2 == 1 && $7 == 1){ $$ = 1; } else {$$ = 0;}}
;

%%

main()
{
    extern FILE *yyin, yyout;
    
    yyin = fopen("Input.txt", "r");

    int parse = yyparse();
    // if(parse == 0) printf ("Error\n");
    // else printf("Valid");
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}
