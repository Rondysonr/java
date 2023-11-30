all: meu_programa

meu_programa: arvoretest.o arvore.o
	gcc arvoretest.o arvore.o -o meu_programa -lm

arvore.o: arvore.c
	gcc -c arvore.c

arvoretest.o: arvoretest.c
	gcc -c arvoretest.c

clean:
	rm -f meu_programa arvore.o arvoretest.o