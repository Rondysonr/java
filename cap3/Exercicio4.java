public class Exercicio4{
	public static void main(String args[]){
        for(int i=1; i<=10; i++){
            int j=i, r=1;
            while(j>0){
                r=r*(j--);
            }			
        System.out.println(r);            
		} 
	}
}
/* O erro apresentado é devido aos fatoriais serem muito longos
fica inviavel usar variaveis do tipo long*/