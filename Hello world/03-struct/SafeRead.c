#include "SafeRead.h"
#include <ctype.h>
#include <stdbool.h>

int readInt(const char *prompt, int min, int max) {
    while (1) {
        printf("%s ", prompt);
        char str[13];
        fgets(str, sizeof(str), stdin);
        if (strchr(str, '\n') == NULL) {
            int c;
            while ((c = fgetc(stdin)) != '\n' && c != EOF);
            printf("Введенная строка превышает допустимый размер\n");
            continue;
        }
        char *end = NULL;
        errno = 0;
        int n = (int) strtol(str, &end, 10);
        if (errno == ERANGE) {
            printf("Переполнение\n");
            continue;
        }
        if (end == str) {
            printf("Не удалось применить преобразование\n");
            continue;
        }
        bool correct = true;
        for (char *p = end; *p; ++p) {
            if (!isspace((int) *p)) {
                correct = false;
                break;
            }
        }
        if (correct == false) {
            printf("Некорректная строка\n");
            continue;
        }
        if (n > max || n < min) {
            printf("Допустимый диапазон от %d до %d\n", min, max);
            continue;
        }
        return n;
    }
}

double readDouble(const char *prompt, double min, double max) {
    while (1) {
        printf("%s ", prompt);
        char str[24];
        fgets(str, sizeof(str), stdin);
        if (strchr(str, '\n') == NULL) {
            int c;
            while ((c = fgetc(stdin)) != '\n' && c != EOF);
            printf("Введенная строка превышает допустимый размер\n");
            continue;
        }
        char *end = NULL;
        errno = 0;
        double n = strtod(str, &end);
        if (errno == ERANGE) {
            printf("Переполнение\n");
            continue;
        }
        if (end == str) {
            printf("Не удалось применить преобразование\n");
            continue;
        }
        bool correct = true;
        for (char *p = end; *p; ++p) {
            if (!isspace((int) *p)) {
                correct = false;
                break;
            }
        }
        if (correct == false) {
            printf("Некорректная строка\n");
            continue;
        }
        if (n > max || n < min) {
            printf("Допустимый диапазон от %f до %f\n", min, max);
            continue;
        }
        return n;
    }
}

char *readStr(const char *prompt) {
    printf("%s", prompt);
    int size=0;
    int capacity = 16;
    char *str = malloc(capacity);
    int ch=EOF;
    while ((ch = fgetc(stdin)) != '\n' && ch != 0) {
        if (size == capacity-1) {
            capacity += 16;
            str = (char *) realloc(str, capacity);
        }
        str[size] =(char) ch;
        size++;
    }
    str[size]='\0';
    return str;
}
