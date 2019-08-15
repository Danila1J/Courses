#include "Matrix.h"
#include <stdio.h>

struct Matrix *CreateVirtualMatrix(struct Matrix *structMatrixBase, size_t indRow, size_t indCol, size_t rows, size_t cols) {
    struct Matrix *structMatrix = malloc(sizeof(struct Matrix));
    structMatrix->data = structMatrixBase;
    structMatrix->type = VIRTUAL;
    structMatrix->shiftCol = indCol;
    structMatrix->shiftRow = indRow;
    if (indRow + rows <= structMatrixBase->rows &&
        indCol + cols <= structMatrixBase->cols) {
        structMatrix->cols = cols;
        structMatrix->rows = rows;
        return structMatrix;
    } else {
        structMatrix->rows = indRow + rows - structMatrixBase->rows;
        structMatrix->cols = indCol + cols - structMatrixBase->cols;
        return structMatrix;
    }
}

struct Matrix *CreateMatrix(enum Type type, size_t rows, size_t cols) {
    struct Matrix *matr = malloc(sizeof(struct Matrix));
    if (rows == 0 || cols == 0) return matr;
    switch (type) {
        case FLAT:
            matr->data = calloc(rows * cols, sizeof(float));
            break;
        case ROW: {
            float **masRow = malloc(rows * sizeof(float *));
            for (size_t i = 0; i < rows; ++i) {
                masRow[i] = calloc(cols, sizeof(float));
            }
            matr->data = masRow;
            break;
        }
        case COLUMN: {
            float **masColumn = malloc(cols * sizeof(float *));
            for (size_t i = 0; i < cols; ++i) {
                masColumn[i] = calloc(rows, sizeof(float));
            }
            matr->data = masColumn;
            break;
        }
        default:
            printf("Не поддерживаемый способ представления матрицы");
    }
    matr->type = type;
    matr->rows = rows;
    matr->cols = cols;
    matr->shiftCol=0;
    matr->shiftRow=0;
    return matr;
}

float GetMatrixValue(struct Matrix *structMatrix, size_t indRow, size_t indCol) {
    switch (structMatrix->type) {
        case FLAT: {
            float *mf = (float *) structMatrix->data;
            return mf[(indRow - 1) * structMatrix->cols + indCol];
        }
        case ROW: {
            float *mf = (float *)structMatrix->data;
            *mf=mf[indRow-1];
            return mf[indCol-1];
        }
        case COLUMN:{
            float *mf = (float *)structMatrix->data;
            *mf=mf[indCol-1];
            return mf[indRow-1];
        }
        case VIRTUAL:
            GetMatrixValue(structMatrix,indRow+structMatrix->shiftRow,indCol+structMatrix->shiftCol);
            break;
    }
    return -0.0;
}

void DestroyMatrix(struct Matrix *structMatrix) {
    free(structMatrix->data);
    free(structMatrix);
}

void matrixPrint(const struct Matrix *const structMatrix) {
    switch (structMatrix->type) {
        case FLAT: {
            float *mf = (float *) structMatrix->data;
            for (size_t i = 0; i < (structMatrix->rows * structMatrix->cols); ++i) {
                printf("%.2f ", mf[i]);
            }
            printf("\n");
            break;
        }
        case ROW:

            break;
        case COLUMN:

            break;
        case VIRTUAL:

            break;
    }
}
