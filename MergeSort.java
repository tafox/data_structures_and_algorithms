import java.util.*;

public class MergeSort {
    public static void main(String[] args) {
        int[] numbers = ReadIntegers.readIntegers();
        System.out.println("Sorting: " + Arrays.toString(numbers));
        numbers = sort(numbers);
        System.out.println("Sorted: " + Arrays.toString(numbers));
    }

    private static int[] sort(int[] numbers) {
        int sorted[] = new int[0];
        int p = 0;
        int r = numbers.length;
        if (r != 1) {
            int m = (p+r)/2;
            sorted = merge(sort(Arrays.copyOfRange(numbers, p, m)), sort(Arrays.copyOfRange(numbers, m, r)));
        } else {
            return numbers;
        }
        return sorted;
    }
    
    private static int[] merge(int[] a, int[] b) {
        int lenA = a.length;
        int lenB = b.length;
        int n = lenA + lenB;
        int sorted[] = new int[n];
        for (int i = 0, j = 0, k = 0; k < n; k++) {
            if (i < lenA && j < lenB) {
                if (a[i] <= b[j]) {
                    sorted[k] = a[i];
                    i++;
                } else {
                    sorted[k] = b[j];
                    j++;
                }
            } else if (i >= lenA) {
                for (; j < lenB; j++, k++) {
                   sorted[k] = b[j];    
                } 
                return sorted;
            } else if (j >= lenB) {
                for (; i < lenA; i++, k++) {
                   sorted[k] = a[i];    
                } 
                return sorted;
            }
        }
        return sorted;
    }
}
