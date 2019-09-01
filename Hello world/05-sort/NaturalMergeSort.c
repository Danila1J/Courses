#include "Sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sequenceSize(int *arr, int n, bool forward) {
    int count = 1;
    if (forward) {
        while (count < n && arr[count - 1] < arr[count]) {
            ++count;
        }
    }else{
        while (count < n && arr[n - count - 1] > arr[n - count]) {
            ++count;
        }
    }
    return count;
}

void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward) {
    int i = 0;
    int j = n2 - 1;
    int dstStart = forward ? 0 : n1 + n2 - 1;
    int dstOrentation = forward ? +1 : -1;
    for (int k = 0; k < n1 + n2; ++k) {
        if (i < n1 && j != -1) {
            //в обоих списках есть элементы
            if (p1[i] < p2[j]) {
                dst[dstStart + k * dstOrentation] = p1[i];
                ++i;
            } else {
                dst[dstStart + k * dstOrentation] = p2[j];
                --j;
            }

        } else if (i < n1) {
            //элементы только в первом
            dst[dstStart + k * dstOrentation] = p1[i];
            ++i;
        } else {
            //элементы только во втором
            dst[dstStart + k * dstOrentation] = p2[j];
            --j;
        }
    }
}

void sortNaturalMerge(int *arr, int n) {
    if (n < 2) return;
    int countRight = sequenceSize(arr,n,false);
    int sizeLeft=sequenceSize(arr,n,true);
    //int start = n - countRight;
    int *supportArray = malloc(sizeof(int) * n);
    //merge(arr, sizeLeft, arr + start, countRight, supportArray, true);
    //printf("%d\n",n-sizeLeft-sequenceSize(arr+sizeLeft,n-sizeLeft-countRight,false));
    merge(arr+sequenceSize(arr,n,true),sequenceSize(arr+sequenceSize(arr,n,true),n-sequenceSize(arr,n,true)-sequenceSize(arr,n,false),true),arr+n-sequenceSize(arr,n,true)-sequenceSize(arr+sequenceSize(arr,n,true),n-sequenceSize(arr,n,true)-sequenceSize(arr,n,false),false),sequenceSize(arr+sequenceSize(arr,n,true),n-sequenceSize(arr,n,true)-sequenceSize(arr,n,false),false),supportArray,false);
    printArray(arr,n);
    printArray(supportArray,sizeLeft+countRight+1);
}
