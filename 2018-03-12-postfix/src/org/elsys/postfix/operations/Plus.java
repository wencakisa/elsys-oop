package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Plus extends BinaryOperation implements Operation {

    private static final String PLUS_TOKEN = "+";

    public Plus(Calculator calculator) {
        super(calculator, PLUS_TOKEN);
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue + rightValue;
    }
}
