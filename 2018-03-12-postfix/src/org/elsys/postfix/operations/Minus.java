package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Minus extends BinaryOperation implements Operation {

    private static final String MINUS_TOKEN = "-";

    public Minus(Calculator calculator) {
        super(calculator, MINUS_TOKEN);
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return rightValue - leftValue;
    }
}
