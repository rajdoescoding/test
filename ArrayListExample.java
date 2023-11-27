package FileClass;

import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        // Create an ArrayList of Strings
        ArrayList<String> arrayList = new ArrayList<>();

        // Add elements to the ArrayList
        arrayList.add("Element 1");
        arrayList.add("Element 2");
        arrayList.add("Element 3");

        // Display elements
        System.out.println("ArrayList Elements:");
        for (String element : arrayList) {
            System.out.println(element);
        }
    }
}