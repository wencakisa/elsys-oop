public class BlockingQueueTest {

    private static final int CAPACITY = 5;

    public static void main(String[] args) {
        BlockingQueue<Integer> queue = new BlockingQueue<>(CAPACITY);

        Runnable pusher = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    try {
                        Thread.sleep(100);
                        queue.push(i);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        Runnable popper = new Runnable() {
            @Override
            public void run() {
                while (true) {
                    try {
                        Thread.sleep(100);
                        queue.pop();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        for (int i = 0; i < CAPACITY; i++) {
            new Thread(pusher).start();
            new Thread(popper).start();
        }

        while (true) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("main");
        }
    }
}
