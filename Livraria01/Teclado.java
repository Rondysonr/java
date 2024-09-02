package br.com.Livraria01;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Teclado {
	private static Scanner scann = new Scanner(System.in);
	public static int lerInteiro(String rotulo) {
        while (true) {
            try {
                System.out.println(rotulo);
                int valor= scann.nextInt();
                if (valor<0) {
                	System.out.println("não use valores negativos!");
                }else {
                	return valor;
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scann.next();
            }
        }
    }
	public static long lerLong(String rotulo) {
		while(true) {
			try {
				System.out.println(rotulo);
				long valor = scann.nextLong();
				if(valor <0) {
					System.out.println("não use valores negativos");
				}else {
					return valor;
				}
			}catch(InputMismatchException e){
				System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scann.next();
			}
		}
		
	}
	public static double lerDouble(String rotulo) {
		while(true) {
			try {
				System.out.println(rotulo);
				double valor = scann.nextDouble();
				if(valor <0) {
					System.out.println("Não use valores negativos");
				}else {
					return valor;
				}
			}catch(InputMismatchException e){
				System.out.println("Entrada inválida. Por favor, digite um número.");
                scann.next();
			}
		}
	}
	public static String lerString(String rotulo) {
		System.out.println(rotulo);
		Scanner scann = new Scanner (System.in);
		return scann.nextLine();
	}

}