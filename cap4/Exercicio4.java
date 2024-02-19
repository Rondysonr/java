/* aparentemente compara objetos de forma direta não é possivel
com o codigo em questão, só é possivel compara os atributos do 
objeto.*/ 


public class Exercicio4{
	public static void main(String args[]){
        Conta c1 = new Conta();								
		c1.titular = "rondyson";
		c1.saldo = 100;
		Conta c2 = new Conta();								
		c2.titular = "rondyson";
		c2.saldo = 100;

		if	(c1	== c2)	{
		    System.out.println("iguais");
        }	
        else{
		    System.out.println("diferentes");								
		}
    }
}