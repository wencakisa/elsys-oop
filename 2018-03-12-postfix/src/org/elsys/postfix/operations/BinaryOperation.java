package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class BinaryOperation extends AbstractOperation {
    public BinaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {
        double leftValue = getCalculator().popValue();
        double rightValue = getCalculator().popValue();

        double result = doCalculate(leftValue, rightValue);

        getCalculator().addValue(result);
    }

    protected abstract double doCalculate(double leftValue, double rightValue);
}
