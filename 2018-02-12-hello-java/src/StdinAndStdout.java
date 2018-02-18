import java.util.Scanner;

public class StdinAndStdout {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int i = in.nextInt();
        double d = in.nextDouble();
        in.nextLine();
        String s = in.nextLine();

        System.out.printf("String: %s\n", s);
        System.out.printf("Double: %f\n", d);
        System.out.printf("Int: %d\n", i);
    }
}
