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
"return" {printf("KEYWORD\n");}


[_a-zA-Z][_a-zA-Z0-9]* {printf("ID\n");}

-?[1-9][0-9]* {printf("INT\n");}

["][^\\]*["]$ {printf("STRING\n");}

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
">" {printf("SYMBOLS\n");}

(\/\/|##).*\n {printf("COMMENT\n");}

[ \s\t]+ {printf("WHITESPACE\n");}

.	{ printf("Mystery character %c\n", *yytext); }


%% 

int yywrap(){}
int main(){
  
yylex();
  
return 0;
}