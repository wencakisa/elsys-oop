package org.elsys.postfix.operation;

import org.elsys.postfix.Calculator;

public abstract class AbstractOperation implements Operation {

    private String name;

    private Calculator calculator;

    public AbstractOperation(String name, Calculator calculator) {
        this.name = name;
        this.calculator = calculator;
    }

    @Override
    public String getName() {
        return name;
    }

    public Calculator getCalculator() {
        return calculator;
    }
}
