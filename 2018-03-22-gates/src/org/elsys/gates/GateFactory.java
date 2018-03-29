package org.elsys.gates;

public abstract class GateFactory {

    public static Gate makeXor(Wire in1, Wire in2, Wire out) {
        CompositeGate compositeGate = new CompositeGate();

        compositeGate.addInput(in1);
        compositeGate.addInput(in2);
        compositeGate.addOutput(out);

        Wire a = new Wire();
        Wire b = new Wire();
        Wire c = new Wire();

        Gate orGate = new OrGate(in1, in2, a);
        Gate andGate1 = new AndGate(in1, in2, b);
        Gate notGate = new InverterGate(b, c);
        Gate andGate2 = new AndGate(a, c, out);

        compositeGate.addGate(orGate);
        compositeGate.addGate(andGate1);
        compositeGate.addGate(notGate);
        compositeGate.addGate(andGate2);

        return compositeGate;
    }

    public static Gate makeHalfAdder(Wire in1, Wire in2, Wire out1, Wire out2) {
        CompositeGate compositeGate = new CompositeGate();

        compositeGate.addInput(in1);
        compositeGate.addInput(in2);
        compositeGate.addOutput(out1);
        compositeGate.addOutput(out2);

        Wire a = new Wire();
        Wire b = new Wire();

        Gate orGate = new OrGate(in1, in2, b);
        Gate andGate1 = new AndGate(in1, in2, out2);
        Gate notGate = new InverterGate(out2, b);
        Gate andGate2 = new AndGate(a, b, out1);

        compositeGate.addGate(orGate);
        compositeGate.addGate(andGate1);
        compositeGate.addGate(notGate);
        compositeGate.addGate(andGate2);

        return compositeGate;
    }

    public static Gate makeFullAdder(Wire a, Wire b, Wire cIn, Wire sum, Wire cOut) {
        CompositeGate compositeGate = new CompositeGate();

        compositeGate.addInput(a);
        compositeGate.addInput(b);
        compositeGate.addInput(cIn);
        compositeGate.addOutput(sum);
        compositeGate.addOutput(cOut);

        Wire s = new Wire();
        Wire c1 = new Wire();
        Wire c2 = new Wire();

        Gate halfAdder1 = makeHalfAdder(b, cIn, s, c1);
        Gate halfAdder2 = makeHalfAdder(a, s, sum, c2);
        Gate orGate = new OrGate(c1, c2, cOut);

        compositeGate.addGate(halfAdder1);
        compositeGate.addGate(halfAdder2);
        compositeGate.addGate(orGate);

        return compositeGate;
    }
}