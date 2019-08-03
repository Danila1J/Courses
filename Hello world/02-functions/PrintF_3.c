#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

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
    int count = 0;
    {
        int nc = n;
        if (n == 0) {
            putchar(n);
            return;
        }
        while (nc != 0) {
            nc = nc / 10;
            count++;
        }
    }
    int num = n;
    int div = pow(10, count - 1);
    for (int i = 0; i < count; ++i, div /= 10) {
        int digit = num / div;
        putchar(48 + digit);
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
    int count = 0;
    {
        int nc = n;
        if (n == 0) {
            putchar(n);
            return;
        }
        while (nc != 0) {
            nc = nc / 10;
            count++;
        }
    }
    int num = n;
    int div = pow(10, count - 1);
    for (int i = 0; i < count; ++i, div /= 10) {
        int digit = num / div;
        putchar(48 + digit);
        num %= div;
    }
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
        if (format[i] == '%' && (format[i + 2] == 'f')) {
            int wide=10;
            if(isdigit(format[i+1])!=0){
                char a = format[i+1];
                wide=a-'0';
            }
            i++;
            double numb=va_arg(args, double);
            double integ;
            double fraction=modf(numb,&integ);
            printInt(integ);
            fraction=fraction*pow(10,wide);
            putchar('.');
            printInt(fraction);
            i+=2;
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
        if (format[i] == '%' && (format[i + 2] == 'f')) {
            int wide=10;
            if(isdigit(format[i+1])!=0){
                char a = format[i+1];
                wide=a-'0';
            }
            i++;
            double numb=va_arg(args, double);
            double integ;
            double fraction=modf(numb,&integ);
            printInt(integ);
            fraction=fraction*pow(10,wide);
            putchar('.');
            printInt(fraction);
            i+=2;
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
    printF("%3f",1.967);
}