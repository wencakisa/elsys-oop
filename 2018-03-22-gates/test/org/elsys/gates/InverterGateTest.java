package org.elsys.gates;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class InverterGateTest {

    private Wire in;

    private Wire out;

    private Gate gate;

    @Before
    public void setUp() throws Exception {
        in = new Wire();
        in.setSignal(true);

        out = new Wire();

        gate = new InverterGate(in, out);

        gate.act();
    }

    @Test
    public void testInTrueOutFalse() {
        assertFalse(out.getSignal());
    }
}