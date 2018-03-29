package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public abstract class BinaryOperation extends AbstractOperation {
    public BinaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {;
        Calculator calculator = getCalculator();

        try {
            double leftValue = calculator.popValue();
            double rightValue = calculator.popValue();

            double result = doCalculate(leftValue, rightValue);

            getCalculator().addValue(result);
        } catch (IndexOutOfBoundsException ex) {
            throw new EmptyStackException();
        }

    }

    protected abstract double doCalculate(double leftValue, double rightValue);
}
