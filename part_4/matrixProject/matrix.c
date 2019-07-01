#include "matrix.h"
#include <stdio.h>

void printMatrix(matrix m) {
	int i, j;
	for(i = 0; i < m.nRows; i++) {
		for(j = 0; j < m.nColumns; j++)
			printf("%f ", m.elements[i][j]);
		printf("\n");
	}
}

matrix newMatrix() {
	int i, j;
	matrix m;
	m.nRows = 0;
	m.nColumns = 0;

	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			m.elements[i][j] = 0.0f;

	return m;
}

matrix readMatrix() {
	int i, j, r, c;
	matrix m;

	printf("Insert to integers representing the number of rows and number of columns of the matrix: ");
	scanf("%d %d", &r, &c);
	if (r > 100)
		r = 100;
	if (c > 100)
		c = 100;
	if (r < 0 || c < 0) {
		r = 0;
		c = 0;
	}

	m.nRows = r;
	m.nColumns = c;

	printf("Insert the matrix elements:\n");
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			scanf("%f", &m.elements[i][j]);

	return m;
}

int isMultiplicationPossible(matrix a, matrix b) {
	return a.nColumns == b.nRows;
}

matrix matrixMultiplication(matrix a, matrix b) {
	matrix c;
	int i, j, k;

	c = newMatrix();
	if (isMultiplicationPossible(a, b)) {
		c.nRows = a.nRows;
		c.nColumns = b.nColumns;

		for(i = 0; i < c.nRows; i++) {
			for(j = 0; j < c.nColumns; j++) {
				c.elements[i][j] = 0.0f;
				for(k = 0; k < a.nColumns; k++) {
					c.elements[i][j] += a.elements[i][k]*b.elements[k][j];
				}
			}
		}
	}

	return c;
}
