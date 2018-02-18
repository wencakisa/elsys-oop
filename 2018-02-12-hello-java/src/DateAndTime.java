import java.util.Calendar;
import java.util.Scanner;

public class DateAndTime {
    private static String getDay(String day, String month, String year) {
        Calendar c = Calendar.getInstance();
        c.set(Calendar.DAY_OF_MONTH, Integer.parseInt(day));
        c.set(Calendar.MONTH, Integer.parseInt(month));
        c.set(Calendar.YEAR, Integer.parseInt(year));

        String result = c.get(Calendar.DAY_OF_WEEK);

        return "";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String month = in.next();
        String day = in.next();
        String year = in.next();

        System.out.println(getDay(day, month, year));
    }
}
