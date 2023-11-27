public class OuterClass2 {
    public static void main(String[] args) {
        //Creating an instance of OuterClass
        OuterClass outer = new OuterClass();

        //Creating an instance of InnerClass1 and InnerClass2
        OuterClass.InnerClass1 inner1 = outer.new InnerClass1();
        OuterClass.InnerClass2 inner2 = outer.new InnerClass2();

        //Calling display method of InnerClass1
        inner1.display();

        //Calling display method of InnerClass2
        inner2.display();
    }
}