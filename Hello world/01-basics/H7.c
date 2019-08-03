#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция выводит числа от а до b включительно,причем 1-ое число выведется 1 раз, 2-ое 2 раза и тд.
 *
 *  Первый цикл определяет число от а до b включительно, второй цикл определяет сколько раз нужно вывети число
 * @warning Не работает с отрицательными и вещественными числами
 *
 * @code
 * void fromAToB(int a, int b) {
    for(int i=0;i<=b-a+1;++i){
        for(int j=0;j<i;++j){
            printf("%d",a+i-1);
        }
    }
   }
 * @endcode
 * @param a Первое число
 * @param b Второе число
 * @return Вывод чисел от а до b
 *
 */

void fromAToB(int a, int b) {
    for(int i=0;i<=b-a+1;++i){
        for(int j=0;j<i;++j){
            printf("%d",a+i-1);
        }
    }
}

int main(int argc, const char *argv[]) {
    int a,b;
    if (argc < 3) {
        printf("Введите числа А и В (А<В): ");
        scanf("%d %d", &a, &b);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    fromAToB(a,b);
}