run: clean
	@echo "=================================="
	@echo "         PROGRAMA HASH"
	@echo "=================================="
	@echo "- Compilando WORK_HASH"
	gcc  DoublyLinkedList.h DoublyLinkedList.c WorkHash.h WorkHash.c WorkHashTest.c -o WorkHash -lm
	@echo "- Torna o programa WorkHash executásvel"
	chmod +x WorkHash
	@echo "- Executando o WorkHash"
	./WorkHash
	@echo "=================================="

clean:
	@echo "===================================="
	@echo "Removendo os programas compilados"
	@echo "===================================="
	@echo "Removendo o programa WorkHash"
	rm -f ola
	@echo "===================================="

help:
	@echo "======================"
	@echo "         AJUDA"
	@echo "======================"
	@echo "help		| ajuda"
	@echo "run		| executar o codigos"
	@echo "clean    | apagar codigos compilados"