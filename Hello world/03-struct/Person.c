#include "Person.h"
#include <stdlib.h>
#include <string.h>

struct Database{
    FILE* f;
    char* path;
};

struct Database* openDatabase(const char* path){
    char* pathCpy= malloc(strlen(path)+1);
    strcpy(pathCpy,path);
    struct Database* d=malloc(sizeof(struct Database));
    d->path=pathCpy;
    d->f=fopen(pathCpy,"w+");
    return d;
}
void closeDatabase(struct Database* d){
    fclose(d->f);
    free(d->path);
    free(d);
}

struct Person *createPerson(
        const char *lastName,
        const char *firstName,
        const char *middleName,
        const unsigned char birthDay,
        const unsigned char birthMonth,
        const int birthYear) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    person->id = 0;
    strncpy(person->lastName, lastName, MAX_NAME_LENGTH);
    strncpy(person->firstName, firstName, MAX_NAME_LENGTH);
    strncpy(person->middleName, middleName, MAX_NAME_LENGTH);
    person->birthDay = birthDay;
    person->birthMonth = birthMonth;
    person->birthYear = birthYear;
    return person;
}

struct Person *getPersonByID(struct Database* d, const int id) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    size_t byteCount = getPersonCount(d) * sizeof(struct Person);
    for (size_t i = 0; i < byteCount; i += sizeof(struct Person)) {
        fseek(d->f, i * sizeof(struct Person), SEEK_SET);
        fread(person, sizeof(struct Person), 1, d->f);
        if (person->id == id) {
            return person;
        }
    }
    free(person);
    return NULL;
}

struct Person *getPersonByIndex(struct Database* d, const unsigned int index) {
    if(index>=getPersonCount(d)) return NULL;
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    fseek(d->f, index * sizeof(struct Person), SEEK_SET);
    fread(person, sizeof(struct Person), 1, d->f);
    return person;
}

unsigned int getPersonCount(struct Database* d) {
    fseek(d->f, 0, SEEK_END);
    const long sizeFile = ftell(d->f);
    return sizeFile / sizeof(struct Person);
}

void printPerson(struct Database* d,int id) {
    struct Person* person=getPersonByID(d,id);
    printf("ID: %d\n", person->id);
    printf("Дата рождения: %d.%d.%d\n", person->birthDay, person->birthMonth, person->birthYear);
    printf("ФИО: %s %s %s\n", person->lastName, person->firstName, person->middleName);
}

void addPerson(struct Database* d, struct Person *const person) {
    struct Person *const person_i = (struct Person *) malloc(sizeof(struct Person));
    size_t byteCount = getPersonCount(d) * sizeof(struct Person);
    int maxId=0;
    for (size_t i = 0; i < byteCount; i += sizeof(struct Person)) {
        fseek(d->f, i , SEEK_SET);
        fread(person_i, sizeof(struct Person), 1, d->f);
        if(person_i->id>=maxId){
            maxId=person_i->id+1;
        }
    }
    free(person_i);
    person->id=maxId;
    fseek(d->f, 0, SEEK_END);
    fwrite(person, sizeof(struct Person), 1, d->f);
}

void removePerson(struct Database* d, const int id) {
    fseek(d->f, 0, SEEK_END);
    long sizeFile = ftell(d->f);
    struct Person *person=(struct Person*)malloc((size_t)sizeFile);
    fseek(d->f,0,SEEK_SET);
    fread(person, sizeof(struct Person), sizeFile/ sizeof(struct Person), d->f);
    size_t countPersons=getPersonCount(d);
    d->f=freopen(d->path,"w+",d->f);
    for (size_t i = 0; i <countPersons ; ++i) {
        if((person+i)->id!=id){
            fwrite(person+i, sizeof(struct Person),1,d->f);
        }
    }
    free(person);
}

void printShort(struct Database* d){
    for (size_t i = 0; i <getPersonCount(d) ; ++i) {
        struct Person* person=getPersonByIndex(d,i);
        printf("ID: %d, %s %.1s. %.1s.\n",person->id,person->lastName,person->firstName,person->middleName);
    }
}
