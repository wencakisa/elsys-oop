package org.elsys;

import java.util.Scanner;

public class Palindrome {
    private static boolean isPalindrome(String str) {
        String reversed = new StringBuilder(str).reverse().toString();

        return str.equals(reversed);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String str = in.nextLine();

        in.close();

        System.out.println((isPalindrome(str) ? "Yes" : "No"));
    }
}
