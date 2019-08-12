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

void vectorPrint(const struct Vector* const s) {
	for (size_t i = 0; i < (s->size); ++i) {
		printf("%.2f ", s->data[i]);
	}
	printf("\n");
}

