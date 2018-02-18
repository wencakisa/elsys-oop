package org.elsys;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class SubstringComparisons {
    private static List<String> splitSubstrings(String str, int split) {
        List<String> result = new ArrayList<>();

        for (int i = 0; i <= str.length(); i++) {
            if (i + split <= str.length()) {
                result.add(str.substring(i, i + split));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        int split = in.nextInt();

        in.close();

        List<String> splittedSubstrings = splitSubstrings(s, split);
        Collections.sort(splittedSubstrings);

        System.out.println(splittedSubstrings.get(0));
        System.out.println(splittedSubstrings.get(splittedSubstrings.size() - 1));
    }
}
