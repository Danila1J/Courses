#include <stdio.h>
#include <stdlib.h>

void degenerateTriangle(double a,double b,double c){
    printf("%d\n",(a<b+c) & (b<a+c) & (c<a+b));
}

int main(int argc, const char *argv[]){
    double a,b,c;
    if (argc < 3) {
        printf("Введите длины сторон a,b,c");
        scanf("%d %d %d", &a,&b,&c);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }
    degenerateTriangle(a,b,c);
}