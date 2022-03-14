
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);
%}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN  ELSE FOR RETURN MOD ID INT;
%token AND OR NOT;
%token NUMBER;
%token STRING COMMENT;
%token WHITESPACE EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV ASSIGN LT GT;



%%

calclist: /* nothing */  
 | term EOL { printf("= %d\n", $1); }
 ;

exp: factor      
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 ;

 factor: term       
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: NUMBER {$$ = $1}; 


%%

main(int argc, char **argv)
{
  yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n",msg);
  return 0;
}
