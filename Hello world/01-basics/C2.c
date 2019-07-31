#include <stdio.h>
#include <stdlib.h>

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