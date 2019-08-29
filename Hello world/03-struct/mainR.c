#include <stdio.h>
#include "SafeRead.h"


int main(){
    char *n=readStr("Введите строку: ");
    printf("%s",n);
    free(n);
}
