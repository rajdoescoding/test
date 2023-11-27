class Example {

    // Method Overloading
    public void display(int value) {
        System.out.println("Integer: " + value);
    }

    public void display(float value) {
        System.out.println("Float: " + value);
    }

    public void display(String value) {
        System.out.println("String: " + value);
    }

    // Constructor Overloading
    public Example() {
        System.out.println("Example object created with default constructor");
    }

    public Example(int a) {
        System.out.println("Example object created with int parameter constructor");
    }

    public Example(String a) {
        System.out.println("Example object created with String parameter constructor");
    }
}

public class Main {

    public static void main(String[] args) {
        Example e = new Example();
        e.display(10);
        e.display(12.5f);
        e.display("Hello, World!");

        Example e1 = new Example(20);
        Example e2 = new Example("jai ram");
    }
}