#include <stdlib.h>

enum Type {
	FLAT,
	ROW,
	COLUMN,
	VIRTUAL
};

struct Matrix {
	void* data;
	enum Type type;
	size_t rows;
	size_t cols;
	size_t shiftRow;
	size_t shiftCol;
};

 void InitMatrix(struct Matrix*const matrix, int numberFrom,int numberTo);
struct Matrix* CreateVirtualMatrix(struct Matrix* structMatrixBase, size_t indRow, size_t indCol, size_t rows, size_t cols);
struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols);
void SetMatrixValue(struct Matrix* matrix,float f, size_t indRow, size_t indCol);
float GetMatrixValue(const struct Matrix* structMatrix, size_t indRow, size_t indCol);
void DestroyMatrix(struct Matrix* structMatrix);
void SwapRows(struct Matrix* matrix_1, struct Matrix* matrix_2, size_t indRow_1, size_t indRow_2);
void PrintMatrix(const struct Matrix* const structMatrix);

