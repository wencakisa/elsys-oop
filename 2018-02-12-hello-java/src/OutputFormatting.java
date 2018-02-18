import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Scanner;

public class OutputFormatting {
    private static final int LENGTH = 3;
    private static final int SPACES_PADDING = 15;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        HashMap<String, Integer> map = new LinkedHashMap<>();

        for (int i = 0; i < LENGTH; i++) {
            String str = in.next();
            int value = in.nextInt();

            map.put(str, value);
        }

        System.out.println("================================");
        map.forEach(
                (k, v) -> System.out.printf(
                        "%s%s\n",
                        String.format("%-" + SPACES_PADDING + "s", k),
                        String.format("%03d", v)
                )
        );
        System.out.println("================================");
    }
}
