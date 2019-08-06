#include "Person.h"
#include <stdlib.h>
#include <string.h>

struct Person *createPerson(
        const char *lastName,
        const char *firstName,
        const char *middleName,
        const unsigned char birthDay,
        const unsigned char birthMonth,
        const int birthYear) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    person->id = rand() % 100;
    strncpy(person->lastName, lastName, MAX_NAME_LENGTH);
    strncpy(person->firstName, firstName, MAX_NAME_LENGTH);
    strncpy(person->middleName, middleName, MAX_NAME_LENGTH);
    person->birthDay = birthDay;
    person->birthMonth = birthMonth;
    person->birthYear = birthYear;
    return person;
}

struct Person *getPersonByID(FILE *f, const int id) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    const int byteCount = getPersonCount(f) * sizeof(struct Person);
    for (int i = 0; i < byteCount; i += sizeof(struct Person)) {
        fseek(f, i * sizeof(struct Person), SEEK_SET);
        fread(person, sizeof(struct Person), 1, f);
        if (person->id == id) {
            return person;
        }
    }
    return NULL;
}

struct Person *getPersonByIndex(FILE *f, const int index) {
    struct Person *const person = (struct Person *) malloc(sizeof(struct Person));
    fseek(f, index * sizeof(struct Person), SEEK_SET);
    fread(person, sizeof(struct Person), 1, f);
    return person;
}

int getPersonCount(FILE *f) {
    fseek(f, 0, SEEK_END);
    const long sizeFile = ftell(f);
    return sizeFile / sizeof(struct Person);
}

void printPerson(const struct Person *const person) {
    printf("%d\n", person->id);
    printf("%d.%d.%d\n", person->birthDay, person->birthMonth, person->birthYear);
    printf("%s %s %s\n", person->lastName, person->firstName, person->middleName);
}

void addPerson(FILE *f, const struct Person *const person) {
    fseek(f, 0, SEEK_END);
    fwrite(person, sizeof(struct Person), 1, f);
}

void removePerson(FILE *f, const int id);
