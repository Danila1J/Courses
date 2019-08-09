#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция дающий ответ возможен ли треугольник с введенными сторонами или он является вырожденными
 *
 * Сумма любых двух сторон должна быть меньше 3-ей стороны
 *
 * @f$(a<b+c),(b<a+c),(c<a+b)\f$
 *
 * @code
 * void degenerateTriangle(double a,double b,double c){
    printf("%d\n",(a<b+c) & (b<a+c) & (c<a+b));
   }
 * @endcode
 *
 * @param a Сторона треугольника а
 * @param b Сторона треугольника b
 * @param c Сторона треугольника с
 * @return d Печатет результат: 1 - треугольник возможен, 0 - треугольник вырожденный
 *
 */

int degenerateTriangle(double a,double b,double c){
    return (a<b+c) & (b<a+c) & (c<a+b);
}

int main(int argc, const char *argv[]){
    double a,b,c;
    if (argc < 3) {
        printf("Введите длины сторон a,b,c");
        scanf("%lf %lf %lf", &a,&b,&c);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }
    printf("%d",degenerateTriangle(a,b,c));
}
