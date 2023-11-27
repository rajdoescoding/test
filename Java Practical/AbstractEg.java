abstract class Animal {
    abstract void makeSound();

    void eat() {
        System.out.println("The animal is eating.");
    }
}

class Dog extends Animal implements Eating {
    void makeSound() {
        System.out.println("The dog barks.");
    }

    public void eat() {
        System.out.println("The dog is eating.");
    }
}

interface Eating {
    void eat();
}

public class AbstractEg {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.makeSound();
        dog.eat();
    }
}