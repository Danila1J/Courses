#pragma once 
#include <stdio.h>
#define MAX_NAME_LENGTH 32

struct Person {
	int id;
	char lastName[MAX_NAME_LENGTH];
	char firstName[MAX_NAME_LENGTH];
	char middleName[MAX_NAME_LENGTH];
	unsigned char birthDay;
	unsigned char birthMonth;
	int birthYear;
};

struct Person* createPerson(const char* lastName,
	const char* firstName,
	const char* middleName,
	const unsigned char birthDay,
	const unsigned char birthMonth,
	const int birthYear);
struct Person* getPersonByID(FILE* f, int id);
struct Person* getPersonByIndex(FILE* f, const int numb);
void printPerson(const struct Person*const person);
int getPersonCount(FILE* f);
void addPerson(FILE* f, const struct Person* const person);
void removePerson(FILE* f, int id);
