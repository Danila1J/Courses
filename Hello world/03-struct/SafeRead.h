#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Функция безопасного чтения целого числа из консоли
 *
 * @param prompt Приглашение
 * @param min Минимальное допустимое число
 * @param max Максимальное допустимое чилсо
 * @return Число
 */
int read_int(const char *prompt, int min, int max);
