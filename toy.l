%{
# include "toy.tab.h"
%}

%%
"bool"    {return BOOL;}
"int"     {return INT;}
"true"    {return TRUE;}
"false"   {return FALSE;}
"void"    {return VOID;}
"printf"  {return PRINTF;}
"string"  {return STRING;}
"struct"  {return STRUCT;}
"if"      {return IF;}
"then"    {return THEN;}
"else"    {return ELSE;}
"for"     {return FOR;}
"and"     {return AND;}
"or"      {return OR;}
"not"     {return NOT;}
"mod"     {return MOD;}
"return"  {return RETURN;}


[_a-zA-Z][_a-zA-Z0-9]* {return ID;}

-?[1-9][0-9]* {
  yylval = atoi(yytext);
  return NUMBER;}

["][^\\"]*["] {return STRING;}


"=="  {return EQU;}
"<="  {return LTE;}
">="  {return GTE;}
"!="  {return NEQ;}
"{"   {return OB;}
"}"   {return CB;}
";"   {return SEMICOLON;}
"!"   {return NEGATE;}
"("   {return OP;}
")"   {return CP;}
"+"   {return ADD;}
"-"   {return SUB;}
"*"   {return MUL;}
"/"   {return DIV;}
"="   {return ASSIGN;}
"<"   {return LT;}
">"   {return GT;}

(\/\/|##).*\n {return COMMENT;}

[ \s\t]+      {return WHITESPACE;}

\n            {return EOL;}



%% 
