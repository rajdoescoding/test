package FileClass;

import java.io.File;

public class FilePropertiesExample {
    public static void main(String[] args) {
        // Specify the file path
        String filePath = "C:\\Users\\Sudeep Pagui\\OneDrive\\Desktop\\Java Practical\\FileClass\\file.txt";

        // Create a File object
        File file = new File(filePath);

        // Display file properties
        if (file.exists()) {
            System.out.println("File Name: " + file.getName());
            System.out.println("Absolute Path: " + file.getAbsolutePath());
            System.out.println("Size: " + file.length() + " bytes");
            System.out.println("Is Directory: " + file.isDirectory());
            System.out.println("Is File: " + file.isFile());
            System.out.println("Last Modified: " + file.lastModified());
        } else {
            System.out.println("File not found.");
        }
    }
}