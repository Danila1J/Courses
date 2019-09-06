#include <libutils/Sort.h>

void quickSort(int *arr, int first, int last) {
    int l = first, r = last;
    int piv = arr[(l + r) / 2];
    while (l <= r)
    {
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r)
            swap (&arr[l++], &arr[r--]);
    }
    if (first < r)
        quickSort (arr,first, r);
    if (last > l)
        quickSort(arr,l, last);
}




