package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public class Duplicate extends AbstractOperation implements Operation {

    private static final String DUPLICATE_TOKEN = "dup";

    public Duplicate(Calculator calculator) {
        super(calculator, DUPLICATE_TOKEN);
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        try {
            double lastValue = calculator.popValue();

            calculator.addValue(lastValue);
            calculator.addValue(lastValue);
        } catch (IndexOutOfBoundsException ex) {
            throw new EmptyStackException();
        }
    }
}