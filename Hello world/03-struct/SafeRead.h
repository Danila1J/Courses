#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Функция безопасного чтения целого числа из консоли
 *
 * @param prompt Строка приглашения
 * @param min Минимальное допустимое число
 * @param max Максимальное допустимое чилсо
 * @return Полченное число из строки
 */
int readInt(const char *prompt, int min, int max);
double readDouble(const char *prompt,double min,double max);
char* readStr(const char* prompt);
