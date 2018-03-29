package org.elsys.gates;

import java.util.ArrayList;
import java.util.List;

public class Wire {

	private List<Gate> gates;
	private boolean state;
	private String name;

	public Wire(String name) {
		this.name = name;
		this.state = false;
		this.gates = new ArrayList<>();
	}

	public String getName() {
		return name;
	}

	public void setSignal(boolean state) {
		if (state != this.state) {
			this.state = state;
            notifyGates();
        }
    }

	public boolean getSignal() {
		return state;
	}

	public void connect(Gate gate) {
		if (!gates.contains(gate)) {
			gates.add(gate);
		}
	}

	private void notifyGates() {
		for (Gate gate : gates) {
			gate.act();
		}
	}

	public static class Helper {
        public static void intToWires(int val, Wire[] w) {
            for (int i = 0; i < w.length; ++i) {
                int bit = 1 << i;
                w[i].setSignal((bit & val) != 0);
            }
        }

        public static int wiresToInt(Wire[] w) {
            int result = 0;

            for (int i = 0; i < w.length; ++i) {
                if (w[i].getSignal()) {
                    int bit = 1 << i;
                    result = result | bit;
                }
            }

            return result;
        }
    }
}
