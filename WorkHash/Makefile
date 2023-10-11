ola: clean
	@echo "=================================="
	@echo "         PROGRAMA HASH"
	@echo "=================================="
	@echo "- Compilando WORK_HASH"
	gcc WorkHash.h WorkHash.c WorkHashTest.c -o lista
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