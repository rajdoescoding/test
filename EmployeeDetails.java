import java.util.Scanner;

class Employee {
    String name;
    int age;
    String department;

    // constructor with three parameters
    public Employee(String name, int age, String department) {
        this.name = name;
        this.age = age;
        this.department = department;
    }

    // method to display employee details
    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
    }
}

public class EmployeeDetails {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the name of the employee: ");
        String name = scanner.nextLine();

        System.out.println("Enter the age of the employee: ");
        int age = scanner.nextInt();
        scanner.nextLine(); // consume newline not consumed by nextInt()

        System.out.println("Enter the department of the employee: ");
        String department = scanner.nextLine();

        Employee employee = new Employee(name, age, department);
        employee.display();
    }
}
