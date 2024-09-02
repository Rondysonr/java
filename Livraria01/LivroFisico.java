package br.com.Livraria01;

public class LivroFisico extends Livro implements Vendavel {
	protected double peso;
	protected int estoque;
	
	
	
	public double getPeso() {
		return peso;
	}


	public void setPeso(double peso) {
		this.peso = peso;
	}


	public int getEstoque() {
		return estoque;
	}


	public void setEstoque(int estoque) {
		this.estoque = estoque;
	}


	public void calculaDesconto() {
		double desconto = (peso >1000)? 0.1:0.05;
		setPreco(getPreco() *(1 - desconto));
	}
	public boolean vender() {
		if (estoque >0) {
			estoque--;
			return true;
		}
		return false;
	}


	@Override
	public String toString() {
		return "LivroFisico [peso=" + peso + ", estoque=" + estoque + ", titulo=" + titulo + ", autor=" + autor
				+ ", preco=" + preco + "]";
	}


	public LivroFisico(String titulo, String autor, double preco, double peso, int estoque) {
		super(titulo, autor, preco);
		this.peso = peso;
		this.estoque = estoque;
	}

}
