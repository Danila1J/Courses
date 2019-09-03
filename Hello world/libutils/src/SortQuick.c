#include <libutils/Sort.h>

void quickSort(int *arr, int first, int last) {
    if (last <= 1) return;
    if (first >= last) return;
    int supportElement = arr[(first + last) / 2];
    int i = first;
    int j = last;
    while (i <= j) {
        while (arr[i] <= supportElement)
            ++i;
        while (arr[j] > supportElement)
            --j;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
        }
    }
    quickSort(arr, first, j-1);
    quickSort(arr, j +1, last);
}


