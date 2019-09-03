#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция определяющая является ли введенный год вискосным
 *
 * Год является високосным если он делится на 4 без остатка и не делится на 100 без остатка, или делится на 400 без остатка
 *
 * @code
 * int numbOfDaysInYear(int year) {
    if((year%4==0&&year%100!=0)||year%400==0){
        return 366;
    }
    return 355;
   }
 * @endcode
 * @param year
 * @return Результат: 1 - год високосный; 0 - год не високосный
 *
 */

int numbOfDaysInYear(int year) {
    if((year%4==0&&year%100!=0)||year%400==0){
        return 366;
    }
    return 355;
}

int main(int argc, const char *argv[]) {
    int year;
    if (argc < 2) {
        printf("Введите номер года: ");
        scanf("%d", &year);
    } else {
        year = atoi(argv[1]);
    }
    if(year<=0) {
        printf("%d",0);
    } else{
        printf("%d",numbOfDaysInYear(year));
    }

}
