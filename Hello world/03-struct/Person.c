#include "Person.h"
#include <stdlib.h>
#include <string.h>

struct Person* createPerson(
	const char* lastName,
	const char* firstName,
	const char* middleName,
	const unsigned char birthDay,
	const unsigned char birthMonth,
	const int birthYear) {
	struct Person* const person = (struct Person*)malloc(sizeof(struct Person));
	person->id = 0;
	strncpy_s(person->lastName, MAX_NAME_LENGTH, lastName, strlen(lastName));
	strncpy_s(person->firstName, MAX_NAME_LENGTH, firstName, strlen(firstName));
	strncpy_s(person->middleName, MAX_NAME_LENGTH, middleName, strlen(middleName));
	person->birthDay = birthDay;
	person->birthMonth = birthMonth;
	person->birthYear = birthYear;
	return person;
}

struct Person* getPersonByID(FILE* f, const int id);

struct Person* getPersonByIndex(FILE* f, const int index) {
	struct Person* const person = (struct Person*)malloc(sizeof(struct Person));
	fseek(f, index * sizeof(struct Person), SEEK_SET);
	fread(person, sizeof(struct Person), 1, f);
	return person;
}

int getPersonCount(FILE* f) {
	fseek(f, 0, SEEK_END);
	const long sizeFile = ftell(f);
	return sizeFile / sizeof(struct Person);
}

void addPerson(FILE* f, const struct Person* const person) {
	fseek(f, 0, SEEK_END);
	fwrite(person, sizeof(struct Person), 1, f);
}

void removePerson(FILE* f, const int id);