import java.util.Scanner;

public class ScannerExercise {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int length = 3;
        int numbers[] = new int[length];

        for (int i = 0; i < length; i++) {
            numbers[i] = in.nextInt();
        }

        for (int number : numbers) {
            System.out.println(number);
        }

        in.close();
    }
}
