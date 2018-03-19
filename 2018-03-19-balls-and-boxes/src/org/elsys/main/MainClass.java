package org.elsys.main;

import org.elsys.part1.Ball;
import org.elsys.part1.BallContainer;
import org.elsys.part1.Box;
import org.elsys.part1.Color;

import java.util.Iterator;
import java.util.Scanner;

public class MainClass {
    private static final double BOX_INITIAL_CAPACITY = 10;
    private static final String DELIMITER = " ";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Box box = new Box(BOX_INITIAL_CAPACITY);

        String line = in.nextLine();

        for (String current : line.split(DELIMITER)) {

            double volume = Double.parseDouble(current);
            Ball ball = new Ball(volume);
            if (volume % 2 != 0) {
                ball.setColor(Color.BLACK);
            }

            box.add(ball);
        }

        BallContainer ballContainer = new BallContainer();

        Iterator<Ball> ballIterator = box.getBallsFromSmallest();

        while (ballIterator.hasNext()) {
            ballContainer.add(ballIterator.next());
        }

        if (box.size() == ballContainer.size()) {
            System.out.println("success");
        }
    }
}
