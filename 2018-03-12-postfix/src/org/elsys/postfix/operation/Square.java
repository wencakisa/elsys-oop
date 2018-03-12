package org.elsys.postfix.operation;

import org.elsys.postfix.Calculator;

public class Square extends UnaryOperation {
    private static final String NAME = "**";

    public Square(Calculator calculator) {
        super(NAME, calculator);
    }

    @Override
    public double execute(double value) {
        return value * value;
    }
}
