package org.elsys;

import java.util.Comparator;

public class TestClass implements Comparator<TestClass> {

    private int value;

    public TestClass() {
        this.value = -1;
    }

    public TestClass(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    @Override
    public int compare(TestClass t0, TestClass t1) {
        return t0.getValue() - t1.getValue();
    }
}
