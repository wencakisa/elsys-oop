import java.util.Scanner;

public class IntegerToString {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int number = in.nextInt();

        if (!Integer.toString(number).equals("")) {
            System.out.println("Good job");
        } else {
            System.out.println("Wrong answer");
        }
    }
}
