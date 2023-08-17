ola: clean
	@echo "=================================="
	@echo "         PROGRAMA LISTA"
	@echo "=================================="
	@echo "- Compilando ola mundo"
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o lista
	@echo "- Torna o programa olamundo executásvel"
	chmod +x ola
	@echo "- Executando o programa ola mundo"
	./ola
	@echo "=================================="

clean:
	@echo "===================================="
	@echo "Removendo os programas compilados"
	@echo "===================================="
	@echo "Removendo o programa olamundo"
	rm -f ola
	@echo "===================================="

help:
	@echo "======================"
	@echo "         AJUDA"
	@echo "======================"
	@echo "help		| ajuda"
	@echo "ela		| executar mensagem de texto"
	@echo "clean| apagar codigos compilados"