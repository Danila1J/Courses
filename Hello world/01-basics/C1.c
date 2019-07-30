#include <stdio.h>
#include <math.h>

double zd (double x1,double x2,double y1, double y2,double z1,double z2){
    double d=sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));
    return d;
}
int main(int argc,const char* argv[]){
    double x1,x2,y1,y2,z1,z2;
    if(argc<7){
        double ot=zd(x1,x2,y1,y2,z1,z2);
        printf("%lf", ot);
    } else{
        printf("Введите координаты точек: x1,y1,z1,x2,y2,z2");
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2);
        double ot=zd(x1,x2,y1,y2,z1,z2);
        printf("%lf", ot);
    }
}