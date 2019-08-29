#include "Sort.h"
#include <stdio.h>

int main(){
    int mas[3]={1,3,4};
    int mas2[3]={6,5,2};
    int mas3[6];
    merge(mas,3,mas2,3,mas3,false);
    //selectionSort(mas,4);
    for (int i = 0; i <6 ; ++i) {
        printf("%d ",mas3[i]);
    }
    //printf("%d",min(mas,4));
}
