c6c: lex.yy.c y.tab.c c6c.c
	gcc -o c6c lex.yy.c y.tab.c c6c.c

lex.yy.c: c6.l
	flex c6.l

y.tab.c: c6.y
	bison -y -d c6.y

nas2:
	flex nas2.l
	bison -d nas2.y
	gcc -o nas2 lex.yy.c nas2.tab.c
