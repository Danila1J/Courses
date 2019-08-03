#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция вычисления количества секунд прошедших с последнего часа
 *
 * @code
 * void countSeconds(int n){
    int k=n/3600;
    int ot=(n-3600*k);
    printf("С начала последнего часа прошло: %d секунд", ot);
    }
 * @endcode
 * @param n Количество секунд
 * @return Печатает количество секунд с начала последнего часа
 *
 */

void countSeconds(int n){
    int k=n/3600;
    int ot=(n-3600*k);
    printf("С начала последнего часа прошло: %d секунд", ot);
}

int main(int argc, const char *argv[]){
    int n;
    if (argc < 1) {
        printf("Введите количество секунд:");
        scanf("%d", &n);
    } else {
        n = atoi(argv[1]);
    }
    countSeconds(n);
}