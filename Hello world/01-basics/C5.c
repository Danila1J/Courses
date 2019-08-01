#include <stdio.h>
#include <stdlib.h>

double function(double x){
    if(x<=0) return x;
    if(0<x<2) return x*x;
    if(x>=2) return 4;
}

int main(int argc, const char *argv[]){
    double x;
    if (argc < 2) {
        printf("Введите x: ");
        scanf("%lf", &x);
    } else {
        x = atoi(argv[1]);
    }
    printf("%lf",function(x));
}