%%
"bool" |
"int" |
"true" |
"false" |
"void" |
"printf" |
"string" |
"struct" |
"if" |
"then" |
"else" |
"for" |
"return" {return KEYWORD;}


[_a-zA-Z][_a-zA-Z0-9]* {return ID;}

-?[0-9]+(;|\s) {return INT;}


"==" |
"<=" | 
">=" |
"!=" | 
"{" |
"}" |
";" |
"!" |
"(" |
")" |
"+" |
"-" |
"." |
"=" | 
"<" |
">" |{return SYMBOLS;}

(\/\/|##).*\n {return COMMENT;}

[\s\t]+ {return WHITESPACE;}

.	{ yyerror("Mystery character %c\n", *yytext); }

%% 