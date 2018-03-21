package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Plus extends BinaryOperation implements Operation {
    public Plus(Calculator calculator) {
        super(calculator, "+");
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue + rightValue;
    }
}
