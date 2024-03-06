public class TestaPessoa{
    public static void main(String[] args){
        Pessoa p1 = new Pessoa();

        String nome1 = Teclado.lerString("digite um nome");
        String cpf1 = Teclado.lerString("digite um cpf");
        p1.setPessoa(nome1, cpf1);
        p1.getPessoa();
        nome1 = p1.getPessoa();
        System.out.println(nome1);
    }  
}