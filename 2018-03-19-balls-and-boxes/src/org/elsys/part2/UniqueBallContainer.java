package org.elsys.part2;

import org.elsys.part1.Ball;
import org.elsys.part1.BallContainer;

public class UniqueBallContainer extends BallContainer {
    public UniqueBallContainer() {
        super();
    }

    @Override
    public boolean add(Ball b) {
        return !super.contains(b) && super.add(b);
    }
}
