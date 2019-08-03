#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Функция перестанвоки сотен и десятков ( 123=213 )
 *
 * @code
 * int per(int num) {
    int a, b, c;
    a = num % 10; //последнее число
    num /= 10; //первые два
    b = num % 10; //число по середине
    num /= 10;
    c = num; //первое число
    num = b * 100 + c * 10 + a; //
    return num;
    }
 * @endcode
 * @warning Работает толь с 3-х значными числами
 * @param num Число для перестановки
 * @return num Измененное число
 *
 */

int per(int num) {
    int a, b, c;
    a = num % 10; //последнее число
    num /= 10; //первые два
    b = num % 10; //число по середине
    num /= 10;
    c = num; //первое число
    num = b * 100 + c * 10 + a; //
    return num;
}

int main(int argc, const char *argv[]) {
    int n;
    if (argc < 2) {
        printf("Введите число для перестановки(длина числа 3 знака):");
        scanf("%d", &n);
    } else {
        n = atoi(argv[1]);
    }
    printf("%d", per(n));
}