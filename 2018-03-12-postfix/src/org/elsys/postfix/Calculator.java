package org.elsys.postfix;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;

import org.elsys.postfix.operation.Operation;

public class Calculator {

    private InputStream in;
    private OutputStream out;

    private Map<String, Operation> operations = new HashMap<>();
    private List<Double> values = new ArrayList<>();

    public Calculator(InputStream in, OutputStream out) {
        this.in = in;
        this.out = out;
    }

    public void addOperation(Operation operation) {
        operations.put(operation.getName(), operation);
    }

    public Operation getOperation(String symbol) {
        return operations.get(symbol);
    }

    public double popValue() {
        return values.remove(values.size() - 1);
    }

    public void run(String quitWord) {
        Scanner scanner = new Scanner(in);
        PrintStream printOut = new PrintStream(out);

        while (true) {
            printOut.printf("(%d): ", values.size());

            String line = scanner.nextLine();

            if (line.equals(quitWord)) {
                break;
            }

            try {
                double value = Double.valueOf(line);

                values.add(value);
            } catch (NumberFormatException nfe) {
                Operation operation = getOperation(line);

                if (operation != null) {
                    double value = operation.execute();
                    values.add(value);

                    printOut.println(value);
                } else {
                    printOut.println("Unknown operation");
                }
            }
        }
    }
}
