#include <stdio.h>
#include "Sort.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
   // int mas[7] = {1, 3, 4, 7, 5, 9, 0};
   int mas2[10] = {1, 3, 1, 4, 9, 7, 8, 4, 5, 2};
    //  int mas3[5]={1,2,3,2,1};
    //merge(mas, 3, mas2, 3, mas3, false);
    //selectionSort(mas,4);
    // printArray(mas2, 6);
    //sortNaturalMerge(mas2, 10);
    quickSort(mas2,0,9);
    //shakerSort(mas2,3);
    //bubbleSort(mas2,3);
    printArray(mas2, 10);
    //printf("%d",min(mas,4));
}
