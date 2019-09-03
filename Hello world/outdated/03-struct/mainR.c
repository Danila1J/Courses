#include <stdio.h>
#include "SafeRead.h"


int main(){
    int n=readInt("Введите целое число: ",0,1000);
    printf("Введенное число: %d\n",n);
    double d=readDouble("Введите вещественное число: ",0.0,1000.0);
    printf("Введенное число: %f\n",d);
    char *s=readStr("Введите строку: ");
    printf("Введенная строка: %s\n",s);
    free(s);
}
