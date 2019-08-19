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

struct Database;

struct Person* createPerson(const char* lastName,
	const char* firstName,
	const char* middleName,
	const unsigned char birthDay,
	const unsigned char birthMonth,
	const int birthYear);
struct Database* openDatabase(const char* path);
void closeDatabase(struct Database* d);
struct Person* getPersonByID(struct Database* d, int id);
struct Person* getPersonByIndex(struct Database* d, const int numb);
void printPerson(const struct Person*const person);
int getPersonCount(struct Database* d);
void addPerson(struct Database* d, struct Person* const person);
void removePerson(struct Database* d, int id);
