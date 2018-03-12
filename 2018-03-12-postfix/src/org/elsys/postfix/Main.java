package org.elsys.postfix;

import org.elsys.postfix.operation.Negate;
import org.elsys.postfix.operation.Square;

public class Main {

    public static void main(String[] args) {
	    Calculator calculator = new Calculator(System.in, System.out);

        calculator.addOperation(new Negate(calculator));
        calculator.addOperation(new Square(calculator));

	    calculator.run("quit");
    }
}
