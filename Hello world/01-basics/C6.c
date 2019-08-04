#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
 * @brief Функция вычисления e^x
 *
 * Функция сделана на основе рекуретной формулы( n+1 член ряда получается из n члена ряда ) без импользования дополнительный функций степени и факториала
 *
 * @f$e^x=\sum\limits_{n=1}^{\inf}\frac{e^x}{x!}\f$
 *
 * @code
 * double expF(double x, int n){
    double sum=1;
    double a=1;
    for(int i=1;i<n;++i){
        a*=x/i;
        sum+=a;
    }
    return sum;
   }
 * @endcode
 * @param x Показатель степени
 * @param n Число членов ряда Тейлора (чем больше,тем точнее будет результат)
 * @return sum Сумма n членов ряда Тейлора для функции e^x
 *
 */

double expF(double x, int n) {
    double sum = 1;
    double a = 1;
    for (int i = 1; i < n; ++i) {
        a *= x / i;
        sum += a;
    }
    return sum;
}

int main(int argc, const char *argv[]) {
    double x;
    int n;
    if (argc < 3) {
        printf("f=e^x Введите x и n-число членов ряда Тейлора: ");
        scanf("%lf %d", &x, &n);
    } else {
        x = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    printf("%lf\n", expF(x, n));
    printf("%lf", exp(x));
}
