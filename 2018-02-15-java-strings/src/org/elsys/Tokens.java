package org.elsys;

import java.util.Scanner;

public class Tokens {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String str = in.nextLine().trim();

        in.close();

        if (str.isEmpty()) {
            System.out.println(str.length());
            return;
        }

        String delimiters = "[!,?._'@ ]+";
        String[] tokens = str.split(delimiters);

        System.out.println(tokens.length);
        for (String token : tokens) {
            System.out.println(token);
        }
    }
}
