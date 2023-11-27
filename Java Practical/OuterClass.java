//Java program to create inner classes
class OuterClass {
    int x = 10;

    //Inner class 1
    class InnerClass1 {
        void display() {
            System.out.println("Inner Class 1 Display");
            System.out.println("x: " + x);
        }
    }

    //Inner class 2
    class InnerClass2 {
        void display() {
            System.out.println("Inner Class 2 Display");
            System.out.println("x: " + x);
        }
    }
}

