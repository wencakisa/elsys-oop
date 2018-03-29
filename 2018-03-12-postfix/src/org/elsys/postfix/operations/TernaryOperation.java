package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public abstract class TernaryOperation extends AbstractOperation {
    public TernaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        try {
            double firstValue = calculator.popValue();
            double secondValue = calculator.popValue();
            double thirdValue = calculator.popValue();

            double result = doCalculate(firstValue, secondValue, thirdValue);

            calculator.addValue(result);
        } catch (IndexOutOfBoundsException ex) {
            throw new EmptyStackException();
        }
    }

    protected abstract double doCalculate(double firstValue, double secondValue, double thirdValue);
}
