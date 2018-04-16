package org.elsys.threads;

public class BasicWithRunnable {

    private static final int THREADS = 10;

    public static void main(String[] args) {
        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) {
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    System.out.println("Runnable started ...");

                    try {
                        Thread.sleep(3000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
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

        System.out.println("Program finished!");
    }
}
