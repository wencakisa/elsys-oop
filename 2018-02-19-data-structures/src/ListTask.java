import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class ListTask {
    private static final String INSERT_COMMAND = "Insert";
    private static final String DELETE_COMMAND = "Delete";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int length = in.nextInt();

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            list.add(in.nextInt());
        }

        int commandsCount = in.nextInt();

        for (int i = 0; i < commandsCount; i++) {
            String command = in.next();
            int index = in.nextInt();

            if (command.equals(INSERT_COMMAND)) {
                int valueToInsert = in.nextInt();
                list.add(index, valueToInsert);
            } else if (command.equals(DELETE_COMMAND)) {
                list.remove(index);
            } else {
                System.err.println("Invalid command");
            }
        }

        String listToString = list.stream().map(Object::toString).collect(Collectors.joining(" "));
        System.out.println(listToString);
    }
}
