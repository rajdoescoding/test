package FileClass;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Hashtable;

public class PhoneBookLoader {
    public static void main(String[] args) {
        // Specify the file path
        String filePath = "path/to/your/phonebook.txt";

        // Create a Hashtable to store phone numbers and names
        Hashtable<String, String> phoneBook = new Hashtable<>();

        // Load data from the text file
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                // Assuming each line has the format: "phone_number name"
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    String phoneNumber = parts[0];
                    String name = parts[1];
                    phoneBook.put(phoneNumber, name);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Display the loaded phone book
        System.out.println("Phone Book:");
        for (String phoneNumber : phoneBook.keySet()) {
            System.out.println("Phone Number: " + phoneNumber + ", Name: " + phoneBook.get(phoneNumber));
        }
    }
}
