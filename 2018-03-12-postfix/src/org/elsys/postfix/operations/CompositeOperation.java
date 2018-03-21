package org.elsys.postfix.operations;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

import org.elsys.postfix.Calculator;

public class CompositeOperation extends AbstractOperation {

    public static final String MACRO_DEFINITION_START = "\\";
    public static final String MACRO_DEFINITION_END   = "def";

	private List<Operation> operations = new ArrayList<>();

	public CompositeOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		for (Operation op : operations) {
			op.calculate();
		}
	}
	
	public void addOperation(Operation op) {
		operations.add(op);
	}
}
