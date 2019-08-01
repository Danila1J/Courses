#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sinF(double x, int n) {
    double a = x;
    double sum = a;
    for (int i = 1; i < n; ++i) {
        a *= -x*x/((2*i+1)*(2*i));
        sum += a;
    }
    return sum;
}

int main(int argc, const char *argv[]) {
    double x;
    int n;
    if (argc < 3) {
        printf("f=sin(x) Введите x и n-число членов ряда Тейлора: ");
        scanf("%lf %d", &x, &n);
    } else {
        x = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    printf("%lf\n", sinF(x, n));
    printf("%lf", sin(x));
}