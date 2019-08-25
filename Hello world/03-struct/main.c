#include "Person.h"
#include <stdlib.h>

int main() {
    struct Database *d = openDatabase("data");
    struct Person *p1 = createPerson("Ivanov", "Danila", "Aleksandrovich", 30, 12, 1999);
    struct Person *p2 = createPerson("Alekseeva", "Liza", "Alekseevna", 26, 6, 1999);
    addPerson(d, p1);
    addPerson(d, p2);
    while (1) {
        printf("0 -  просмотр всей базы в сокращённом формате (id, фамилия, инициалы);\n"
               "1 - просмотр всей информации о человеке по указанному id;\n"
               "2 - добавление нового человека в базу данных;\n"
               "3 - удаление человека из базы данных.\n"
               "любая другая цифра - закрытие меню\n");
        printf("Введите команду: ");
        char n[1];
        char* end;
        scanf("%s", n);
        switch (strtol(n,&end,10)) {
            case 0: {
                printf("------------------------------\n");
                printShort(d);
                printf("------------------------------\n");
                break;
            }
            case 1: {
                printf("Введите требуемый ID: ");
                char id_s[10];
                scanf("%s", id_s);
                printf("------------------------------\n");
                printPerson(d, (int)strtol(id_s,&end,10));
                printf("------------------------------\n");
                break;
            }
            case 2: {
                printf("------------------------------\n");
                printf("Введите фамилию: ");
                char sF[MAX_NAME_LENGTH];
                scanf("%s", sF);
                printf("Введите имя: ");
                char sI[MAX_NAME_LENGTH];
                scanf("%s", sI);
                printf("Введите отчество: ");
                char sO[MAX_NAME_LENGTH];
                scanf("%s", sO);
                printf("Введите день рождения: ");
                char birthD[2];
                scanf("%s", birthD);
                printf("Введите месяц рождения: ");
                char birthM[2];
                scanf("%s", birthM);
                printf("Введите год рождения: ");
                char birthY[4];
                scanf("%s", birthY);
                struct Person *p = createPerson(sF, sI, sO,(unsigned char) strtoul(birthD,&end,10), (unsigned char) strtoul(birthM,&end,10), (int) strtoul(birthY,&end,10));
                addPerson(d, p);
                free(p);
                printf("------------------------------\n");
                break;
            }
            case 3: {
                printf("------------------------------\n");
                printf("Введите ID человека, для удаления из базы данных: ");
                char id[10];
                scanf("%s", id);
                removePerson(d, (int)strtol(id,&end,10));
                printf("------------------------------\n");
                break;
            }
            default:
                goto Exit;
        }
    }
    Exit:
    closeDatabase(d);
    free(p1);
    free(p2);
}
