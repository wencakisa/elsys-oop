package org.elsys;

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Anagrams {
    private static int getLetterOccurrences(String str, Character letter) {
        return str.length() - str.replace(letter.toString(), "").length();
    }

    private static Map<Character, Integer> letterOccurrences(String str) {
        Map<Character, Integer> occurrences = new HashMap<>();

        str = str.toLowerCase();
        for (Character letter : str.toCharArray()) {
            occurrences.put(letter, getLetterOccurrences(str, letter));
        }

        return occurrences;
    }

    private static boolean isAnagram(String a, String b) {
        return letterOccurrences(a).equals(letterOccurrences(b));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String a = in.nextLine();
        String b = in.nextLine();

        in.close();

        System.out.println((isAnagram(a, b)) ? "Yes" : "No");
    }
}
