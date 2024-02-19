public class VetorDeVetor{
	public static void main(String args[]){
       int[][] x= new int[3][3];
       for(int i=0; i< x.length; i++){
        for(int j=0; j< x.length; j++){
            x[i][j]= i + j;
              System.out.println("-- "+ x[i][j]);
        }
       }
        for(int i=0; i< x.length; i++){
        for(int j=0; j< x.length; j++){
            System.out.print(" "+ x[i][j]);
            if(j== x.length-1){
                System.out.println();
            }
	    }
    }
}
}