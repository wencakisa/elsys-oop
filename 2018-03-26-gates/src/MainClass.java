import org.elsys.gates.GateFactory;
import org.elsys.gates.Wire;

import java.util.Scanner;

public class MainClass {
    private static final int MAX_BITS = 8;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextShort()) {
            short a = in.nextShort();
            short b = in.nextShort();

            Wire aToWires[] = new Wire[MAX_BITS];
            Wire bToWires[] = new Wire[MAX_BITS];
            Wire cIn        = new Wire("cIn");
            Wire sum[]      = new Wire[MAX_BITS];
            Wire cOut       = new Wire("cOut");

            for (int i = 0; i < MAX_BITS; ++i) {
                aToWires[i] = new Wire("a" + i);
                bToWires[i] = new Wire("b" + i);
                sum[i]      = new Wire("sum" + i);
            }

            Wire.Helper.intToWires(a, aToWires);
            Wire.Helper.intToWires(b, bToWires);

            GateFactory.makeRippleCarryAdder(aToWires, bToWires, cIn, sum, cOut);

            System.out.println("Sum = " + Wire.Helper.wiresToInt(sum));
        }
    }
}
