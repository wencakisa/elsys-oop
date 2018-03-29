package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Cos extends UnaryOperation implements Operation {

    private static final String COS_TOKEN = "cos";

    public Cos(Calculator calculator) {
        super(calculator, COS_TOKEN);
    }

    @Override
    protected double doCalculate(double value) {
        return Math.cos(value);
    }
}
