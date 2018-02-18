package org.elsys;

import java.util.Scanner;

public class StringsIntroduction {
    private static String capitalize(String string) {
        return Character.toUpperCase(string.charAt(0)) + string.substring(1);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String a = in.nextLine();
        String b = in.nextLine();

        in.close();

        int lengthSum = a.length() + b.length();
        boolean lexicographicallyLarger = a.compareTo(b) > 0;
        String concatResult = capitalize(a) + " " + capitalize(b);

        System.out.println(lengthSum);
        System.out.println((lexicographicallyLarger) ? "Yes" : "No");
        System.out.println(concatResult);
    }
}
