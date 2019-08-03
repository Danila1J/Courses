#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*!
 * @brief Функция вычисления sin(x)
 *
 * Функция сделана на основе рекуретной формулы( n+1 член ряда получается из n члена ряда ) без импользования дополнительный функций степени и факториала
 *
 * @f$sin(x)=\sum\limits_{n=0}^{\inf}\frac{(-1)^n*x^{2n+1}}{(2n+1)!}\f$
 *
 * @code
 * double sinF(double x, int n) {
    double a = x;
    double sum = a;
    for (int i = 1; i < n; ++i) {
        a *= -x*x/((2*i+1)*(2*i));
        sum += a;
    }
    return sum;
    }
 * @endcode
 * @param x Показатель степени
 * @param n Число членов ряда Тейлора (чем больше,тем точнее будет результат)
 * @return sum Сумма n членов ряда Тейлора для функции sin(x)
 *
 */

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