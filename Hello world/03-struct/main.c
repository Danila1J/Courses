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
                char id_s[1];
                scanf("%s", id_s);
                printf("------------------------------\n");
                printPerson(d, strtol(id_s,&end,10));
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
                unsigned char birthD;
                scanf("%hhu", &birthD);
                printf("Введите месяц рождения: ");
                unsigned char birthM;
                scanf("%hhu", &birthM);
                printf("Введите год рождения: ");
                int birthY;
                scanf("%d", &birthY);
                struct Person *p = createPerson(sF, sI, sO, birthD, birthM, birthY);
                addPerson(d, p);
                free(p);
                printf("------------------------------\n");
                break;
            }
            case 3: {
                printf("------------------------------\n");
                printf("Введите ID человека, для удаления из базы данных: ");
                int id;
                scanf("%d", &id);
                removePerson(d, id);
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
