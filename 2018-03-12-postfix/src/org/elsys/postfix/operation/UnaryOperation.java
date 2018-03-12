package org.elsys.postfix.operation;

import org.elsys.postfix.Calculator;

public abstract class UnaryOperation extends AbstractOperation {

    public UnaryOperation(String name, Calculator calculator) {
        super(name, calculator);
    }

    @Override
    public double execute() {
        return execute(getCalculator().popValue());
    }

    protected abstract double execute(double value);
}
