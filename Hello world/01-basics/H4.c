#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void queen(int x1, int y1, int x2, int y2) {
    int z = (x1 == x2) || (y1 == y2);//горизонтально или вертикально одна из координат должна совпадать
    int v = abs(x1 - x2) == abs(y1 - y2);// по диагонали квадрата, а у квадрата
    // все стороны равны, то это означает, что насколько изменяется
    //координата x, настолько же меняется и координата y; то есть
    //нужно находить разницу. Но поскольку мы не знаем, каково из
    //чисел больше или меньше, то эту разницу вычисляем по модулю
    int sln = z || v;
    printf("%d\n",sln);
}

int main(int argc, const char *argv[]){
    int x1,y1,x2,y2;
    if (argc < 4) {
        printf("Введите координаты шахматной доски(1-8): x1 y1 x2 y2");
        scanf("%d %d %d",&x1,&y1,&x2,&y2);
    } else {
        x1 = atoi(argv[1]);
        y1 = atoi(argv[2]);
        x2 = atoi(argv[3]);
        y2 = atoi(argv[4]);
    }
    queen(x1,y1,x2,y2);
}