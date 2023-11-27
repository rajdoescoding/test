public class MultiThreadExample {

    public static void main(String[] args) {
        // Create three threads
        Thread thread1 = new Thread(new Task1());
        Thread thread2 = new Thread(new Task2());
        Thread thread3 = new Thread(new Task3());

        // Start the threads
        thread1.start();
        thread2.start();
        thread3.start();
    }

    // Thread 1: Print numbers from 1 to 5
    static class Task1 implements Runnable {
        @Override
        public void run() {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Thread 1: " + i);
                try {
                    Thread.sleep(500); // Sleep for 500 milliseconds
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // Thread 2: Print letters from A to E
    static class Task2 implements Runnable {
        @Override
        public void run() {
            for (char c = 'A'; c <= 'E'; c++) {
                System.out.println("Thread 2: " + c);
                try {
                    Thread.sleep(500); // Sleep for 500 milliseconds
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // Thread 3: Print "Hello" five times
    static class Task3 implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 3: Hello");
                try {
                    Thread.sleep(500); // Sleep for 500 milliseconds
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
