package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Multiply extends BinaryOperation implements Operation {

    private static final String MULTIPLY_TOKEN = "*";

    public Multiply(Calculator calculator) {
        super(calculator, MULTIPLY_TOKEN);
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue * rightValue;
    }
}
