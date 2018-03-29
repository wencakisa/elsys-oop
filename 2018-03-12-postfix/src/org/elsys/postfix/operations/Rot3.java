package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Rot3 extends AbstractOperation implements Operation {

    private static final String ROT3_TOKEN = "rot3";

    public Rot3(Calculator calculator) {
        super(calculator, ROT3_TOKEN);
    }

    @Override
    public void calculate() {
        Operation swap = new Swap(getCalculator());

        swap.calculate();
        swap.calculate();
    }
}
