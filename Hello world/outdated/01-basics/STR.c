#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void strcopy(char *t, char *s) {
    while ((*t++ = *s++) != '\0');
}

void strncopy(char *dst, char *src, size_t count) {
    size_t i = 0;
    while (i++ != count && (*dst++ = *src++));
    for (; count--; *dst++ = '\0');
}

size_t strleng(const char *input) {
    size_t length = 0;
    while (input[length] != '\0') {
        length++;
    }
    return length;

}

char* concat(char *dest, const char *src) {
    size_t i = 0;
    for (; dest[i] != 0; ++i) {
    }
    for (; *src != 0; ++src, ++i) {
        dest[i] = *src;
    }
    dest[i] = 0;
    return dest;
}

char* concatn(char *dest, const char *src, size_t n) {
    while(*dest) {
        ++dest;
    }
    for (size_t i = 0; i < n && *src != 0; ++i, ++src, ++dest) {
        *dest = *src;
    }
    *dest = 0;
    return dest;
}

int main() {
    char *s = concatn("first", "second", 100);
    printf("%s\n", s);
    char str[100];
    strncopy(str,"Hello world",7);
    printf("%s",str);
    free(s);
}
