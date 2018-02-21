import java.util.Scanner;

public class SimpleArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int length = in.nextInt();

        int[] array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = in.nextInt();
        }

        for (int i : array) {
            System.out.println(i);
        }
    }
}
