public class Exercicio9{
	public static void main(String args[]){
       Conta c1 = new Conta();
       c1.titular = "rondyson";
       c1.numeroCC = 1014;
       c1.agencia = "002";
       c1.saldo = 100;
       Data data =	new	Data();	
	   c1.dataDeAbertura =	data;

       System.out.println("\nDados da Conta:");
       System.out.println(c1.recuperaDadosParaImpressao());
    }
}