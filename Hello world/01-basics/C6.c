#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double expF(double x, int n){
    double sum=1;
    double a=1;
    for(int i=1;i<n;++i){
        a*=x/i;
        sum+=a;
    }
    return sum;
}

int main(int argc, const char *argv[]){
    double x;
    int n;
    if (argc < 3) {
        printf("f=e^x Введите x и n-число членов ряда Тейлора: ");
        scanf("%lf %d", &x,&n);
    } else {
        x = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    printf("%lf\n",expF(x,n));
    printf("%lf",exp(x));
}