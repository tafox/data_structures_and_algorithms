import java.util.*;

public class Quicksort {
    public static void main(String[] args) {
        int[] numbers = ReadIntegers.readIntegers();
        System.out.println("Sorting: " + Arrays.toString(numbers));
        sort(numbers, 0, numbers.length-1);
        System.out.println("Sorted: " + Arrays.toString(numbers));
    }

    private static void sort(int[] numbers, int p, int r) {
        if (p < r) {
            int m = partition(numbers, p, r);
            sort(numbers, p, m-1);
            sort(numbers, m+1,r);
        }
    }
    
    private static int partition(int[] numbers, int p, int r) {
        int m = r;
        int j = p;
        int i;
        for (i = p+1; i < r; i++) {
            if (numbers[j] < numbers[m]) {
                j++;
            } else if (numbers[i] < numbers[m]) {
                swap(numbers, j, i);
                j++;
            }        
        }
        if (numbers[m] < numbers[j]) {
            swap(numbers, j, i);
        } else {
            j++;
        }
        return j;
    }

    private static void swap(int[] numbers, int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
