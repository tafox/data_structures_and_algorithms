#include <stdio.h>
#include <stdlib.h>

int read_array(int* array)
{
	int i, num, out;
	for (i = 0; scanf("%d", &num) != EOF; i++) {
		array[i] = num;
	}
	return i;
}

void print_array(int* array, int len)
{
	int i;
	for (i = 0; i < len-1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

void swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* array, int len)
{
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i+1; j < len; j++) {
			if (array[j] < array[min])
				min = j;
		}
		swap(array+i, array+min);
	}
}

int main()
{
	int len;
	int* array = malloc(sizeof(int)*100);
	len = read_array(array);
	print_array(array, len);
	sort(array, len);
	print_array(array, len);
	return 0;
}
