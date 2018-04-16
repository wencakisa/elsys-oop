package org.elsys.threads;

public class CounterExample {

    private static final int THREADS = 10;

    private static long counter = 0;

    private static final Object lock = new Object();

    public static void main(String[] args) {
        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) {
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    System.out.println("Runnable started ...");

                    for (int j = 0; j < 1000000; j++) {
                        synchronized (lock) {
                            counter++;
                        }
                    }

                    System.out.println("Runnable finished ...");
                }
            };

            threads[i] = new Thread(runnable);
        }

        for (int i = 0; i < THREADS; i++) {
            threads[i].start();
        }

        for (int i = 0; i < THREADS; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Program finished! [" + counter + "]");
    }
}
