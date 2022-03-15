
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
%token ADD SUB MUL DIV ASSIGN LT GT;


%%
input:	/* empty*/
	|input line
	;

line: EOL
	|exp EOL { printf("= %d\n", $1); }
	;

exp: /* nothing */
 | term { $$ = $1; }
 | SUB exp { $$ = $2 * -1; }
 | exp ADD exp {  $$ = $1 + $3; }
 | exp SUB exp { $$ = $1 - $3; }
 | exp MUL exp {  $$ = $1 * $3; }
 | exp DIV exp {  $$ = $1 / $3; }
 | OP exp CP {  $$ = $2; }
 ;

term: int_literal; 

int_literal: NUMBER {$$ = $1;} ;


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n",msg);
  return 0;
}
