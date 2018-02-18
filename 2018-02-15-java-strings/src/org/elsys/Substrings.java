package org.elsys;

import java.util.Scanner;

public class Substrings {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        Integer start = Integer.parseInt(in.next());
        Integer end = Integer.parseInt(in.next());

        in.close();

        System.out.println(s.substring(start, end));
    }
}
