#include <stdio.h>
#include <stdlib.h>
#include <libutils/Sort.h>
#include <time.h>


bool compareArrays(int *a, int *b, size_t count) {
    for (size_t i = 0; i < count; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void testSort(size_t n, size_t m) {
    int *masBubbleSort = malloc(sizeof(int) * n);
    int *masSelectionSort = malloc(sizeof(int) * n);
    int *masShakerSort = malloc(sizeof(int) * n);
    int *masQuickSort = malloc(sizeof(int) * n);
    clock_t finish1;
    clock_t finish2;
    clock_t finish3;
    clock_t finish4;
    for (size_t i = 0; i < m; i++) {
        for (size_t k = 0; k < n; ++k) {
            int r = 0;
            r = rand() % 100;
            masBubbleSort[k] = r;
            masSelectionSort[k] = r;
            masShakerSort[k] = r;
            masQuickSort[k] = r;
        }
        clock_t start = clock();
        bubbleSort(masBubbleSort, n);
        finish1 += clock() - start;
        start = clock();
        selectionSort(masSelectionSort, n);
        finish2 += clock() - start;
        start = clock();
        shakerSort(masShakerSort, n);
        finish3 += clock() - start;
        start = clock();
        quickSort(masQuickSort, 0, n - 1);
        finish4 += clock() - start;
    }
    printf("Среднее время выполнения bubbleSort: %f\n", ((double) finish1 / CLOCKS_PER_SEC) / m);
    printf("Среднее время выполнения selectionSort: %f\n", ((double) finish2 / CLOCKS_PER_SEC) / m);
    printf("Среднее время выполнения shakerSort: %f\n", ((double) finish3 / CLOCKS_PER_SEC) / m);
    printf("Среднее время выполнения quickSort: %f\n", ((double) finish4 / CLOCKS_PER_SEC) / m);

    if (!(compareArrays(masBubbleSort, masSelectionSort, n) &&
          compareArrays(masSelectionSort, masShakerSort, n) &&
          compareArrays(masShakerSort, masQuickSort, n))) {
        printf("Массивы не сопадают\n");
    }

    free(masBubbleSort);
    free(masSelectionSort);
    free(masShakerSort);
    free(masQuickSort);
}

int main() {
    testSort(10000, 10);
    // int mas[7] = {1, 3, 4, 7, 5, 9, 0};
    //int mas2[10] = {1, 3, 1, 4, 9, 7, 8, 4, 5, 2};
    //  int mas3[5]={1,2,3,2,1};
    //merge(mas, 3, mas2, 3, mas3, false);
    //selectionSort(mas,4);
    // printArray(mas2, 6);
    //sortNaturalMerge(mas2, 10);
    //quickSort(mas2,0,4);
    //shakerSort(mas2,3);
    //bubbleSort(mas2,3);
    //printArray(mas2, 6);
    //printf("%d",min(mas,4));
}
