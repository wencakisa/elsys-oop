package org.elsys.postfix;

import org.junit.Test;

public class ConstantMacroTest extends CalculatorAbstractTest {

    @Test
    public void test() {
        input("\\add1");
        input("1 +");
        input("def");

        input("2");
        input("add1");

        inputCtrlC();

        runCalculator();
        assertCalculatorLastValue(3.0);
    }

}
