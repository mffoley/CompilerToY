
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);
%}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN ELSE FOR RETURN MOD ID INT;
%token AND OR NOT;
%token NUMBER;
%token STRING COMMENT;
%token EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV DOT ASSIGN LT GT;


%%
input:	/* empty*/
	|input line
	;

line: EOL
	|struct_ EOL { printf("= %d\n", $1); }
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

type : INT | BOOL | STRING
;

declaration: /* nothing */
  |type ID declaration
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
  | l_exp ASSIGN exp SEMICOLON { sym[$1]=$3;}
;

stmt_seq : 
 | stmt stmt_seq
 ;


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n",msg);
  return 0;
}
