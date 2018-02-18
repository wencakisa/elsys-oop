import java.util.Scanner;

public class Loops {
    private static final int LENGTH = 10;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int value = in.nextInt();

        for (int i = 1; i <= LENGTH; i++) {
            System.out.println(value + " x " + i + " = " + value * i);
        }
    }
}
