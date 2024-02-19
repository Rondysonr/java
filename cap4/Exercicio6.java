public class Exercicio6{
	public static void main(String args[]){
        Conta c1 = new Conta();								
		c1.titular = "rondyson";
		c1.saldo = 100;
		Conta c2 = new Conta();

		Data data =	new	Data();	
		c1.dataDeAbertura =	data;
    }
}