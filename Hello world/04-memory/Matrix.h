#include <stdlib.h>

enum Type{
    FLAT,
    ROW,
    COLUMN,
    VIRTUAL
};

struct Matrix{
    void* data;
    enum Type type;
    size_t rows;
    size_t cols;
    size_t shiftRow;
    size_t shiftCol;
};
struct Matrix* CreateVirtualMatrix(struct Matrix* structMatrixBase,size_t indRow,size_t indCol,size_t rows,size_t cols);
struct Matrix* CreateMatrix(enum Type type,size_t rows,size_t cols);
void matrixPrint(const struct Matrix *const structMatrix);

