package org.elsys.postfix.operation;

import org.elsys.postfix.Calculator;

public class Negate extends UnaryOperation {
    private static final String NAME = "neg";

    public Negate(Calculator calculator) {
        super(NAME, calculator);
    }

    @Override
    public double execute(double value) {
        return -value;
    }
}
