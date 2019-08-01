#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numbOfDaysInYear(int year) {
    if((year%4==0&&year%100!=0)||year%400==0){
        return 1;
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    unsigned int year;
    if (argc < 2) {
        printf("Введите номер года: ");
        scanf("%d", &year);
    } else {
        year = atoi(argv[1]);
    }
    printf("%d",numbOfDaysInYear(year));
}