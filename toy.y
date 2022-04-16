
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);

  #include <stdlib.h>
  #include <string.h>
  #include "sym.h"
  #include "ast.h"
  #include "ast.c"


  int printg(){
    printf("blah");
    return 0;
  }


%} 

%union{
  char* str;
  int val;
  Expression *expression;
}


%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN ELSE FOR RETURN MOD INT;
%token AND OR NOT;
%token <str> ID;
%token <val> NUMBER;
%token STRING COMMENT STRING_LITERAL;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV DOT COMMA ASSIGN LT GT;

%type <val> type;
%type <val> declaration;
%type <val> struct_;
%type <val> proc;
%type <val> l_exp;
%type <val> Name;
%type <val> int_literal;
%type <val> string_literal;
%type <val> bool_literal;
%type <val> stmt;
%type <val> stmt_seq;
%type <val> binary_maths_op;
%type <val> binary_boolean_op_r;
%type <val> binary_boolean_op_nr;
%type <val> return_type;

%type <expression> exp;


%%
input:	/* empty*/
	|input line {}
	;

line: 
	|pgm { print_symbol_table();}
	;

pgm2: 
| proc pgm2 { if($1 == 1){printf("-----------------------------Valid Proc\n");} else {printf("-----------------------------Invalid Proc\n"); }}
| struct_ pgm2 { if($1 == 1){printf("-----------------------------Valid Struct\n");} else {printf("-----------------------------Invalid Struct\n"); }}
;

pgm: proc pgm2 { if($1 == 1){printf("-----------------------------Valid Proc\n");} else {printf("-----------------------------Invalid Proc\n"); } }
| struct_ pgm { if($1 == 1){printf("-----------------------------Valid Struct\n");} else {printf("-----------------------------Invalid Struct\n"); } }
;


exp: /* nothing */ { $$ = NULL; }
  | OP exp CP {$$ = $2; }
  | exp binary_maths_op exp       { $$ = add_expression(4,11,12,$1,$3); }
  | exp binary_boolean_op_r exp   { $$ = add_expression(5,10,12,$1,$3); }
  | exp binary_boolean_op_nr exp  { $$ = add_expression(5,10,12,$1,$3); }
  | int_literal                   { $$ = add_expression(4,14,14,NULL,NULL); }
  | string_literal                { $$ = add_expression(6,14,14,NULL,NULL); }
  | bool_literal                  { $$ = add_expression(5,14,14,NULL,NULL); }
  | ID                            { $$ = add_expression(return_type($1),14,14,NULL,NULL); }
 ;

int_literal: NUMBER {$$ = $1;} 
;

string_literal: STRING_LITERAL {$$ = 1;}
;

bool_literal: TRUE {$$ = 1;}| FALSE {$$ = 1;}
;

binary_maths_op: ADD {$$ = 1;} 
  | MUL {$$ = 1;} 
  | DIV {$$ = 1;} 
  | SUB {$$ = 1;} 
  | MOD {$$ = 1;} 
  ;

  
binary_boolean_op_r: LTE {$$ = 1;} 
  | GTE {$$ = 1;} 
  | LT {$$ = 1;} 
  | GT {$$ = 1;} 
  ;

binary_boolean_op_nr: EQU {$$ = 1;} 
  | NEQ {$$ = 1;} 
  ;


type : INT { $$ = 4; }
 | BOOL { $$ = 5; }
 | STRING { $$ = 6; }
 | ID {store_struct_name(strtok($1, " ")); $$ = 7; }
;

declaration: type ID {if($1 != 0) { if(add_to_scope($1, $2) == 1){ $$ = 1; if($1 == 7) {add_struct_name(); add_struct_to_scope(strtok($2, ";")); struct_name = NULL;} } else { $$ = 0;} } else {$$ = 0;}}
| declaration COMMA declaration { if($1 == 0 || $3 == 0) { $$ = 0; } else {$$ = 1;}  } 
;



return_type : type {store_return_type($1); $$ = $1;  }
| VOID { store_return_type(1);  $$ = 1;}
;

struct_ : STRUCT Name OB declaration CB { is_struct(1); new_scope(); if($4 == 1 && $2 == 1){ $$ = 1; } else {$$ = 0;}  } 
; 


l_exp : ID  { printf("ORDER: %s\n", $1); if(check_scope(strtok($1, " =")) == 1) { int type_number = return_type(strtok($1, " =")); if(type_number == 7) { $$ = 0;} else { printf("Type number : %d\n", type_number); $$ = type_number;} }} /* return type, if 0 then invalid */
| ID DOT l_exp { if (check_if_field($1) != 0) { $$=$3;} else { $$ = 0; }}
;


intern_scope_then: THEN {add_internal_scope(); }
;

intern_scope_else: ELSE { delete_scope(); add_internal_scope(); }
;

FOR_LOOP: FOR { add_internal_scope(); }
;
stmt : FOR_LOOP OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt { delete_scope(); if(check_scope(strtok($3, " =")) == 1 && $9 == 1 && $11 == 1 && check_compatibility( 5, $7 )==1 && check_compatibility(return_type($3), $5)) { $$ = 1; } else { $$ = 0; } }
  | FOR_LOOP OP  SEMICOLON exp SEMICOLON stmt CP stmt { delete_scope(); if( $6 == 1 && $8 == 1 && check_compatibility( 5, $4 )==1 ) { $$ = 1; } else { $$ = 0; } }
  | IF OP exp CP intern_scope_then stmt { delete_scope();  print($3); if(check_compatibility( 5, $3 )==1){printf("If statement exp is bool\n");}else{printf("If statement exp is NOT bool\n");} if($6 == 0) { $$ = 0; } else { $$ = 1; } }
  | IF OP exp CP intern_scope_then stmt intern_scope_else stmt { delete_scope(); if($6 == 0 || $8 == 0 || check_compatibility( 5, $3 )==0) { $$ = 0; } else { $$ = 1; } }
  | PRINTF OP exp CP SEMICOLON { $$ = check_compatibility(6,$3); }
  | RETURN exp SEMICOLON  { $$ = 1; }
  | OB stmt_seq CB { $$ = $2; }
  | type ID SEMICOLON { printf("has returned with %d %s\n", $1, $2); if($1 == 0 || add_to_scope($1, $2) == 0) {  $$ = 0; } else {  $$ = 1; }  if($1 == 7) { printf("hey hey \n"); printf("HEREEEEEEEEEEEEEE\n"); add_struct_name(); printf("finished adding a_struct"); add_struct_to_scope(strtok($2, ";"));  }}
  | l_exp ASSIGN exp SEMICOLON { printf("What are we returning %d", $1); if( check_compatibility($1, $3) == 1 && ($1 != 0) ) { $$ = 1; } else { $$ = 0; }}
;

stmt_seq : /* empty */
 | stmt stmt_seq { if($1 == 0 || $2 == 0) { $$ = 0; } else { $$ = 1;}}
 ;

Name : ID { if(add_name($1) == 1){ $$ = 1; } else {$$ = 0;} }
;

proc : return_type Name OP declaration CP OB stmt_seq CB {new_scope(); if($4 == 1 && $2 == 1 && $7 == 1){ $$ = 1; } else {$$ = 0;}}
;

%%

 main()
{
    extern FILE *yyin, yyout;
    
    yyin = fopen("Test1.txt", "r");

    int parse = yyparse();
    // if(parse == 0) printf ("Error\n");
    // else printf("Valid");
}

int yyerror(const char *msg){
  fprintf(stderr, "%s\n", msg);
  return 0;
}
