#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция вычисления количества кадратов которые можно разместить на прямоуголнике без наложения, а также оставшейся незанятой площади прямоугольника
 *
 * @code
 * void squaresInRectangle(int a,int b,int c){
    int num=(a/c)*(b/c);
    printf("Количество квадратов размещенных на прямоугольнике %d\n",num);
    int s=a*b-num*c*c;
    printf("Площадь незанятой части прямоугольника %d\n",s);
   }
 * @endcode
 * @param a Сторона прямоугольника а
 * @param b Сторона прямоугольна b
 * @param c Сторона квадрата
 * @return Печатает количество размещенных квадратов и площадь незанятой части прямоугольника 
 *
 */

void squaresInRectangle(int a,int b,int c){
    int num=(a/c)*(b/c);
    printf("Количество квадратов размещенных на прямоугольнике %d\n",num);
    int s=a*b-num*c*c;
    printf("Площадь незанятой части прямоугольника %d\n",s);
}

int main(int argc, const char *argv[]){
    int a,b,c;
    if (argc < 3) {
        printf("Введите 3 целых положительных числа: a b c");
        scanf("%d %d %d",&a,&b,&c);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }
    squaresInRectangle(a,b,c);
}
