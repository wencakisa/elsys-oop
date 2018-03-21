package org.elsys.postfix;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;
import java.util.stream.Collectors;

import org.elsys.postfix.operations.*;

public class Calculator {

	private Map<String, Operation> operations = new HashMap<>();

	private List<Double> stack = new LinkedList<>();

	private InputStream in;

	private PrintStream out;
	
	public Calculator(InputStream in, PrintStream out) {
		this.in = in;
		this.out = out;

		addOperation(new Negate(this));
		addOperation(new Duplicate(this));
		addOperation(new Sin(this));
		addOperation(new Cos(this));
		addOperation(new Plus(this));
		addOperation(new Minus(this));
		addOperation(new Multiply(this));
		addOperation(new Divide(this));
		addOperation(new NegativeMultiply(this));
		addOperation(new Swap(this));
		addOperation(new Rot3(this));
	}

	public void run() {
		String input;

		try (Scanner scanner = new Scanner(in)) {
			while (scanner.hasNext()) {
				out.print(stack.size() + ": ");
				input = scanner.next();

                if (isDouble(input)) {
					stack.add(Double.valueOf(input));
				} else if (isMacroDefinition(input)) {
                    String macroName = input.split(CompositeOperation.MACRO_DEFINITION_START + CompositeOperation.MACRO_DEFINITION_START)[1];

                    addMacro(scanner, macroName);
                } else {
                    Operation operation = this.getOperation(input);

                    if (operation != null) {
                        operation.calculate();
                    } else {
                        throw new UnsupportedOperationException();
                    }
                }
			}
		}
	}

	private static boolean isDouble(String input) {
		try {
			Double.valueOf(input);
		} catch (NumberFormatException e) {
			return false;
		}
		return true;
	}

	private static boolean isMacroDefinition(String input) {
	    return input.startsWith(CompositeOperation.MACRO_DEFINITION_START);
    }

	public void addOperation(Operation operation) {
		operations.put(operation.getToken(), operation);
	}

	public Operation getOperation(String token) {
		return operations.get(token);
	}

    public void addMacro(Scanner scanner, String macroName) {
        CompositeOperation macro = new CompositeOperation(this, macroName);

        while (!scanner.hasNext(CompositeOperation.MACRO_DEFINITION_END)) {
            String input = scanner.next();

            Operation operation = this.getOperation(input);

            if (isDouble(input)) {
                operation = new Literal(this, Double.valueOf(input));
            }

            macro.addOperation(operation);
        }

        scanner.next();

        this.addOperation(macro);
    }

	public Double popValue() {
		int lastIndex = stack.size() - 1;

		if (lastIndex < 0) {
		    throw new EmptyStackException();
        }

		Double value = stack.get(lastIndex);
		stack.remove(lastIndex);
		return value;
	}

	public Double lastValue() {
		return stack.get(stack.size() - 1);
	}

	public void addValue(double value) {
		out.println(value);
		stack.add(value);
	}

	int stackSize() {
		return stack.size();
	}
}
