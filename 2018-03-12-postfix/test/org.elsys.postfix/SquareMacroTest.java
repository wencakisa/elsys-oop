package org.elsys.postfix;

import org.junit.Test;

public class SquareMacroTest extends CalculatorAbstractTest {

	@Test
	public void test() {
		input("\\square");
		input("dup");
		input("*");
		input("def");
		
		input("2");
		input("square");

        inputCtrlC();

        runCalculator();
		assertCalculatorLastValue(4.0);
	}

}
