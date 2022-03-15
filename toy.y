
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);
%}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN  ELSE FOR RETURN MOD ID INT;
%token AND OR NOT;
%token NUMBER;
%token STRING COMMENT;
%token EOL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV ASSIGN LT GT;



%%
line: exp line | exp;


exp: /* nothing */  
 | term EOL { printf("= %d\n", $1); }
 | term ADD term EOL {printf("= %d\n", ($1 + $3));}
 | term SUB term EOL {printf("= %d\n", ($1 - $3));}
 | term MUL term EOL {printf("= %d\n", ($1 * $3));}
 | term DIV term EOL {printf("= %d\n", ($1 / $3));}
 | SUB term EOL {printf("= %d\n", $2 * -1);}
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
