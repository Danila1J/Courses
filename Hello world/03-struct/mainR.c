#include <stdio.h>
#include "SafeRead.h"


int main(){
    int n=read_int("Введите целое число:",0,1000);
    printf("%d",n);
}
