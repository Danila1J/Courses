#include <stdio.h>
#include "Sort.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    //int mas[3] = {1, 3, 4};
    int mas2[5] = {6, 5, 3,4,1};
    //int mas3[6];
    //merge(mas, 3, mas2, 3, mas3, false);
    //selectionSort(mas,4);
    printArray(mas2,5);
    quickSort(mas2,0,4);
    //shakerSort(mas2,3);
    //bubbleSort(mas2,3);
    printArray(mas2,5);
    //printf("%d",min(mas,4));
}
