import java.util.*;

public class ArrayListTask {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int linesCount = in.nextInt();

        List<List<Integer>> lines = new ArrayList<>();
        for (int i = 0; i < linesCount; i++) {
            int length = in.nextInt();

            List<Integer> currentLine = new ArrayList<>();
            for (int j = 0; j < length; j++) {
                currentLine.add(in.nextInt());
            }

            lines.add(currentLine);
        }

        int queriesCount = in.nextInt();

        List<Map<String, Integer>> queries = new ArrayList<>();
        for (int i = 0; i < queriesCount; i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            Map<String, Integer> query = new HashMap<>();
            query.put("x", x - 1);
            query.put("y", y - 1);

            queries.add(query);
        }

        for (Map<String, Integer> query : queries) {
            try {
                System.out.println(lines.get(query.get("x")).get(query.get("y")));
            } catch (IndexOutOfBoundsException ex) {
                System.out.println("ERROR!");
            }
        }

        in.close();
    }
}
