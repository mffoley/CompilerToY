default:
	bison -d toy.y
	flex toy.l
	gcc toy.tab.c lex.yy.c -ll -Wno-error=implicit-function-declaration
	./a.out

test:
	./a.out
