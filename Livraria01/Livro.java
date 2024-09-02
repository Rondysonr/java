package br.com.Livraria01;

public abstract class Livro {
	protected String titulo;
	protected String autor;
	protected double preco;
	
	
	
	public Livro(String titulo, String autor, double preco) {
		super();
		this.titulo = titulo;
		this.autor = autor;
		this.preco = preco;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getAutor() {
		return autor;
	}
	public void setAutor(String autor) throws PrecoInvalidoException {
		if (preco<0) {
			throw new PrecoInvalidoException("O produto não pode ter preço negativo");
		}
		this.autor = autor;
	}
	public double getPreco() {
		return preco;
	}
	public void setPreco(double preco) {
		this.preco = preco;
	}
	@Override
	public String toString() {
		return "Livro [titulo=" + titulo + ", autor=" + autor + ", preco=" + preco + "]";
	}
	
	
}
