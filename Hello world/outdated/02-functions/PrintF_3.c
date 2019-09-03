#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

const int CODE_ZERO = 48; //Код цифры 0 в ASCII

/**
 * Функция отбрасывает младшие разряды которые равны нули и оставляет только цифры не равные нулю, напрмер: 12300 = 123
 *
 * @param n Число
 * @param withOut Флаг решающий отбрасывать нули или нет, 1 - отбрасывать; 0 - нет
 * @return
 */

long lenNumbWithoutInsignificantZeros(long n, int withOut) {
    int count = 0;
    {
        long nc = n;
        if (n == 0) {
            putchar(n);
            return 1;
        }
        while (nc != 0) {
            if (withOut == 1) {
                int zero = nc % 10;
                if (zero == 0) {
                    nc /= 10;
                    continue;
                }
            }
            nc = nc / 10;
            count++;
        }
    }
    return count;
}

/*!
 * @brief Функция вывода в консоль целого числа с помощью putchar
 *
 * nc -  это копия числа(n)
 * В цикле while делим на 10 и увеличиваем счётчик(count) чтобы узнать количество цифр в числе
 * num - это копия числа n
 * div показывает максимальный разряд в числе
 * int digit = num / div - в digit остаётся первое число
 * 48 - код числа ноль
 * num %= div отюрасывает первое число
 *
 * @code
 * void printInt(int n) {
    if (n < 0) {
        putchar(45);
        n = -n;
    }
    int count = lenNumbWithoutInsignificantZeros(n,0);
    int num = n;
    int div = pow(10, count - 1);
    for (int i = 0; i < count; ++i, div /= 10) {
        int digit = num / div;
        putchar(CODE_ZERO + digit);
        num %= div;
    }
   }
 * @endcode
 * @param n Целое число
 * @return Печатает целое число в консоль
 *
 */

void printInt(int n) {
    if (n < 0) {
        putchar(45);
        n = -n;
    }
    int count = lenNumbWithoutInsignificantZeros(n,0);
    int num = n;
    int div = pow(10, count - 1);
    for (int i = 0; i < count; ++i, div /= 10) {
        int digit = num / div;
        putchar(CODE_ZERO + digit);
        num %= div;
    }
}

/**
 * @brief Отбрасывает дробную часть вещественного числа
 *
 * @param d Вещественое число d
 * @return integ Целая часть вещественного числа
 */

long integerPart(double d) {
    double integ;
    modf(d, &integ);
    return integ;
}

/**
 * @brief Печать вещественного числа с заданной точностью
 *
 * @param wide Точность числа
 * @param integ Целая часть вещественного числа
 * @param fraction Дробная часть вещественного числа
 * @return Печать в консоль вещественного числа
 */

void printFloat(int wide, double integ, double fraction) {
    printInt(integ);
    fraction = fraction * pow(10, wide);
    putchar('.');
    printInt(integerPart(fraction));
}

/*!
 * @brief Функция вывода (аналог printf) с помощью putchar и собственного метода printInt
 *
 * @warning нужно точно указывать что выводить, если в строке формата указать %d аругмент будет вещественное число,то функция будет работать неправильно
 *
 * %d - в строке формата для вывода целого числа
 * %f - в строке формата для вывода вещественного числа
 * \n - для переноса на новую строку
 *
 * @code
 * void printF(const char *format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != 0; ++i) {
        if (format[i] == '\\' && format[i + 1] == 'n') {
            putchar(10);
        }
        int withPrecision = 0;
        if (format[i] == '%' && (format[i + 3] == 'f')) {
            withPrecision = 1;
        }
        if (withPrecision || (format[i] == '%' && (format[i + 1] == 'f'))) {
            double numb = va_arg(args, double);
            double integ;
            double fraction = modf(numb, &integ);
            double fracCpy = fraction;
            fracCpy *= pow(10, 10);
            int wide =1;
            wide = lenNumbWithoutInsignificantZeros(integerPart(fracCpy),1);
            if (withPrecision) {
                wide = format[i + 2] - '0';
                i += 2;
            }
            printFloatWithPrecision(wide, integ, fraction);
            i += 2;
        }
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
            printInt(va_arg(args, int));
            ++i;
        } else {
            putchar(format[i]);
        }
    }
    va_end(args);
   }
 * @endcode
 * @param format Строка формата
 * @param ... Переменное число параметров
 * @return Печатает текст,целое или вещественное число в консоль
 *
 */

void printF(const char *format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != 0; ++i) {
        if (format[i] == '\\' && format[i + 1] == 'n') {
            putchar(10);
        }
        int withPrecision = 0;
        if (format[i] == '%' && (format[i + 3] == 'f')) {
            withPrecision = 1;
        }
        if (withPrecision || (format[i] == '%' && (format[i + 1] == 'f'))) {
            double numb = va_arg(args, double);
            double integ;
            double fraction = modf(numb, &integ);
            double fracCpy = fraction;
            fracCpy *= pow(10, 10);
            int wide =1;
            wide = lenNumbWithoutInsignificantZeros(integerPart(fracCpy),1);
            if (withPrecision) {
                wide = format[i + 2] - '0';
                i += 2;
            }
            printFloat(wide, integ, fraction);
            i += 2;
        }
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
            printInt(va_arg(args, int));
            ++i;
        } else {
            putchar(format[i]);
        }
    }
    va_end(args);
}

int main() {
    printF("%.2f\n", 2.773);
    printf("%.2f",2.773);
}