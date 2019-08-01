#include <stdio.h>
#include <stdlib.h>

void fromAToB(int a, int b) {
    for(int i=0;i<=b-a+1;++i){
        for(int j=0;j<i;++j){
            printf("%d",a+i-1);
        }
    }
}

int main(int argc, const char *argv[]) {
    int a,b;
    if (argc < 3) {
        printf("Введите числа А и В (А<В): ");
        scanf("%d %d", &a, &b);
    } else {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    fromAToB(a,b);
}