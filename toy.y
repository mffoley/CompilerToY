
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);

  #include <stdlib.h>
  #include <string.h>
  #include "sym.h"

  defined(char *name)
  { 
    symbol *s = get(name);
    if (s == 0)
    {
      s = put(name);
    }
    else
    {
      printf( "%s is already defined\n", name );
      yyerror("is already defined\n");
    }
  }

  check(char *name)
  { 
    if (get(name) == 0)
    {
      printf( "%s is an undeclared identifier\n", name );
      yyerror("is an undeclared identifier\n");
    }
  }


%}



%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN ELSE FOR RETURN MOD ID INT;
%token AND OR NOT;
%token NUMBER;
%token STRING COMMENT;
%token EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV DOT COMMA ASSIGN LT GT;


%%
input:	/* empty*/
	|input line
	;

line: EOL
	|declaration EOL {printf("= %d\n", $1); }
	;

exp: /* nothing */
 | term { $$ = $1; }
 | SUB exp { $$ = $2 * -1; }
 | exp ADD exp {  $$ = $1 + $3; }
 | exp SUB exp { $$ = $1 - $3; }
 | exp MUL exp {  $$ = $1 * $3; }
 | exp DIV exp {  $$ = $1 / $3; }
 | l_exp { $$ = $1; }
 | OP exp CP {  $$ = $2; }
 ;

term: int_literal | string_literal
; 

int_literal: NUMBER {$$ = $1;} 
;

string_literal : STRING {$$ = $1;} 
;

type : INT | BOOL | STRING
;

declaration: type ID { printf("%s", $2); }

;

return_type : type | VOID 
;

struct_ : STRUCT ID OB declaration CB
;

l_exp : ID | ID DOT l_exp
;

stmt : FOR OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt
  | IF exp THEN stmt
  | IF exp THEN stmt ELSE stmt
  | PRINTF OP STRING CP SEMICOLON
  | RETURN exp SEMICOLON
  | OB stmt_seq  CB
  | type ID SEMICOLON
  | l_exp ASSIGN exp SEMICOLON 
;

stmt_seq : /* empty */
 | stmt stmt_seq
 ;

proc : return_type ID OP declaration CP OB stmt CB


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}
