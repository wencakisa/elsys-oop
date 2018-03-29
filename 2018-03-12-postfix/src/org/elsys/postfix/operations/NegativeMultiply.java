package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class NegativeMultiply extends TernaryOperation implements Operation {

    private static final String NEGATIVE_MULTIPLY_TOKEN = "\\*-\\*";

    public NegativeMultiply(Calculator calculator) {
        super(calculator, NEGATIVE_MULTIPLY_TOKEN);
    }

    @Override
    protected double doCalculate(double firstValue, double secondValue, double thirdValue) {
        return -(firstValue * secondValue * thirdValue);
    }
}
