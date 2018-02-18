import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class EndOfFile {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        List<String> lines = new ArrayList<>();

        while (in.hasNext()) {
            String line = in.nextLine();
            lines.add(line);
        }

        for (int i = 0; i < lines.size(); i++) {
            System.out.println(i + 1 + " " + lines.get(i));
        }
    }
}
