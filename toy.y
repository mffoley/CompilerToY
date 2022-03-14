
%token BOOL TRUE FALSE VOID PRINTF STRUCT IF THEN  ELSE FOR RETURN MOD ID;
%token AND OR NOT;
%token INT;
%token STRING COMMENT;
%token WHITESPACE;
%token EQU LTE GTE NEQ OB CB SEMICOLON NEGATE OP CP;
%token ADD SUB MUL DIV ASSIGN LT GT;



%%

calclist: /* nothing */  
 | calclist exp EOL { printf("= %d\n", $2); }
 ;

exp: factor       default $$ = $1 
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 ;

 factor: term       default $$ = $1 
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: INT  default $$ = $1
 | OP exp CP { $$ = $2; }
;


%%