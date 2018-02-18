package org.elsys;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

public class SyntaxChecker {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int testCases = Integer.parseInt(in.nextLine());

        List<String> patterns = new ArrayList<>();
        for (int i = 0; i < testCases; i++) {
            patterns.add(in.nextLine());
        }

        in.close();

        for (String pattern : patterns) {
            try {
                Pattern.compile(pattern);
            } catch (PatternSyntaxException ex) {
                System.out.println("Invalid");
                continue;
            }

            System.out.println("Valid");
        }
    }
}
