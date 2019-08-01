#include <stdio.h>
#include <stdlib.h>

int EuclidGCD(int a, int b) {
    if(b==0){
        return a;
    }else{
        EuclidGCD(b,a%b);
    }
}

int main(int argc, const char *argv[]) {
    int a,b;
    if (argc < 3) {
        printf("Введите числа А и В для определения НОД: ");
        scanf("%d %d", &a, &b);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    printf("НОД: %d",EuclidGCD(a,b));
}