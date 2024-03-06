public class Pessoa{
    String nome;  
    private String cpf;

public Pessoa(){    
}
public void setPessoa(String nome, String cpf){
    
    this.nome = nome;
    this.cpf = cpf;
}
public String getPessoa(){
    return nome;
}

}