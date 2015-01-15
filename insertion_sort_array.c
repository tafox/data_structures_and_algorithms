#include <stdio.h>

#define N 100

int read_array(int array[]) 
{
	int c, i;
	for (i = 0; scanf("%d", &c) != EOF; i++)
		array[i] = c;
	return i;
}

void print_array(int array[], int len) 
{
	for (int i = 0; i < len; i++)
		printf("%d, ", array[i]);
	printf("\n");
}

void insert(int loc, int array[], int len)
{
	int i = loc-1;
	for (;array[i] > array[loc] && i >= 0;i--)
		;
	i++;
	int move = array[loc];
	int temp = array[i];
	int temp2;
	for (int j = i+1; j <= loc; j++) {
		temp2 = array[j];
		array[j] = temp;
		temp = temp2;
	}
	array[i] = move;
}

void sort(int array[], int len)
{
	for (int i = 0; i < len; i++)
		insert(i, array, len);
}

int main() 
{
	int array[N];
	int len = read_array(array);
	print_array(array, len);
	sort(array, len);
	print_array(array, len);
	return 0;
}
