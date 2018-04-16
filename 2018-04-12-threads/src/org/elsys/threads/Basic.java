package org.elsys.threads;

public class Basic extends Thread {

    private static final int THREADS = 10;

    @Override
    public void run() {
        System.out.println("Thread started ...");

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Thread finished ...");
    }

    public static void main(String[] args) {
        Thread[] threads = new Thread[THREADS];

        for (int i = 0; i < THREADS; i++) {
            threads[i] = new Basic();
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
