package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public abstract class UnaryOperation extends AbstractOperation {

	public UnaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Calculator calculator = getCalculator();

		try {
            double value = calculator.popValue();

            double result = doCalculate(value);
            calculator.addValue(result);
        } catch (IndexOutOfBoundsException ex) {
            throw new EmptyStackException();
        }
	}

	protected abstract double doCalculate(double value);
}
