package org.elsys.gates;

public abstract class NandFactory {

	public static Gate makeNotGate(Wire in, Wire out, String name) {
		CompositeGate notGate = new CompositeGate(name);

		notGate.addInput(in);
		notGate.addOutput(out);

		notGate.addGate(new NandGate(in, in, out));

		return notGate;
	}

	public static Gate makeNotGate(Wire in, Wire out) {
		return makeNotGate(in, out, "NandNot");
	}

	public static Gate makeAndGate(Wire in1, Wire in2, Wire out, String name) {
        CompositeGate andGate = new CompositeGate(name);

        andGate.addInput(in1);
        andGate.addInput(in2);
        andGate.addOutput(out);

        Wire innerOut = new Wire("InnerOut");

        andGate.addGate(new NandGate(in1, in2, innerOut));
        andGate.addGate(makeNotGate(innerOut, out));

        return andGate;
	}

	public static Gate makeAndGate(Wire in1, Wire in2, Wire out) {
		return makeAndGate(in1, in2, out, "NandAnd");
	}

	public static Gate makeOrGate(Wire in1, Wire in2, Wire out, String name) {
        CompositeGate orGate = new CompositeGate(name);

        orGate.addInput(in1);
        orGate.addInput(in2);
        orGate.addOutput(out);

        Wire innerOut1 = new Wire("InnerOut1");
        Wire innerOut2 = new Wire("InnerOut2");

        orGate.addGate(makeNotGate(in1, innerOut1));
        orGate.addGate(makeNotGate(in2, innerOut2));
        orGate.addGate(new NandGate(innerOut1, innerOut2, out));

        return orGate;
	}

	public static Gate makeOrGate(Wire in1, Wire in2, Wire out) {
		return makeOrGate(in1, in2, out, "NandOr");
	}

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out, String name) {
        CompositeGate xorGate = new CompositeGate(name);

        xorGate.addInput(in1);
        xorGate.addInput(in2);
        xorGate.addOutput(out);

        Wire innerOut1 = new Wire("InnerOut1");
        Wire innerOut2 = new Wire("InnerOut2");
        Wire innerOut3 = new Wire("InnerOut3");

        xorGate.addGate(new NandGate(in1, in2, innerOut1));
        xorGate.addGate(new NandGate(in1, innerOut1, innerOut2));
        xorGate.addGate(new NandGate(in2, innerOut1, innerOut3));
        xorGate.addGate(new NandGate(innerOut2, innerOut3, out));

        return xorGate;
	}

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out) {
		return makeXorGate(in1, in2, out, "NandXor");
	}

}
