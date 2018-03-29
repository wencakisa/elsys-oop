package org.elsys.gates;

import java.util.List;

public interface Gate {

    void act();

    List<Wire> getInputs();
    List<Wire> getOutputs();
}
