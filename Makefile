ola: clean
	@echo "=================================="
	@echo "         PROGRAMA LISTA"
	@echo "=================================="
	@echo "- Compilando GeneralizedList"
	gcc GeneralizedLinkedList.h GeneralizedLinkedList.c GeneralizedLinkedListTest.c -o lista
	@echo "- Torna o programa olamundo executásvel"
	chmod +x lista
	@echo "- Executando o programa ola mundo"
	./lista
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