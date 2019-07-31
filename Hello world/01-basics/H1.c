#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double quadraticRoots(double a,double b,double c){
    double Im,Re;
    if(a == 0 && b == 0 && c == 0) {
        printf("Некорректные коэффициенты");
    }
    if(a == 0 && b == 0 && c != 0) {
        printf("Некорректные коэффициенты");
    }
    if(a == 0 && c == 0 && b != 0) {
        printf("x = 0");
    }
    if (c == 0 && a != 0 && b != 0) {
        double x = -b / a;
        printf("Квадратное уравнение неполное, корни уравнения: x1 = 0, x2 = %g", x);
    } else if (a == 0 && b != 0 && c != 0) {
        double x = -c / b;
        printf("Линейное уранение, корень уравнения: x = %g", x);
    } else if (b == 0 && a != 0 && c != 0) {
        if(a > 0 && c < 0) {
            float sq = sqrt(-c / a);
            printf("x1 = +%gi\n", sq);
            printf("x2 = -%gi", sq);
        }
        if(a < 0 && c > 0) {
            float sq = sqrt(c / (-a));
            printf("x1 = +%gi\n", sq);
            printf("x2 = -%gi", sq);
        }
    } else if (b == 0 && c == 0 && a != 0) {
        printf("Квадратное уравнение неполное, корень уравнения: x = 0");
    } else if (a != 0 && b != 0 && c != 0) {
        double D = pow(b, 2) - 4 * a * c;
        if (D == 0) {
            double x = -b / (2 * a);
            printf("Дискриминант = 0, один корень уравнения: x = %g", x);
        }
        if (D > 0) {
            double x1 = -(b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D) / (2 * a));
            printf("Дискриминант > 0, два корня уравнения: x1 = %g, x2 = %g", x1, x2);
        }
        if (D < 0) {
            Re = -b / (2 * a);
            Im = sqrt(-D) / (2 * a);
            printf("x1 = %g + %gi\n", Re, Im);
            printf("x2 = %g - %gi\n", Re, Im);
        }
    }
}

int main(int argc, const char **argv) {
    double a,b,c;
    if (argc == 4) {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    } else{
        printf("Введите коэффициенты А, В, С: ");
        scanf("%lf %lf %lf", &a, &b, &c);
    }
    quadraticRoots(a,b,c);
}