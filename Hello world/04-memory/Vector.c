#include "Vector.h"
#include <stdio.h>

void vectorInit(struct Vector* const s, size_t n) {
	s->data = (float*)malloc(sizeof(float) * n);
	if (s->data == NULL) {
		s->capacity = 0;
		s->size = 0;
		return;
	}
	s->size = n;
	s->capacity = n;
	for (size_t i = 0; i < n; i++){
		s->data[i] = (float)n;
	}
}

void vectorFree(struct Vector* const s){
    free(s->data);
    s->data=NULL;
    s->capacity=0;
    s->size=0;
}

int firstIndexOf(const struct Vector* const structVector,float f){
    for (size_t i = 0; i <structVector->size; ++i) {
        if(structVector->data[i]==f){
            return i;
        }
    }
    return -1;
}

int lastIndexOf(const struct Vector* const structVector,float f){
    int lastInd=-1;
    for (size_t i = 0; i <structVector->size; ++i) {
        if(structVector->data[i]!=f){
            continue;
        } else{
            lastInd=i;
        }
    }
    return lastInd;
}

void vectorPrint(const struct Vector* const s) {
	for (size_t i = 0; i < (s->size); ++i) {
		printf("%.2f ", s->data[i]);
	}
	printf("\n");
}

