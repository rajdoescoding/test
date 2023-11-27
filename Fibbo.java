import java.util.Scanner;

class Fibbo {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int n;
        n=scanner.nextInt();
        System.out.println("Fibonacci series Up to "+n+"terms:");
        for(int i=0;i<n;i++){
            System.out.print(fibonacci(i)+" ");
        }
    }

    private static int fibonacci(int n) {
        if(n <= 1){
            return n;
        }
        int fib = 1,prevFib=0;
        for(int i=2; i<=n; i++){
            int temp = fib;
            fib += prevFib;
            prevFib=temp;
        }
        return fib;
    }
}
