import java.util.*;

public class BubbleSort {
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
        sort(numbers, n);
        System.out.println("Sorted: " + Arrays.toString(numbers));
    }

    private static void sort(int[] numbers, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (numbers[j] > numbers[j+1]) {
                    swap(j, j+1, numbers);
                }
            }
        }
    }

    private static void swap(int i, int j, int[] numbers) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}
