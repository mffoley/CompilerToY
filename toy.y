
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
	|pgm EOL {}
	;

pgm2: 
| proc pgm2
| struct_ pgm2 { }

pgm: proc pgm2
| struct_ { print_struct_table(); }



exp: /* nothing */
 | string_literal {  }
 | l_exp { }
 | OP exp CP { }
 | int_exp {}
 | bool_exp { }
 ;

int_exp: /* nothing */
  | int_exp ADD int_exp {  }
  | int_exp SUB int_exp {  }
  | int_exp MUL int_exp { }
  | int_exp DIV int_exp { }
  | int_exp MOD int_exp {   }
  | SUB int_exp { }
  | int_literal {  }
  ;

bool_exp: /* nothing */
  | exp EQU exp { }
  | exp LT exp {  }
  | exp GT exp {  }
  | exp LTE exp { }
  | exp GTE exp { }
  | exp NEQ exp { }
  | NEGATE bool_exp {  }
  | bool_literal {  }
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

declaration: type ID { add_to_node_list(4, $2); }
| declaration COMMA declaration {  } 
;


return_type : type | VOID 
;

struct_ : STRUCT ID OB declaration CB { add_to_struct_table($2); delete_node_list(); } 
; 

l_exp : ID  {  check_scope($1); }
| ID DOT l_exp { check_scope($1); }
;

stmt : FOR OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt
  | IF exp THEN stmt
  | IF exp THEN stmt ELSE stmt
  | PRINTF OP STRING CP SEMICOLON
  | RETURN exp SEMICOLON
  | type ID SEMICOLON { add_to_node_list(4, $2); }
  | l_exp ASSIGN exp SEMICOLON 
;

stmt_seq : /* empty */
 | stmt stmt_seq
 ;

proc : return_type ID OP declaration CP OB stmt_seq CB { add_to_symbol_table($2); print_symbol_table(); delete_node_list(); }
;

%%

main()
{
    extern FILE *yyin, yyout;
    
    yyin = fopen("Input.txt", "r");

    int parse = yyparse();
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}
