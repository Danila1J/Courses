#include <stdio.h>

int per(int num){
    int a,b,c;
    a = num % 10; //последнее число
    num /= 10; //первые два
    b = num % 10; //число по середине
    num /= 10;
    c = num; //первое число
    num = b * 100 + c * 10 + a; //
    return num;
}
int main(){
    printf("Введите число для перестановки(длина числа 3 знака)");
    int n;
    scanf("%d",&n);
    printf("%d",per(n));
}