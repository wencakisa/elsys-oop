package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Multiply extends BinaryOperation implements Operation {
    public Multiply(Calculator calculator) {
        super(calculator, "*");
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue * rightValue;
    }
}
