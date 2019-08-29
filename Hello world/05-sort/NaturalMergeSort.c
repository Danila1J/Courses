#include "Sort.h"
#include <stdbool.h>

void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward) {
    int i = 0;
    int j = n2 - 1;
    int dstStart = forward ? 0 : n1 + n2-1;
    int dstOrentation = forward ? +1:-1;
    for (int k = 0; k < n1 + n2; ++k) {
        if (i < n1 && j != -1) {
            //в обоих списках есть элементы
            if (p1[i] < p2[j]) {
                dst[dstStart+k*dstOrentation] = p1[i];
                ++i;
            } else {
                dst[dstStart+k*dstOrentation] = p2[j];
                --j;
            }

        } else if (i < n1) {
            //элементы только в первом
            dst[dstStart+k*dstOrentation] = p1[i];
            ++i;
        } else {
            //элементы только во втором
            dst[dstStart+k*dstOrentation] = p2[j];
            --j;
        }
    }
}
