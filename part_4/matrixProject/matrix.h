#define MAX 100

typedef struct {
	int nRows;
	int nColumns;
	float elements[MAX][MAX];
}matrix;

void printMatrix(matrix m);

matrix newMatrix();

matrix readMatrix();

int isMultiplicationPossible(matrix A, matrix B);

matrix matrixMultiplication(matrix A, matrix B);
