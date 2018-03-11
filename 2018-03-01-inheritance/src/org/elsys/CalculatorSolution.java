package org.elsys;

import java.util.ArrayList;
import java.util.List;

interface AdvancedArithmetic {
    int divisor_sum(int n);
}

class MyCalculator implements AdvancedArithmetic {
    public int divisor_sum(int n) {
        List<Integer> divisors = new ArrayList<>();

        for (int i = n; i > 0; i--) {
            if (n % i == 0) {
                divisors.add(i);
            }
        }

        return divisors.stream().reduce((a, b) -> a + b).get();
    }
}

public class CalculatorSolution {
    public static void main(String[] args) {

    }
}
