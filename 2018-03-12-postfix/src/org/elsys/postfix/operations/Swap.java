package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public class Swap extends AbstractOperation implements Operation {

    private static final String SWAP_TOKEN = "swap";

    public Swap(Calculator calculator) {
        super(calculator, SWAP_TOKEN);
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        try {
            double lastValue = calculator.popValue();
            double preLastValue = calculator.popValue();

            calculator.addValue(lastValue);
            calculator.addValue(preLastValue);
        } catch (IndexOutOfBoundsException ex) {
            throw new EmptyStackException();
        }
    }
}
