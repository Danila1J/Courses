#include <libutils/Sort.h>

void shakerSort(int *arr, int n) {
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = i - 1; j < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        for (int k = n - i - 1; k >= i; --k) {
            if (arr[k] < arr[k - 1]) {
                swap(&arr[k], &arr[k - 1]);
            }
        }
    }
}
