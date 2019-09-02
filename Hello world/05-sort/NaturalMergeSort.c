#include "Sort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swapPointer(int **a, int **b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sequenceSize(const int *arr, int n, bool forward) {
    int count = 1;
    if (forward) {
        while (count < n && arr[count - 1] <= arr[count]) {
            ++count;
        }
    } else {
        while (count < n && arr[n - count - 1] >= arr[n - count]) {
            ++count;
        }
    }
    return count;
}

void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward) {
    int i = 0;
    int j = n2 - 1;
    bool intersects = p1 + n1 >= p2;
    if (intersects) {
        --n1;
        if (!forward) {
            ++dst;
        }
    }
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
    int *supportArray = malloc(sizeof(int) * n);
    int count=0;
    printf("Изначальный массив\n");
    printArray(arr,n);
    printf("---------------------------------------------------------------------\n");
    while(1){
        printf("Количество свапов = %d\n",count);
        printf("Массив arr = ");
        printArray(arr,n);
        printf("Массив support = ");
        printArray(supportArray,n);
        printf("---------------------------------------\n");
    merge(
            arr,
            sequenceSize(arr, n, true),
            arr + (n-(sequenceSize(arr+sequenceSize(arr,n,true), n-sequenceSize(arr,n,true), false))),//!!!!!!!!!!!
            sequenceSize(arr+sequenceSize(arr,n,true), n-sequenceSize(arr,n,true), false),
            supportArray,
            true);
        printf("merge1\n");
        printf("Смещение возрастающей последовательности = arr + %d\n",0);
        printf("Размер возрастающей поледовательности = %d\n", sequenceSize(arr, n, true));
        printf("Смещение убывающей последовательности = arr + %d\n", n-(sequenceSize(arr+sequenceSize(arr,n,true), n-sequenceSize(arr,n,true), false)));//!!!!!!!!!!!!!!!
        printf("Размер убывающей поледовательности = %d\n",sequenceSize(arr+sequenceSize(arr,n,true), n-sequenceSize(arr,n,true), false));
        printf("Смещение вспомогательного массива = arr + %d\n",0);
        printf("\nПосле merge1\n");
        printf("Массив arr = ");
        printArray(arr,n);
        printf("Массив support = ");
        printArray(supportArray,n);
        printf("---------------------------------------\n");
    if(sequenceSize(arr,n,true)+sequenceSize(arr,n,false)>=n){
        break;
    }
    merge(arr + sequenceSize(arr, n, true),
          sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, true)-sequenceSize(arr, n, false), true),
          arr + (n - sequenceSize(arr, n, false)-sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false)),
          sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false),
          supportArray + n - (sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, true)-sequenceSize(arr, n, false), true)+sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false)),
          false);
    printf("merge2\n");
    printf("Смещение возрастающей последовательности = arr + %d\n",sequenceSize(arr, n, true));
    printf("Размер возрастающей поледовательности = %d\n", sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, true)-sequenceSize(arr,n,false), true));
    printf("Смещение убывающей последовательности = arr + %d\n",(n - sequenceSize(arr, n, false)-sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false)));
    printf("Размер убывающей поледовательности = %d\n",sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false));
    printf("Смещение вспомогательного массива = arr + %d\n",n - (sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, true)-sequenceSize(arr, n, false), true)+sequenceSize(arr+sequenceSize(arr, n, true), n-sequenceSize(arr, n, false)-sequenceSize(arr,n,true), false)));
        printf("\nПосле merge2\n");
        printf("Массив arr = ");
        printArray(arr,n);
        printf("Массив support = ");
        printArray(supportArray,n);
    printf("---------------------------------------\n");
    printf("После переноса оставшихся элементов\n");
    for (int i = sequenceSize(arr, n, true) + sequenceSize(arr + sequenceSize(arr, n, true),n - sequenceSize(arr, n, true) - sequenceSize(arr, n, false),true);
    i <= n - sequenceSize(arr, n, true) -sequenceSize(arr + sequenceSize(arr, n, true),n - sequenceSize(arr, n, true) -sequenceSize(arr, n, false),false) - 1;
    ++i) {
        supportArray[i - 1] = arr[i];
    }
    printf("Массив arr = ");
    printArray(arr,n);
    printf("Массив support = ");
    printArray(supportArray,n);
    printf("*********************************************************************\n");
    swapPointer(&arr,&supportArray);
    ++count;
   }
    if((count%2)!=0){
        swapPointer(&arr,&supportArray);
    }
    printArray(arr,n);

}
