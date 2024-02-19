public class Conta{ 
    String titular, agencia;
    int numeroCC;
    double saldo; 
    Data dataDeAbertura;

       public void deposito(double valor){
        if(valor>0){
            saldo += valor;
            System.out.println("Valor depositado R$ " + valor);
        }
        else{
            System.out.println("valor invalido!");
        }
       }
       public void saque(double valor){
        if (valor > 0 && valor <= saldo){
            saldo -= valor;
            System.out.println("Você sacou R$ " + valor);
        }
        else{
            System.out.println("Saldo insuficiente!");
        }

       }
       public double rendimento(){
        return saldo *0.1;
       }

       public String recuperaDadosParaImpressao() {
        String dados =  titular + "\n" 
                        + numeroCC + "\n" 
                        + agencia + "\n" 
                        + saldo + "\n";
        return dados;
    }
}
