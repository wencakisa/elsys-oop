package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class NegativeMultiply extends TernaryOperation implements Operation {
    public NegativeMultiply(Calculator calculator) {
        super(calculator, "\\*-\\*");
    }

    @Override
    protected double doCalculate(double firstValue, double secondValue, double thirdValue) {
        return -(firstValue * secondValue * thirdValue);
    }
}
