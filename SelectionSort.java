import java.util.*;

public class SelectionSort {
    public static void main(String[] args) {
        int[] numbers = ReadIntegers.readIntegers();
        System.out.println("Sorting: " + Arrays.toString(numbers));
        sort(numbers, numbers.length);
        System.out.println("Sorted: " + Arrays.toString(numbers));
    }
    
    private static void sort(int[] numbers, int n) {
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i+1; j < n; j++) {
                if (numbers[j] < numbers[min]) {
                    min = j;    
                }
            }
            swap(min, i, numbers);
        }
    }

    private static void swap(int i, int j, int numbers[]) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
