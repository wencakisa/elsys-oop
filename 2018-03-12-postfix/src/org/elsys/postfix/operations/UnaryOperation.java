package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class UnaryOperation extends AbstractOperation {

	public UnaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Calculator calculator = getCalculator();

		double value = calculator.popValue();
		double result = doCalculate(value);
		calculator.addValue(result);
	}

	protected abstract double doCalculate(double value);
}
