default:
    bison -d toy.y
    flex toy.l
    gcc toy.tab.c lex.yy.c -lfl -Wno-error=implicit-function-declaration
    ./a

test:
    ./a