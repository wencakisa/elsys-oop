import java.text.NumberFormat;
import java.util.*;

public class CurrencyFormatter {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        double payment = in.nextDouble();

        in.close();

        Map<String, Locale> currencies = new LinkedHashMap<>();
        currencies.put("US", new Locale("en", "US"));
        currencies.put("India", new Locale("en", "IN"));
        currencies.put("China", new Locale("zh", "CN"));
        currencies.put("France", new Locale("fr", "FR"));

        for (String currency : currencies.keySet()) {
            String formattedCurrency = NumberFormat.getCurrencyInstance(currencies.get(currency)).format(payment);
            System.out.println(currency + ": " + formattedCurrency);
        }
    }
}
