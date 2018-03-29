package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Negate extends UnaryOperation implements Operation {

	private static final String NEGATE_TOKEN = "neg";

	public Negate(Calculator calculator) {
		super(calculator, NEGATE_TOKEN);
	}
	
	@Override
	protected double doCalculate(double value) {
		return -value;
	}

}
