#include <libutils/Vector.h>
#include <stdio.h>
#include <libutils/Sort.h>

struct Vector {
    float* data; /*< Динамический массив float */
    size_t capacity; /*< Число элементов под которые выделена память*/
    size_t size; /*< Реальное число элементов в массиве*/
};

void vector_create(struct Vector *const s, size_t n) {
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

void vector_free(struct Vector *s) {
    free(s->data);
    free(s);
}

int vector_search(const struct Vector *const structVector, predicate p) {
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

void vector_insert(struct Vector *const structVector, int index, float f) {
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

void vector_remove(struct Vector *const structVector, size_t index) {
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

void vector_add(struct Vector* v,float f){
    vector_insert(v,v->size,f);
}

int qfloat(const void *pa, const void *pb) {
    float a = *(float*)pa, b = *(float*)pb;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

void vector_sort(struct Vector* v,int n){
    //quickSort((int *) v, 0, n);
    qsort(v,n, sizeof(float),qfloat);
}

int vector_get(struct Vector* v,size_t index){
    if(index>v->size) return -1;
    return v->data[index];
}

void vector_set(struct Vector* v,size_t index, float f){
    v->data[index]=f;
}
