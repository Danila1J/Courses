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

char *concat(char *s1, char *s2) {
    size_t len1 = strleng(s1);
    size_t len2 = strleng(s2);
    char *result = malloc(len1 + len2 + 1);
    if (!result) {
        fprintf(stderr, "malloc() failed\n");
        return NULL;
    }
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

char *concatn(char *front, char *back, size_t count) {
    size_t len1 = strleng(front);
    size_t len2=count;
    if(count>=strleng(back)){
        len2 = strleng(back);
    }
    char *result = malloc(len1 +len2+ 1);
    if (!result) {
        fprintf(stderr, "malloc() failed\n");
        return NULL;
    }
    memcpy(result, front, len1);
    for (size_t i = 0; i <count ; ++i) {
        memcpy(result+len1+i,&back[i],1);
    }
    return result;
}

int main() {
    char *s = concatn("first", "second", 100);
    printf("%s\n", s);
    char str[100];
    strncopy(str,"Hello world",7);
    printf("%s",str);
    free(s);
}
