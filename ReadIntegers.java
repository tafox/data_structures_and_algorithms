import java.util.*;
import java.io.*;

public class ReadIntegers {

    public static int[] readIntegers() { 
        Scanner in = new Scanner(System.in);
        //System.out.print("Input number of elements: ");
        int n = in.nextInt();
        int[] numbers = new int[n];
        //System.out.print("Input " + Integer.toString(n) + " elements: ");
        for (int i = 0; i < n && in.hasNextInt(); i++) {
            numbers[i] = in.nextInt();
        }
        return numbers;
    }

    public static int[] readIntegersFromFile(String fileName) { 
        Scanner in;
        try {
            File file = new File(fileName);
            in = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("File: " + fileName + " not found.");
            return new int[0];
        }
        int n = in.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n && in.hasNextInt(); i++) {
            numbers[i] = in.nextInt();
        }
        return numbers;
    }
}
