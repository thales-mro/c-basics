#include <stdio.h>
#include "matrix.h"

int main() {
	matrix a, b, mult;
	
	printf("Creating matrix A:\n");
	a = readMatrix();
	printf("Creating matrix B:\n");
	b = readMatrix();
	printf("\nReading matrix A:\n");
	printMatrix(a);
	printf("\nReading matrix B:\n");
	printMatrix(b);	
	
	printf("\nIs multiplication between A and B possible? %d\n", isMultiplicationPossible(a, b));
	printf("Multiplication Result:\n");
	mult = matrixMultiplication(a, b);
	printMatrix(mult);

	return 0;
}
