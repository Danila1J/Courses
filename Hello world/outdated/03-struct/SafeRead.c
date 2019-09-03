#include "SafeRead.h"

int readInt(const char *prompt, int min, int max) {
    while (1) {
        printf("%s ", prompt);
        char str[16];
        fgets(str, sizeof(str), stdin);
        if (strchr(str, '\n') == NULL) {
            int c;
            bool flag = true;
            while ((c = fgetc(stdin)) != '\n' && c != EOF) {
                if (!isspace(c)) {
                    flag = false;
                }
            }
            if (flag == false) {
                printf("Введенная строка превышает допустимый размер\n");
                continue;
            }
        }
        char *endptr = NULL;
        errno = 0;
        int n = (int) strtol(str, &endptr, 10);
        int tmp = errno;
        if (tmp == ERANGE) {
            printf("Переполнение\n");
            continue;
        }
        if (endptr == str) {
            printf("Не удалось применить преобразование\n");
            continue;
        }
        bool correct = true;
        for (char *p = endptr; *p != '\0'; ++p) {
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
        char str[32];
        fgets(str, sizeof(str), stdin);
        if (strchr(str, '\n') == NULL) {
            int c;
            bool flag = true;
            while ((c = fgetc(stdin)) != '\n' && c != EOF) {
                if (!isspace(c)) {
                    flag = false;
                }
            }
            if (flag == false) {
                printf("Введенная строка превышает допустимый размер\n");
                continue;
            }
        }
        char *endptr = NULL;
        errno = 0;
        double n = strtod(str, &endptr);
        int tmp = errno;
        if (tmp == ERANGE) {
            printf("Переполнение\n");
            continue;
        }
        if (endptr == str) {
            printf("Не удалось применить преобразование\n");
            continue;
        }
        bool correct = true;
        for (char *p = endptr; *p; ++p) {
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
    size_t size = 0;
    size_t capacity = 16;
    char *str = malloc(capacity);
    if (str == NULL) {
        int c;
        while ((c = fgetc(stdin)) != '\n' && c != EOF);
        printf("Не удалось выделить требуемый блок памяти");
        return NULL;
    }
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        if (size == capacity - 1) {
            capacity += 16;
            char *tmp = str;
            str = (char *) realloc(str, capacity);
            if (str == NULL) {
                printf("Не удалось выделить требуемый блок памяти");
                free(tmp);
                return NULL;
            }
        }
        str[size] = (char) ch;
        size++;
    }
    str[size] = '\0';
    return str;
}
