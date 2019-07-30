#include <stdio.h>

void zd(int n){
    int k=n/3600;
    int ot=(n-3600*k);
    printf("С начала суток прошло часов: %d", ot);
}

int main(){
    int N;
    scanf("%d", &N);//Считывание с клавиатуры введенного значения
    zd(N);
}