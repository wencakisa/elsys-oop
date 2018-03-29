package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Divide extends BinaryOperation implements Operation {

    private static final String DIVIDE_TOKEN = "/";

    public Divide(Calculator calculator) {
        super(calculator, DIVIDE_TOKEN);
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue / rightValue;
    }
}
