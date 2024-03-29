#include "../../outdated/04-memory/Vector.h"
#include <stdio.h>

void vectorInit(struct Vector *const s, size_t n) {
    s->data = (float *) malloc(sizeof(float) * n);
    if (s->data == NULL) {
        s->capacity = 0;
        s->size = 0;
        return;
    }
    s->size = n;
    s->capacity = n;
    for (size_t i = 0; i < n; i++) {
        s->data[i] = (float) n;
    }
}

void vectorFree(struct Vector *s) {
    free(s->data);
    free(s);
}

int firstIndexOf(const struct Vector *const structVector, predicate p) {
    for (size_t i = 0; i < structVector->size; ++i) {
        if (p(structVector->data[i])) {
            return i;
        }
    }
    return -1;
}

int lastIndexOf(const struct Vector *const structVector, predicate p) {
    int lastInd = -1;
    for (size_t i = 0; i < structVector->size; ++i) {
        if (p(structVector->data[i])) {
            lastInd = i;
        }
    }
    return lastInd;
}

void vectorInsert(struct Vector *const structVector, int index, float f) {
    if(index>(int)structVector->size) return;
    float mas[structVector->size+1];
    int sizeOld = structVector->size;
    for (int i = 0; i < index; ++i) {
        mas[i] = structVector->data[i];
    }
    mas[index] = f;
    for (int i = index; i <sizeOld; ++i) {
        mas[i + 1] = structVector->data[i];
    }
    if (structVector->capacity == structVector->size) {
        free(structVector->data);
        structVector->data = (float *) malloc(sizeof(structVector->data) * 2);
    }
    for (int i = 0; i <= sizeOld; ++i) {
        structVector->data[i] = mas[i];
    }
    structVector->size = sizeOld + 1;
    structVector->capacity = sizeOld * 2;
}

void vectorRemove(struct Vector *const structVector, size_t index) {
    if (index > structVector->size) { return; }
    for (size_t i = index; i < structVector->size; ++i) {
        structVector->data[i] = structVector->data[i + 1];
    }
    structVector->size--;
}

void vector_print(const struct Vector *const s) {
    for (size_t i = 0; i < (s->size); ++i) {
        printf("%.2f ", s->data[i]);
    }
    printf("\n");
}

