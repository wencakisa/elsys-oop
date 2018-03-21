package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Swap extends AbstractOperation implements Operation {
    public Swap(Calculator calculator) {
        super(calculator, "swap");
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        double lastValue = calculator.popValue();
        double preLastValue = calculator.popValue();

        calculator.addValue(lastValue);
        calculator.addValue(preLastValue);
    }
}
