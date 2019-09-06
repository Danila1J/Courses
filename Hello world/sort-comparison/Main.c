#include <libutils/Sort.h>
#include <libutils/SafeRead.h>

bool compareArrays(int * a, int * b, size_t count) {
    for ( size_t i = 0; i < count; ++i )
        if ( a[i] != b[i] )
            return false;
    return true;
}

void testSort(size_t n) {
    int *masBubbleSort = malloc(sizeof(int) * n);
    int *masSelectionSort = malloc(sizeof(int) * n);
    int *masShakerSort = malloc(sizeof(int) * n);
    int *masQuickSort = malloc(sizeof(int) * n);
    int *masNaturalMergeSort = malloc(sizeof(int) * n);
    int r = 0;
    for (size_t i = 0; i < n; i++) {
        r = rand() % 100;
        masBubbleSort[i] = r;
        masSelectionSort[i] = r;
        masShakerSort[i] = r;
        masQuickSort[i] = r;
        masNaturalMergeSort[i] = r;
    }
    bubbleSort(masBubbleSort, n);
    selectionSort(masSelectionSort, n);
    shakerSort(masShakerSort, n);
    quickSort(masQuickSort, 0, n-1);
    naturalMergeSort(masNaturalMergeSort, n);
    if(!(compareArrays(masBubbleSort,masSelectionSort,n)&&compareArrays(masSelectionSort,masShakerSort,n)&&compareArrays(masShakerSort,masQuickSort,n)&&compareArrays(masQuickSort,masNaturalMergeSort,n))){
        printf("Массивы не сопадают\n");
    }
    printArray(masBubbleSort, n);
    printArray(masSelectionSort, n);
    printArray(masShakerSort, n);
    printArray(masQuickSort, n);
    printArray(masNaturalMergeSort, n);
    free(masBubbleSort);
    free(masSelectionSort);
    free(masShakerSort);
    free(masQuickSort);
    free(masNaturalMergeSort);
}

int main() {
    //testSort(10);
    testSort(15);
    //int mas[7] = {1, 3, 4, 7, 5, 9, 0};
    //int mas2[10] = {1, 3, 1, 4, 9, 7, 8, 4, 5, 2};
    //  int mas3[5]={1,2,3,2,1};
    //merge(mas, 3, mas2, 3, mas3, false);
    //selectionSort(mas,4);
    // printArray(mas2, 6);
    //naturalMergeSort(mas2, 10);
    // quickSort(mas,0,6);
    //shakerSort(mas2,3);
    //bubbleSort(mas2,3);
    // printArray(mas, 7);
    //printf("%d",min(mas,4));
}
