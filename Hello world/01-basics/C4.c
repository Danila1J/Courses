#include <stdio.h>

void zd(double a,double b,double c){
    printf("%d\n",(a<b+c) & (b<a+c) & (c<a+b));
}

int main(){
    double a,b,c;
    scanf("%lf %lf %lf", &a,&b,&c);
    zd(a,b,c);
}