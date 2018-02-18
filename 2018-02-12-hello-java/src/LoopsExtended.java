import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class LoopsExtended {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numberOfQueries = in.nextInt();

        List<List<Integer>> allResults = new ArrayList<>();
        for (int i = 0; i < numberOfQueries; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            List<Integer> currentResults = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                int result = a;

                for (int x = 0; x < j; x++) {
                    result += Math.pow(2, x) * b;
                }

                currentResults.add(result);
            }

            allResults.add(currentResults);
        }

        for (List<Integer> results : allResults) {
            for (Integer value : results) {
                System.out.print(value + " ");
            }
            System.out.println();
        }

        in.close();
    }
}
