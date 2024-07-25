import java.util.Scanner;

public class Teclado {
	public static int lerInteiro(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextInt();
	}
	public static long lerLong(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextLong();
	}
	public static double lerDouble(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextDouble();
	}
	public static float lerFloat(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextFloat();
	}
	public static String lerString(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextLine();
	}

}
