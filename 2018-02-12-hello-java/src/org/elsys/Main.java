package org.elsys;

public class Main {

    private static String WORLD_TYPE = "Java";

    public static void main(String[] args) {
        System.out.printf("Hello, %s World\n", WORLD_TYPE);

        int array[] = new int[] { 0, 1, 2, 3, 4 };

        System.out.println(average(array));
        modify(array);
        System.out.println(average(array));
    }

    private static int average(int array[]) {
        int sum = 0;

        for (int num : array) {
            sum += num;
        }

        return sum / array.length;
    }

    private static void modify(int array[]) {
        array[0] = 10;
    }
}
