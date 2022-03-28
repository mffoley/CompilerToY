
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
%token NUMBER;
%token STRING COMMENT;
%token EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV DOT COMMA ASSIGN LT GT;


%%
input:	/* empty*/
	|input line {}
	;

line: EOL
	|proc EOL {}
	;

term: int_literal | string_literal | bool_literal
; 

int_literal: NUMBER {} 
;

string_literal : STRING {} 
;

bool_literal : TRUE {} | FALSE {} 
;

type : INT {}
 | BOOL {}
 | STRING {}
;

declaration: type ID { add_to_scope($2, 4); }
|declaration COMMA declaration
;

exp:
;

return_type : type | VOID 
;

struct_ : STRUCT ID OB declaration CB { } 
;

l_exp : ID | ID DOT l_exp
;

stmt : FOR OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt
  | IF exp THEN stmt
  | IF exp THEN stmt ELSE stmt
  | PRINTF OP STRING CP SEMICOLON
  | RETURN exp SEMICOLON
  | OB stmt_seq  CB
  | type ID { add_to_scope($2, 4); }
  | l_exp ASSIGN exp SEMICOLON 
;


stmt_seq : /* empty */
 | stmt stmt_seq
 ;

proc : return_type ID OP declaration CP OB stmt CB { }
;


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}
