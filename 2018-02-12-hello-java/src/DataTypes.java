import java.util.Scanner;

public class DataTypes {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int count = in.nextInt();

        for (int i = 0; i < count; i++) {
            try {
                long currentNumber = in.nextLong();

                System.out.println(currentNumber + " can be fitted in:");

                if (currentNumber >= Byte.MIN_VALUE && currentNumber <= Byte.MAX_VALUE) System.out.println("* byte");
                if (currentNumber >= Short.MIN_VALUE && currentNumber <= Short.MAX_VALUE) System.out.println("* short");
                if (currentNumber >= Integer.MIN_VALUE && currentNumber <= Integer.MAX_VALUE) System.out.println("* int");
                if (currentNumber > Long.MIN_VALUE && currentNumber < Long.MAX_VALUE) System.out.println("* long");
            } catch (Exception e) {
                System.out.println(in.next() + " can't be fitted anywhere.");
            }
        }

        in.close();
    }
}
