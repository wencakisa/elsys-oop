package org.elsys.gates;

public abstract class GateFactory {

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out, String name) {
		CompositeGate xorGate = new CompositeGate(name);

		xorGate.addInput(in1);
		xorGate.addInput(in2);
		xorGate.addOutput(out);

		Wire a = new Wire("XorA");
		Wire b = new Wire("XorB");
		Wire c = new Wire("XorC");

		Gate orGate = new OrGate(in1, in2, a);
		Gate andGate1 = new AndGate(in1, in2, b);
		Gate notGate = new InverterGate(b, c);
		Gate andGate2 = new AndGate(a, c, out);

		xorGate.addGate(orGate);
		xorGate.addGate(andGate1);
		xorGate.addGate(notGate);
		xorGate.addGate(andGate2);

		return xorGate;
	}

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out) {
		return makeXorGate(in1, in2, out, "XorGate");
	}

	public static Gate makeHalfAdder(Wire a, Wire b, Wire s, Wire c, String name) {
		CompositeGate halfAdder = new CompositeGate(name);

		halfAdder.addInput(a);
		halfAdder.addInput(b);
		halfAdder.addOutput(s);
		halfAdder.addOutput(c);

		halfAdder.addGate(new XorGate(a, b, s));
		halfAdder.addGate(new AndGate(a, b, c));

		return halfAdder;
	}

	public static Gate makeHalfAdder(Wire a, Wire b, Wire s, Wire c) {
		return makeHalfAdder(a, b, s, c, "HalfAdder");
	}

	public static Gate makeFullAdder(Wire a, Wire b, Wire cIn, Wire sum, Wire cOut, String name) {
	    CompositeGate fullAdder = new CompositeGate(name);

	    fullAdder.addInput(a);
	    fullAdder.addInput(b);
	    fullAdder.addInput(cIn);
	    fullAdder.addOutput(sum);
	    fullAdder.addOutput(cOut);

	    Wire innerOut1 = new Wire("InnerOut1");
	    Wire innerOut2 = new Wire("InnerOut2");
	    Wire innerOut3 = new Wire("InnerOut3");

	    fullAdder.addGate(new XorGate(a, b, innerOut1));
	    fullAdder.addGate(makeHalfAdder(innerOut1, cIn, sum, innerOut2));
	    fullAdder.addGate(new AndGate(a, b, innerOut3));
	    fullAdder.addGate(new OrGate(innerOut2, innerOut3, cOut));

		return fullAdder;
	}

	public static Gate makeFullAdder(Wire a, Wire b, Wire cIn, Wire sum, Wire cOut) {
		return makeFullAdder(a, b, cIn, sum, cOut, "FullAdder");
	}
	
	public static Gate makeRippleCarryAdder(Wire a[], Wire b[], Wire cIn, Wire sum[], Wire cOut) {
		assert a.length == b.length;
		assert a.length == sum.length;
		int count = a.length;

		CompositeGate rippleCarryAdder = new CompositeGate("RippleCarryAdder");

		rippleCarryAdder.addInput(cIn);
		rippleCarryAdder.addOutput(cOut);

		Wire innerWires[] = generateInnerWires(cIn, cOut, count + 1);

		for (int i = 0; i < count; ++i) {
            rippleCarryAdder.addGate(makeFullAdder(a[i], b[i], innerWires[i], sum[i], innerWires[i + 1]));
        }

        rippleCarryAdder.act();

        return rippleCarryAdder;
	}

	private static Wire[] generateInnerWires(Wire cIn, Wire cOut, int count) {
        int start = 0;

        Wire innerWires[] = new Wire[count];

        innerWires[start++] = cIn;
        for (; start < count; ++start) {
            innerWires[start] = new Wire("InnerWire" + start);
        }
        innerWires[count - 1] = cOut;

        return innerWires;
    }
}
