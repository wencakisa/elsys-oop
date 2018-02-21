import java.util.*;

public class StackTask {
    private static boolean isOpeningBracket(Character bracket) {
        return bracket.equals('(') || bracket.equals('[') || bracket.equals('{');
    }

    private static boolean isClosingBracket(Character bracket) {
        return bracket.equals(')') || bracket.equals(']') || bracket.equals('}');
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Stack<Character> brackets = new Stack<>();
        List<Boolean> results = new ArrayList<>();
        while (in.hasNext()) {
            String line = in.next();

            for (char bracket : line.toCharArray()) {
                if (isOpeningBracket(bracket)) {
                    brackets.push(bracket);
                } else if (isClosingBracket(bracket)) {
                    try {
                        brackets.pop();
                    } catch (EmptyStackException ex) {
                        brackets.push('_');
                        break;
                    }
                }
            }

            results.add(brackets.empty());
            brackets.clear();
        }

        for (boolean result : results) {
            System.out.println(result);
        }
    }
}
