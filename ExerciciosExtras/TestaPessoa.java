public class TestaPessoa{
    public static void main(String args[]){
        int max = 2;
        Pessoa[] p1 = new Pessoa[max];
        
        while(true) {
            System.out.println(" 1 - Cad\n 2 - Edit\n 3 - Consult\n 4 - Excl\n 5 - Sair");
            int op = Teclado.lerInteiro("Digite uma opção:");
            switch(op){
                case 1:
                    for (int i = 0; i < p1.length; i++){
                        String nome = Teclado.lerString("Digite um nome: ");
                        String cpf = Teclado.lerString("Digite um CPF: ");
                        p1[i] = new Pessoa(nome, cpf);
                    }
                    break;
                // editar
                case 2:
                    String pcpf = Teclado.lerString("Digite o CPF procurado: ");
                    for (int i= 0; i<p1.length && p1[i] != null; i++){
                        System.out.println("passei aqui");
                        if(p1[i].getCpf().equals(pcpf)){
                            String nome = Teclado.lerString("Digite um CPF: ");
                            p1[i].setNome(nome);
                        }
                    }

                    break;
                case 3:
                    // Consult
                    for (int i= 0; i<p1.length; i++){
                        if(p1[i] != null){
                            System.out.println(p1[i].toString());
                        }
                    }
                    break;
                // Excluir    
                case 4:
                    String pcpf1 = Teclado.lerString("Digite o CPF procurado: ");
                    for (int i= 0; i<p1.length; i++){
                        
                        if(p1[i].getCpf().equals(pcpf1)){
                            p1[i] = null;
                            System.out.println("Excluido");
                        }
                    }
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("opção invalida");
            }
        } 
    }
}