
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);
%}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN  ELSE FOR RETURN MOD ID;
%token AND OR NOT;
%token INT;
%token STRING COMMENT;
%token WHITESPACE EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV ASSIGN LT GT;



%%

calclist: /* nothing */  
 | calclist exp EOL { printf("= %d\n", $2); }
 ;

exp: factor      
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 ;

 factor: term       
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: INT  
 | OP exp CP { $$ = $2; }
;


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  printf(stderr);
  return 0;
}
