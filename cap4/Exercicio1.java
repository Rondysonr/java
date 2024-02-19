public class Exercicio1{
	public static void main(String args[]){
       Conta c1 = new Conta();
       c1.titular = "rondyson";
       c1.numeroCC = 1014;
       c1.agencia = "002";
       c1.dataAbertura = "18/02/2024";
       c1.saldo = 100;
       
        // Exibindo o saldo inicial
        System.out.println("Saldo atual: R$ " + c1.saldo);

        // Realizando um depósito
        c1.deposito(100.0);
        System.out.println("Saldo após depósito: R$ " + c1.saldo);

        // Realizando um saque
        c1.saque(50.0);
        System.out.println("Saldo após saque: R$ " + c1.saldo);

        // Exibindo o rendimento da conta
        System.out.println("Rendimento: R$ " + c1.rendimento());

        // Exibindo todos os dados da conta
        System.out.println("\nDados da Conta:");
        System.out.println(c1.recuperaDadosParaImpressao());
    }
}

