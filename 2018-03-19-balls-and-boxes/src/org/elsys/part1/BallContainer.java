package org.elsys.part1;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class BallContainer {

	protected List<Ball> container;

	public BallContainer() {
	    this.container = new ArrayList<>();
	}

	/** 
	 * Adds a ball to the container.
	 * @param b the Ball to be added
	 * @return true if b was successfully added
	 */
	public boolean add(Ball b) {
        return b != null && container.add(b);
	}

	/**
	 * Removes a ball from the container.
	 * @param b the Ball to be removed
	 * @return true if b was present in the collection
	 */
	public boolean remove(Ball b) {
	    return container.remove(b);
	}

	/**
	 * Returns the sum of the volumes of all balls in the container.
	 * @return
	 */
	public double getVolume() {
		return container
                .stream()
                .map(Ball::getVolume)
                .collect(Collectors.toList())
                .stream()
                .mapToDouble(Double::doubleValue)
                .sum();
	}

	/**
	 * Returns the total count of balls in the container.
	 * @return
	 */
	public int size() {
		return container.size();
	}

	/**
	 *  Removes all balls from the container.
	 */
	public void clear() {
        container.clear();
	}

	/**
	 * Checks whether a Ball is present in the container.
	 * @param b the Ball to check
	 * @return true if b is present
	 */
	public boolean contains(Ball b) {
	    return container.contains(b);
	}

}