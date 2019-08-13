#include "Matrix.h"
#include <stdio.h>

int main(){
    struct Matrix* matrix=CreateMatrix(ROW, 3, 3);
    matrixPrint(matrix);
}
