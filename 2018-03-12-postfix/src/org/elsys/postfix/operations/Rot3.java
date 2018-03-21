package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Rot3 extends AbstractOperation implements Operation {
    public Rot3(Calculator calculator) {
        super(calculator, "rot3");
    }

    @Override
    public void calculate() {
        Operation swap = new Swap(getCalculator());

        swap.calculate();
        swap.calculate();
    }
}
