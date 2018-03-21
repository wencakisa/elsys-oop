package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Literal extends AbstractOperation implements Operation {
    private double value;

    public Literal(Calculator calculator, double value) {
        super(calculator, "#LITERAL#");

        this.value = value;
    }

    @Override
    public void calculate() {
        getCalculator().addValue(value);
    }
}
