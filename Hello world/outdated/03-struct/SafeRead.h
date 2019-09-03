#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Функция безопасного чтения целого числа из консоли
 *
 * @param prompt Строка приглашения
 * @param min Минимальное допустимое число
 * @param max Максимальное допустимое чилсо
 * @return Полученное число из строки
 */
int readInt(const char *prompt, int min, int max);

/**
 * @brief Функция безопасного чтения вещественного числа
 *
 * @param prompt Строка приглашения
 * @param min Минимальное допустимое число
 * @param max Максимальное допустимое чилсо
 * @return Полученное число из строки
 */
double readDouble(const char *prompt,double min,double max);

/**
 * @brief Функция чтения строки из консоли
 *
 * После окончания работы нужно освободить указатель с помощью функции free()
 *
 * @param prompt Строка приглашения
 * @return Полученная строка
 */
char* readStr(const char* prompt);
