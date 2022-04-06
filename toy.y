
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

%type <val> type;
%type <val> declaration;
%type <val> struct_;
%type <val> proc;
%type <val> l_exp;



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

pgm: proc pgm2 { }
| struct_ { print_struct_table();}
;


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

type : INT { $$ = 4; }
 | BOOL { $$ = 5; }
 | STRING { $$ = 6; }
 | ID { if(check_struct_name($1) == 1) { add_struct_to_scope($1); $$ = 7; } else { $$ = 0; } }
;

declaration: type ID { if($1 != 0) { add_to_node_list($1, $2); $$ = 1; } }
| declaration COMMA declaration {  } 
;


return_type : type | VOID 
;

struct_ : STRUCT ID OB declaration CB { if(add_to_struct_table($2) == 0) { $$ = 0; } else { $$ = 1; } delete_node_list();  } 
; 

l_exp : ID  {  if(check_scope($1)== 0) { $$ = 0; } else { $$ = 1; } }
| ID DOT l_exp { print_node_list(); }
;

stmt : FOR OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt 
  | IF exp THEN stmt {}
  | IF exp THEN stmt ELSE stmt
  | PRINTF OP STRING CP SEMICOLON
  | RETURN exp SEMICOLON
  | type ID SEMICOLON {  if($1 != 0){ add_to_node_list($1, $2); }}
  | l_exp ASSIGN exp SEMICOLON 
;

stmt_seq : /* empty */
 | stmt stmt_seq
 ;

proc : return_type ID OP declaration CP OB stmt_seq CB { if(add_to_symbol_table($2) == 0) { $$ = 0; } else { print_symbol_table(); $$ = 1; } delete_node_list();}
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
