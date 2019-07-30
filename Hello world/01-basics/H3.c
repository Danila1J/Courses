#include <stdio.h>

void zd(int a,int b,int c){
    int num=(a/c)*(b/c);
    printf("Количество квадратов размещенных на прямоугольнике %d\n",num);
    int s=a*b-num*c*c;
    printf("Площадь незанятой части прямоугольника %d\n",s);
}

int main(){
    printf("Введите 3 целых положительных числа: a b c");
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    zd(a,b,c);
}