package org.elsys;

import java.util.InputMismatchException;
import java.util.Scanner;

public class DivisionByZero {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        try {
            int x = in.nextInt();
            int y = in.nextInt();

            System.out.println(x / y);
        } catch (InputMismatchException ime) {
            System.out.println(ime.getClass().getName());
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
