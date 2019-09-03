#include "Person.h"
#include <stdlib.h>
#include <stdbool.h>
#include "SafeRead.h"

int main() {
    struct Database *d = openDatabase("data");
    struct Person *p1 = createPerson("Ivanov", "Danila", "Aleksandrovich", 30, 12, 1999);
    struct Person *p2 = createPerson("Alekseeva", "Liza", "Alekseevna", 26, 6, 1999);
    addPerson(d, p1);
    addPerson(d, p2);
    bool flag=true;
    while (flag) {
        printf("0 -  просмотр всей базы в сокращённом формате (id, фамилия, инициалы);\n"
               "1 - просмотр всей информации о человеке по указанному id;\n"
               "2 - добавление нового человека в базу данных;\n"
               "3 - удаление человека из базы данных.\n"
               "4 - закрытие меню\n");
        int command=readInt("Введите команду: ",0,10);
        switch (command) {
            case 0: {
                printf("------------------------------\n");
                printShort(d);
                printf("------------------------------\n");
                break;
            }
            case 1: {
                int id=readInt("Введите требуемый ID: ",0,1000);
                printf("------------------------------\n");
                struct Person* person=getPersonByID(d,id);
                printPerson(person);
                free(person);
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
                int birthD=readInt("Введите день рождения: ",0,31);
                int birthM=readInt("Введите месяц рождения: ",0,12);
                int birthY=readInt("Введите год рождения: ",0,2100);
                struct Person *p = createPerson(sF, sI, sO,(unsigned char) birthD, (unsigned char) birthM, birthY);
                addPerson(d, p);
                free(p);
                printf("------------------------------\n");
                break;
            }
            case 3: {
                printf("------------------------------\n");
                int id=readInt("Введите ID человека, для удаления из базы данных: ",0,1000);
                removePerson(d, id);
                printf("------------------------------\n");
                break;
            }
            default:
                flag=false;
        }
    }
    closeDatabase(d);
    free(p1);
    free(p2);
}
