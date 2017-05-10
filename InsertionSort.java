import java.util.*;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Insert number of elements: ");
        int n = in.nextInt();
        int numbers[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Insert element " + Integer.toString(i+1) + ": ");
            numbers[i] = in.nextInt();
        }
        System.out.println("Sorting: " + Arrays.toString(numbers));
        sort(numbers);
        System.out.println("Sorted: " + Arrays.toString(numbers));
    }

    private static void sort(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            int key = numbers[i];
            int j = i-1;
            while (j >= 0 && key < numbers[j]) {
                swap(j,j+1,numbers);
                j--;
            }
        }
    }

    private static void swap(int i, int j, int[] numbers) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
