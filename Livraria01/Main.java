package br.com.Livraria01;

public class Main {
	static Livro[] lista = new Livro[3];
	public static void main(String[] args) {
		Menu();
	}
	private static void Menu() {
		while (true) {
			int opcaoMenu = Teclado.lerInteiro("1 cadastro \n 2 vender \n 3 listar livros \n 4 sair ");
			// TODO Auto-generated method stub
			switch (opcaoMenu) {
			case 1:
				Cadastro();
				break;
			case 2:
				RealizarVenda();
				break;
			case 3:
				ListarLivros();
				break;
			case 4:
				System.exit(0);
				break;

			default:
				System.out.println("opção invalida!");
				break;
			}
		
		}

}
	private static void Cadastro() {
		int opcaoCadatro= Teclado.lerInteiro("1 para livro fisico\n 2 para Ebook");
		for (int i = 0; i < lista.length; i++) {
			if(lista[i]==null) {
				if (opcaoCadatro ==1) {
					String titulo = Teclado.lerString("digite o titulo");
					String autor = Teclado.lerString("qual o autor");
					double preco = Teclado.lerDouble("qual o valor");
					double peso = Teclado.lerDouble("qual o peso em G");
					int estoque =Teclado.lerInteiro("qual a quantidade de estoque");
					lista[i] = new LivroFisico(titulo, autor, preco, peso, estoque);
					break;
				}
				else if(opcaoCadatro ==2) {
					String titulo = Teclado.lerString("digite o titulo");
					String autor = Teclado.lerString("qual o autor");
					double preco = Teclado.lerDouble("qual o valor");
					String formato =Teclado.lerString("qual o formato");
					double tamanho = Teclado.lerDouble("qual tamanho do arquivo em MB");
					lista[i] = new Ebook(titulo, autor, preco, tamanho, formato);	
					break;
				}
			}
		}
	}
	private static void RealizarVenda() {
		String opcaoDeLivro = Teclado.lerString("qual o titulo do livro procurado");
		for (int i = 0; i < lista.length; i++) {
			if (lista[i].getTitulo().equals(opcaoDeLivro)) {
				if (lista[i] instanceof LivroFisico) {
					//System.out.println("quebrei aqui");
					((LivroFisico)lista[i]).calculaDesconto();
					//System.out.println("quebrei aqui 1");
					((LivroFisico)lista[i]).vender();
					//System.out.println("quebrei aqui 2");
					break;
				}
				else
					if(lista[i] instanceof Ebook) {
						((Ebook)lista[i]).vender();
						break;
					}
			}
			
		}
		
	}
	private static void ListarLivros() {
		// TODO Auto-generated method stub
		for (int i = 0; i < lista.length; i++) {
			if(lista[i]!= null)
				System.out.println(lista[i].toString());
		}
	}
}