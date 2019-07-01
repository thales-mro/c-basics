#include <stdio.h>

#define ARRAY_SIZE 100

void print_array(int array[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void read_array(int array[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
}

void hadamard_product(int array1[], int array2[], int answer[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		answer[i] = array1[i]*array2[i];
	}
}

int main() {
	int n;
	int vector1[ARRAY_SIZE], vector2[ARRAY_SIZE], answer[ARRAY_SIZE];

	scanf("%d", &n);
	read_array(vector1, n);
	read_array(vector2, n);
	hadamard_product(vector1, vector2, answer, n);
	print_array(answer, n);
	
	return 0;
}
