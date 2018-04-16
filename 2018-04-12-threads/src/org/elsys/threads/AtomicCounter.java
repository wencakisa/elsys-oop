package org.elsys.threads;

import java.util.concurrent.atomic.AtomicLong;

public class AtomicCounter {

    private static final int THREADS = 10;

    private static AtomicLong counter = new AtomicLong(0);

    public static void main(String[] args) {
        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) {
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    System.out.println("Runnable started ...");

                    for (int j = 0; j < 1000000; j++) {
                        counter.incrementAndGet();
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
