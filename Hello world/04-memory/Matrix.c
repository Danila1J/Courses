#include "Matrix.h"
#include <stdio.h>
#include <math.h>

void InitMatrix(struct Matrix*const matrix, int numberFrom,int numberTo){
    int temp=numberFrom;
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->cols; j++)
        {
            for (int k = numberFrom; k <=numberTo ; ++k) {
                if(temp>numberTo) temp=numberFrom;
                SetMatrixValue(matrix,temp,i,j);
                temp++;
                break;
            }
        }
    }
}

struct Matrix* CreateVirtualMatrix(struct Matrix* structMatrixBase, size_t indRow, size_t indCol, size_t rows, size_t cols) {
	struct Matrix* structMatrix = malloc(sizeof(struct Matrix));
	if (structMatrix == NULL) return NULL;
	structMatrix->data = structMatrixBase;
	structMatrix->type = VIRTUAL;
	structMatrix->shiftCol = indCol;
	structMatrix->shiftRow = indRow;
	if (indRow + rows <= structMatrixBase->rows &&
		indCol + cols <= structMatrixBase->cols) {
		structMatrix->cols = cols;
		structMatrix->rows = rows;
	}
	else {
		structMatrix->rows = indRow + rows - structMatrixBase->rows;
		structMatrix->cols = indCol + cols - structMatrixBase->cols;
	}
	return structMatrix;
}

struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols) {
	struct Matrix* matr = malloc(sizeof(struct Matrix));
	if (matr == NULL) {
		return NULL;
	}
	if (rows == 0 || cols == 0) {
		matr->data = NULL;
		matr->rows = 0;
		matr->cols = 0;
		matr->shiftCol = 0;
		matr->shiftRow = 0;
		matr->type = FLAT;
		return matr;
	}
	matr->type = type;
	matr->rows = rows;
	matr->cols = cols;
	matr->shiftCol = 0;
	matr->shiftRow = 0;
	switch (type) {
	case FLAT:
		matr->data = calloc(rows * cols, sizeof(float));
		break;
	case ROW: {
		float** masRow = malloc(rows * sizeof(float*));
		if (masRow == NULL) {
			free(matr);
			return NULL;
		}
		for (size_t i = 0; i < rows; ++i) {
			masRow[i] = calloc(cols, sizeof(float));
			if (masRow[i] == NULL) {
				for (size_t j = i; j>0; --j)
				{
					free(masRow[j]);
				}
				return NULL;
			}
		}
		matr->data = masRow;
		break;
	}
	case COLUMN: {
		float** masColumn = malloc(cols * sizeof(float*));
		if (masColumn == NULL) {
			free(matr);
			return NULL;
		}
		for (size_t i = 0; i < cols; ++i) {
			masColumn[i] = calloc(rows, sizeof(float));
			if (masColumn[i] == NULL) {
				for (size_t j = i; j > 0; --j)
				{
					free(masColumn[j]);
				}
				return NULL;
			}
		}
		matr->data = masColumn;
		break;
	}
	default:
		return NULL;
	}
	return matr;
}

void SetMatrixValue(struct Matrix* matrix,float f, size_t indRow, size_t indCol) {
	switch (matrix->type) {
	case FLAT: {
		float* mf = (float*)matrix->data;
		mf[(indRow)* matrix->cols + indCol]=f;
		break;
	}
	case ROW: {
		float** mf = (float**)matrix->data;
		float* r = (float*)mf[indRow];
		r[indCol]=f;
		break;
	}
	case COLUMN: {
		float** mf = (float**)matrix->data;
		float* c = (float*)mf[indCol];
		c[indRow]=f;
		break;
	}
	case VIRTUAL:
		GetMatrixValue(matrix, indRow + matrix->shiftRow, indCol + matrix->shiftCol);
		break;
	}
}

float GetMatrixValue(const struct Matrix* structMatrix, size_t indRow, size_t indCol) {
	switch (structMatrix->type) {
	case FLAT: {
		float* mf = (float*)structMatrix->data;
		return mf[(indRow)* structMatrix->cols + indCol];
	}
	case ROW: {
		float** mf = (float**)structMatrix->data;
		float* r = (float*)mf[indRow];
		return r[indCol];
	}
	case COLUMN: {
		float** mf = (float**)structMatrix->data;
		float* c = (float*)mf[indCol];
		return c[indRow];
	}
	case VIRTUAL:
		GetMatrixValue(structMatrix, indRow + structMatrix->shiftRow, indCol + structMatrix->shiftCol);
		break;
	}
	return nanf("");
}

void DestroyMatrix(struct Matrix* structMatrix) {
	float** f = structMatrix->data;
	switch (structMatrix->type)
	{
	case FLAT: {
		free(structMatrix->data);
		break; 
	}
	case ROW: {
		for (size_t i = 0; i < structMatrix->rows; ++i) {
			free(f[i]);
		}
		break;
	}
	case COLUMN: {
		for (size_t i = 0; i < structMatrix->cols; ++i) {
			free(f[i]);
		}
		break;
	}
	default:
		break;
	}
	free(structMatrix);
}

void SwapRows(struct Matrix* matrix_1, struct Matrix* matrix_2, size_t indRow_1, size_t indRow_2) {
	if (matrix_1->cols != matrix_2->cols && matrix_1->rows != matrix_2->rows) return;
	if (matrix_1->type == ROW && matrix_2->type == ROW) {
		float** first = (float**)matrix_1->data;
		float** second = (float**)matrix_2->data;
		float* temp = second[indRow_2];
		second[indRow_2] = first[indRow_1];
		first[indRow_1] = temp;
	}
	else {
		for (size_t i = 0; i < matrix_1->cols; ++i)
		{
			float temp = GetMatrixValue(matrix_2, indRow_2, i);
			SetMatrixValue(matrix_2, GetMatrixValue(matrix_1, indRow_1, i), indRow_2, i);
			SetMatrixValue(matrix_1, temp, indRow_1, i);
		}
	}

}

void PrintMatrix(const struct Matrix* const structMatrix) {
	for (size_t i = 0; i < structMatrix->rows; i++)
	{
		for (size_t j = 0; j < structMatrix->cols; j++)
		{
			printf("%.2f ",GetMatrixValue(structMatrix, i, j));
			if (j == structMatrix->cols - 1) {
				printf("\n");
			}
		}
	}
}
