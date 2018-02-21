import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class TwoDimensionArray {
    private static final int DIMENSION = 6;

    private static int sumThreeConsecutive(int[] array, int startIndex) {
        return array[startIndex] + array[startIndex + 1] + array[startIndex + 2];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[][] array = new int[DIMENSION][DIMENSION];

        for (int row = 0; row < DIMENSION; row++) {
            for (int col = 0; col < DIMENSION; col++) {
                array[row][col] = in.nextInt();
            }
        }

        in.close();

        List<Integer> results = new ArrayList<>();
        for (int row = 0; row <= DIMENSION / 2; row++) {
            for (int col = 0; col <= DIMENSION / 2; col++) {
                int currentResult = sumThreeConsecutive(array[row], col)
                        + array[row + 1][col + 1]
                        + sumThreeConsecutive(array[row + 2], col);

                results.add(currentResult);
            }
        }

        System.out.println(Collections.max(results));
    }
}
