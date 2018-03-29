package org.elsys.gates;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class FullAdderTest {
    private Wire a;

    private Wire b;

    private Wire cIn;

    private Wire sum;

    private Wire cOut;

    private Gate gate;

    @Before
    public void setUp() throws Exception {
        a = new Wire();
        b = new Wire();
        cIn = new Wire();
        sum = new Wire();
        cOut = new Wire();

        gate = GateFactory.makeFullAdder(a, b, cIn, sum, cOut);
    }

    @Test
    public void testIn1TrueIn2False() {
        a.setSignal(true);
        b.setSignal(true);

        assertTrue(sum.getSignal());
    }
}
