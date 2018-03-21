package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Divide extends BinaryOperation implements Operation {
    public Divide(Calculator calculator) {
        super(calculator, "/");
    }

    @Override
    protected double doCalculate(double leftValue, double rightValue) {
        return leftValue / rightValue;
    }
}
