run: clean
	@echo "=================================="
	@echo "         PROGRAMA ARVORE"
	@echo "=================================="
	@echo "- Compilando ARVORE"
	gcc  arvore.h arvore.c arvoretest.c -o arvore -lm
	@echo "- Torna o programa arvore executásvel"
	chmod +x ARVORE
	@echo "- Executando ARVORE"
	./ARVORE
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