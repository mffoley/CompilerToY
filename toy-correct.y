%{



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
 | string_literal { $$ = $1; }
 | l_exp { $$ = $1; }
 | OP exp CP {  $$ = $2; }
 | int_exp { $$ = $1; }
 | bool_exp {  $$ = $1; }
 ;

int_exp: /* nothing */
  | int_exp ADD int_exp {  $$ = $1 + $3; }
  | int_exp SUB int_exp { $$ = $1 - $3; }
  | int_exp MUL int_exp {  $$ = $1 * $3; }
  | int_exp DIV int_exp {  $$ = $1 / $3; }
  | int_exp MOD int_exp {  $$ = $1 % $3; }
  | SUB int_exp { $$ = $2 * -1; }
  | int_literal { $$ = $1; }
  ;

bool_exp: /* nothing */
  | exp EQU exp { $$ = $1 == $3; }
  | exp LT exp { $$ = $1 < $3; }
  | exp GT exp { $$ = $1 > $3; }
  | exp LTE exp { $$ = $1 <= $3; }
  | exp GTE exp { $$ = $1 >= $3; }
  | exp NEQ exp { $$ = $1 != $3; }
  | NOTEX bool_exp { $$ = ! $2; }
  | bool_literal { $$ = $1; }
  ;



term: int_literal | string_literal | bool_literal
; 

int_literal: NUMBER {$$ = $1;} 
;

string_literal : STRING {$$ = $1;} 
;

bool_literal : TRUE {$$ = $1;} | FALSE {$$ = $1;} 
;

type : INT {$$ = 4;}
 | BOOL {$$ = 5;}
 | STRING {$$ = 6;}
;

declaration: type ID SEMICOLON { printf("%s", $1); }

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