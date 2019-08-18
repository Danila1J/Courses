#include "Matrix.h"
#include <stdio.h>

int main() {
	struct Matrix* matrix = CreateMatrix(FLAT, 2, 3);
	struct Matrix* matrix2 = CreateMatrix(COLUMN, 2, 3);

	InitMatrix(matrix,1,6);
    InitMatrix(matrix2,7,12);

	PrintMatrix(matrix);
	printf("\n");
	PrintMatrix(matrix2);
	printf("\n");
	
	SwapRows(matrix, matrix2, 1, 0);

	PrintMatrix(matrix);
	printf("\n");
	PrintMatrix(matrix2);
	printf("\n");
}
