#include "Vector.h"
#include <stdio.h>

int main() {
	struct Vector s1;
	struct Vector s2[3];
	struct Vector* s3 =(struct Vector*) malloc(sizeof(struct Vector));
	struct Vector* s4= (struct Vector*) malloc(3*sizeof(struct Vector));
	vectorInit(&s1, 1);
	vectorInit(s2+0, 2); // &(*(s2+0))
	vectorInit(s2+1, 3);
	vectorInit(s2+2, 4);
	vectorInit(s3, 5);
	vectorInit(s4+0, 6);
	vectorInit(s4+1, 7);
	vectorInit(s4+2, 8);
	vectorPrint(&s1);
	vectorPrint(s2 + 0);
	vectorPrint(s2 + 1);
	vectorPrint(s2 + 2);
	vectorPrint(s3);
	vectorPrint(s4 + 0);
	vectorPrint(s4 + 1);
	vectorPrint(s4 + 2);
	vectorFree(&s1);
	printf("-----------------------\n");
	vectorPrint(&s1);
    printf("-----------------------\n");
    s2[0].data[0]=34.0f;
    vectorPrint(s2+0);
    printf("%d\n",firstIndexOf(s2+0,2.0));
    printf("%d\n",lastIndexOf(s2+0,2.0));
}