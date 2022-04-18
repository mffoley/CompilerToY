
%{
  #include <stdio.h>

  int yylex();
  int yyerror(const char *msg);

  #include <stdlib.h>
  #include <string.h>

  #include "ast.h"
  #include "sym.h"
  #include "ast.c"
  #include "sym.c"


  int printg(){
    printf("blah");
    return 0;
  }

  int error = 1;
  int valid = 1;


%} 

%union{
  char* str;
  int val;
  Expression *expression;
  ExpType *expt;
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
%type <val> Name;
%type <val> int_literal;
%type <val> string_literal;
%type <val> bool_literal;
%type <val> stmt;
%type <val> stmt_seq;
%type <val> binary_maths_op;
%type <val> binary_boolean_op_r;
%type <val> binary_boolean_op_nr;
%type <val> unary_maths_op;
%type <val> unary_boolean_op;
%type <val> return_type;
%type <val> pgm;
%type <val> pgm2;
%type <val> line;
%type <val> input;


%type <expression> exp;

%type <val> declaration_check;

%type <expt> l_exp;


%%
input:  { $$ = 1; }	/* empty*/
	|input line {if(($1 == 1) && ($2 == 1)) { valid = 1; $$ = 1; } else{ valid = 0; $$ = 0; }}
	;

line: 
	|pgm { if(check_for_main() == 1 && ($1 == 1)) { $$ = 1; }else { $$ = 0; }}
	;

pgm2: 
| proc pgm2 { if(($1 == 1) && ($2 == 1)){ $$=1; } else { $$=0; }}
| struct_ pgm2 { if(($1 == 1) && ($2 == 1)){ $$=1; } else { $$=0; }}
;

pgm: proc pgm2 { if(($1 == 1) && ($2 == 1)){ $$=1; } else { $$=0; } }
| struct_ pgm { if(($1 == 1) && ($2 == 1)){ $$=1; } else { $$=0; } }
;


exp: /* nothing */ { $$ = NULL; }
  | OP exp CP {$$ = $2; }
  | unary_boolean_op exp          { $$ = add_expression(5,9,13,NULL,$2,NULL); }
  | unary_maths_op exp            { $$ = add_expression(4,11,13,NULL,$2,NULL); }
  | exp binary_maths_op exp       { $$ = add_expression(4,11,12,$1,$3,NULL); }
  | exp binary_boolean_op_r exp   { $$ = add_expression(5,10,12,$1,$3,NULL); }
  | exp binary_boolean_op_nr exp  { $$ = add_expression(5,10,12,$1,$3,NULL); }
  | int_literal                   { $$ = add_expression(4,14,14,NULL,NULL,NULL); }
  | string_literal                { $$ = add_expression(6,14,14,NULL,NULL,NULL); }
  | bool_literal                  { $$ = add_expression(5,14,14,NULL,NULL,NULL); }
  | ID OP declaration_check CP    { printf("calling expression\n");$$ = add_expression(get_return_type_of_a_proc($1),14,14,NULL,NULL,NULL); }
  | l_exp                         { /*printf("right side exp: %d, %s\n",$1->type,$1->sname);*/ $$ = add_expression($1->type,14,14,NULL,NULL,$1->sname); }
 ;

int_literal: NUMBER {if($1 >= 32768 || $1 < -32768 ) {printf("too big int");$$ = 0;} else{$$ = 1;}} 
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

unary_maths_op: SUB {$$ = 1;} 
  ;

unary_boolean_op: NEGATE {$$ = 1;} 
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


declaration_check: exp {  $$=1;}
| declaration_check COMMA exp { $$=1;}
  
;


return_type : type {store_return_type($1); $$ = $1;  }
| VOID { store_return_type(1);  $$ = 1;}
;

struct_ : STRUCT Name OB declaration CB { is_struct(1); new_scope(); if($4 == 1 && $2 == 1){ $$ = 1; } else {$$ = 0;}  } 
; 


l_exp : ID  {  if(check_scope($1) == 1) { $$ = return_type($1);  } /* printf("found that this is of type: %d\n", $$->type);*/ } /* return type, if 0 then invalid */
| ID DOT l_exp {printf("c\n");printf("checkiffield %d\n", check_if_field($1)); if (check_if_field($1) != 0) { $$=$3;  printf("found that this is of type: %d\n", $$->type); } else { printf("cant get it");$$ = NULL; }}
;


intern_scope_then: THEN {add_internal_scope(); }
;

intern_scope_else: ELSE { delete_scope(); add_internal_scope(); }
;

FOR_LOOP: FOR { add_internal_scope(); }
;
stmt : FOR_LOOP OP ID ASSIGN exp SEMICOLON exp SEMICOLON stmt CP stmt { delete_scope(); if(check_scope($3) == 1 && $9 == 1 && $11 == 1 && check_compatibility( 5, $7 )==1 && check_compatibility(return_type($3)->type, $5)) { $$ = 1; } else { $$ = 0; } }
  | FOR_LOOP OP  SEMICOLON exp SEMICOLON stmt CP stmt { delete_scope(); if( $6 == 1 && $8 == 1 && check_compatibility( 5, $4 )==1 ) { $$ = 1; } else { $$ = 0; } }
  | IF OP exp CP intern_scope_then stmt { delete_scope();   if(check_compatibility( 5, $3 )!=1 || $6 == 0){$$ = 0;}else{$$ = 1;} }
  | IF OP exp CP intern_scope_then stmt intern_scope_else stmt { delete_scope(); if($6 == 0 || $8 == 0 || check_compatibility( 5, $3 )==0) { $$ = 0; } else { $$ = 1; } }
  | PRINTF OP exp CP SEMICOLON { $$ = check_compatibility(6,$3); }
  | RETURN exp SEMICOLON  {ExpType* r = get_return_type_current_proc();  $$ = check_compatibility_dyn(r,$2, 1); }
  | OB stmt_seq CB { $$ = $2; }
  | ID OP declaration_check CP { if (get_return_type_of_a_proc($1) == 1){$$ = 1;}else{$$=0;} }
  | type ID SEMICOLON {  if($1 == 0 || add_to_scope($1, $2) == 0) {  $$ = 0; } else {  $$ = 1; }  if($1 == 7) { add_struct_name();  add_struct_to_scope($2);  }}
  | l_exp ASSIGN exp SEMICOLON { if( check_compatibility_dyn($1, $3, 0) == 1 && ($1 != 0) ) { $$ = 1; } else { $$ = 0; }}
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
    
    yyin = fopen("Test6VALID.txt", "r");

    int parse = yyparse();
    printf("valid: %d\nerror: %d\n", valid, error);
    if(valid == 0 || error == 0) printf ("Error\n");
    else printf("\nValid\n\n");
}

int yyerror(const char *msg){
  error = 0;
}
