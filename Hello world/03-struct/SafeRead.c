#include "SafeRead.h"

int read_int(const char *prompt, int min, int max) {
    while (1) {
        Start:
        printf("%s ", prompt);
        char mas[11];
        fgets(mas, sizeof(mas), stdin);
        if (strchr(mas, 10) == NULL) {
            int c;//не работает!!!!!!!!!!!!1
            while ((c=fgetc(stdin))!='\n'||(c=fgetc(stdin))!=EOF){
                ;
            }
            printf("Введенная строка превышает допустимый размер\n");
            goto Start;
        }
        char* end;
        int n=strtol(mas,&end,10);
        if(errno==ERANGE){
            printf("Переполнение\n");
            goto Start;
        }
        if(n==0){
            char c=getchar();
            if(c!=0x0030){
                goto Start;
            }
        }
        if(n>max||n<min){
            printf("Допустимый диапазон от %d до %d\n",min,max);
            goto Start;
        }
        return n;
    }
}
