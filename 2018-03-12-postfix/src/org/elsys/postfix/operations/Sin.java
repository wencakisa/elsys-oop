package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Sin extends UnaryOperation implements Operation {

    private static final String SIN_TOKEN = "sin";

    public Sin(Calculator calculator) {
        super(calculator, SIN_TOKEN);
    }

    @Override
    protected double doCalculate(double value) {
        return Math.sin(value);
    }
}
