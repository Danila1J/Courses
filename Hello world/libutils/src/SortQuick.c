#include <libutils/Sort.h>

void quickSort(int *data, int first, int last) {
    if (first < last)
    {
        int left = first;
        int right = last;
        int middle = data[(left + right) / 2];
        do
        {
            while (data[left] < middle) left++;
            while (data[right] > middle) right--;
            if (left <= right)
            {
                int tmp = data[left];
                data[left] = data[right];
                data[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(data, first, right);
        quickSort(data, left, last);
    }
}




