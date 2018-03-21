package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class TernaryOperation extends AbstractOperation {
    public TernaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        double firstValue = calculator.popValue();
        double secondValue = calculator.popValue();
        double thirdValue = calculator.popValue();

        double result = doCalculate(firstValue, secondValue, thirdValue);

        calculator.addValue(result);
    }

    protected abstract double doCalculate(double firstValue, double secondValue, double thirdValue);
}
