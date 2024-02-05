public class Exercicio6{
    public static void main(String[] args) {
        int limite = 100;

        System.out.println("Série de Fibonacci até ultrapassar " + limite + ":");
        
        int i = 0;
        while (fibonacci(i) <= limite) {
            System.out.print(fibonacci(i) + " ");
            i++;
        }
    }

    public static int fibonacci(int num) {
        if (num == 0) {
            return 0;
        } else if (num == 1) {
            return 1;
        } else {
            return fibonacci(num - 1) + fibonacci(num - 2);
        }
    }
}
