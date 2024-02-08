public class ExercicioE{
	public static void main(String args[]){
        int r=0, p=0, i=0;

		for(i=0; i<=100; i++){
            if (i%2==0){
                
                p=p+i;
            }
            else 
            
            r=r+i;
        }
        System.out.println("par:" +p+ " "+ "impar"+ r);	
	}
}