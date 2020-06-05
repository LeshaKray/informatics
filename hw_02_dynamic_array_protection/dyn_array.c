#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]); 

	printf("\n"); 
}

void read_array(int* array, int n) {
	printf("Enter values: "); 

	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]); 
}

void remove_value_array(int* array, int* n, int value) {
	int j = 0; 

	for (int i = 0; i < *n; i++) 
		if (array[i] != value) 
			array[j++] = array[i]; 

	*n = j; 
}

int main() {
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int* array = (int*)malloc(n * sizeof(int));
	read_array(array, n); 


	remove_value_array(array, &n, 1); 

	printf("Changed array: ");
	print_array(array, n);

	return 0; 
}
