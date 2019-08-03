#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*!
 * @brief Функция вычисления расстояние между точками
 *
 * @f$d=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(z_2-z_1)^2}\f$
 *
 * @code
 * double distPoints(double x1, double x2, double y1, double y2, double z1, double z2) {
    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
    return d;
    }
 * @endcode
 * @param x1 Координата точки 1 по x
 * @param y1 Координата точки 1 по y
 * @param z1 Координата точки 1 по z
 * @param x2 Координата точки 2 по x
 * @param y2 Координата точки 2 по y
 * @param z2 Координата точки 2 по z
 * @return d Расстояние между двумя точками
 *
 */

double distPoints(double x1, double x2, double y1, double y2, double z1, double z2) {
    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
    return d;
}

int main(int argc, const char *argv[]) {
    double x1, x2, y1, y2, z1, z2;
    if (argc != 7) {
        printf("Введите координаты точек: x1,y1,z1,x2,y2,z2");
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
    } else {
        x1 = atof(argv[1]);
        y1 = atof(argv[2]);
        z1 = atof(argv[3]);
        x2 = atof(argv[4]);
        y2 = atof(argv[5]);
        z2 = atof(argv[6]);
    }
    double ot = distPoints(x1, x2, y1, y2, z1, z2);
    printf("%lf", ot);
}