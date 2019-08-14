#include "Matrix.h"
#include <stdio.h>

int main(){
    struct Matrix* matrix=CreateMatrix(ROW, 3, 3);
    float* mf=(float*)matrix->data;
    *mf=mf[0];
    mf[0]=34.0f;
    matrix->data=mf;
    printf("%.2f\n",GetMatrixValue(matrix,1,1));
    //matrixPrint(matrix);
}
