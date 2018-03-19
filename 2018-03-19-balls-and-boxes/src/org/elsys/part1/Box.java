package org.elsys.part1;

import java.util.Comparator;
import java.util.Iterator;

public class Box extends BallContainer {

	private double capacity;

	public Box(double capacity) {
        super();
        this.capacity = capacity;
	}

    @Override
    public boolean add(Ball b) {
        boolean result = super.add(b);

        if (getVolume() > capacity) {
            super.remove(b);
//            throw new BallContainerException();
            return false;
        }

        return result;
    }

    public Iterator<Ball> getBallsFromSmallest() {
        container.sort(Comparator.comparing(Ball::getVolume));

        return container.iterator();
	}

}