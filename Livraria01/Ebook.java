package br.com.Livraria01;

public class Ebook extends Livro implements Vendavel {
	protected double tamanhoDoArquivo;
	protected String formato;
	
	
	
	
	public double getTamanhoDoArquivo() {
		return tamanhoDoArquivo;
	}

	public void setTamanhoDoArquivo(double tamanhoDoArquivo) {
		this.tamanhoDoArquivo = tamanhoDoArquivo;
	}

	public String getFormato() {
		return formato;
	}

	public void setFormato(String formato) {
		this.formato = formato;
	}

	public boolean vender() {
			return true;
		}

	public Ebook(String titulo, String autor, double preco, double tamanhoDoArquivo, String formato) {
		super(titulo, autor, preco);
		this.tamanhoDoArquivo = tamanhoDoArquivo;
		this.formato = formato;
	}

	@Override
	public String toString() {
		return "Ebook [tamanhoDoArquivo=" + tamanhoDoArquivo + ", formato=" + formato + ", titulo=" + titulo
				+ ", autor=" + autor + ", preco=" + preco + "]";
	}
	
	
}
