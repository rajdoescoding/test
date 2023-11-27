import java.util.Scanner;

public class Fibonacci2 {
    // Function to calculate Fibonacci number using recursion
    public static int calculateFibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return calculateFibonacciRecursive(n - 1) + calculateFibonacciRecursive(n - 2);
    }

    // Function to calculate Fibonacci number using non-recursion
    public static int calculateFibonacciNonRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0;
        int b = 1;
        int c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number to find the Fibonacci series using recursive function: ");
        int n = scanner.nextInt();
        System.out.println("The " + n + "th Fibonacci number using recursive function is: " + calculateFibonacciRecursive(n));

        System.out.println("Enter a number to find the Fibonacci series using non-recursive function: ");
        n = scanner.nextInt();
        System.out.println("The " + n + "th Fibonacci number using non-recursive function is: " + calculateFibonacciNonRecursive(n));

        scanner.close();
    }
}