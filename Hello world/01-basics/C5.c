#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция дающаю однозначный ответ в зависимости от х
 *
 * При x<=0 Результат: -x;
 * При 0<x<2 Результат: x*x;
 * При x>=2 Результат: 4;
 *
 * @code
 * double function(double x){
    if(x<=0) return -x;
    if(0<x<2) return x*x;
    if(x>=2) return 4;
    }
 * @endcode
 * @param x Вещественное число
 * @return Ответ зависящий от x
 *
 */

double function(double x){
    if(x<=0) return -x;
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