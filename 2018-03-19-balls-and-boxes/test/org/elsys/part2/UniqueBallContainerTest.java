package org.elsys.part2;

import static org.junit.Assert.*;

import org.elsys.part1.Ball;
import org.elsys.part1.BallContainer;
import org.junit.Test;

public class UniqueBallContainerTest {

    @Test
    public void testAdd() {
        BallContainer container = new UniqueBallContainer();
        Ball ball1 = new Ball(10);

        assertTrue(container.add(ball1));
        assertFalse(container.add(ball1));
    }

    @Test
    public void testVolume() {
        BallContainer container = new UniqueBallContainer();

        Ball ball = new Ball(10);
        container.add(ball);
        container.add(ball);
        assertEquals(10, container.getVolume(), 0.01);
    }

}
