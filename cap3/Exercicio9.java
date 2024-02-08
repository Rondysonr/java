public class Exercicio9 {
    public static void main(String[] args) {
        int numAnterior = 0;
        int numAtual = 1;
        System.out.print(numAnterior + " " + numAtual + " "); // Imprime os dois primeiros números
        while (numAnterior + numAtual <= 100) {
            int novoNum = numAnterior + numAtual;
            System.out.print(novoNum + " ");
            numAnterior = numAtual;
            numAtual = novoNum;
        }
    }
}