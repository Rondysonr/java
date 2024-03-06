public class Pessoa{
    private String nome;  
    private String cpf;

public Pessoa(){    
}
public void setPessoa(String nome, String cpf){
    this.nome = nome;
    this.cpf = cpf;
    
}
/*public String getPessoa(){
    return nome;
}
public String getPessoa(){
    return cpf;
}*/
public void printPessoa() {
        System.out.println("Nome: " + this.nome + ", CPF: " + this.cpf);
    }
}