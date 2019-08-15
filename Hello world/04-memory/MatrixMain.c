#include "Matrix.h"
#include <stdio.h>

int main() {
	struct Matrix* matrix = CreateMatrix(COLUMN, 2, 3);
	struct Matrix* matrix2 = CreateMatrix(COLUMN, 2, 3);
	SetMatrixValue(matrix, 1.0f, 0, 0);
	SetMatrixValue(matrix, 2.0f, 0, 1);
	SetMatrixValue(matrix, 3.0f, 0, 2);
	SetMatrixValue(matrix, 4.0f, 1, 0);
	SetMatrixValue(matrix, 5.0f, 1, 1);
	SetMatrixValue(matrix, 6.0f, 1, 2);

	SetMatrixValue(matrix2, 7.0f, 0, 0);
	SetMatrixValue(matrix2, 8.0f, 0, 1);
	SetMatrixValue(matrix2, 9.0f, 0, 2);
	SetMatrixValue(matrix2, 10.0f, 1, 0);
	SetMatrixValue(matrix2, 11.0f, 1, 1);
	SetMatrixValue(matrix2, 12.0f, 1, 2);
	PrintMatrix(matrix);
	printf("\n");
	PrintMatrix(matrix2);
	printf("\n");
	
	//SwapRows(matrix, matrix2, 1, 0);
	//PrintMatrix(matrix);
	//printf("\n");
	//PrintMatrix(matrix2);
	//printf("\n");
}
