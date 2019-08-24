#pragma once 
#include <stdio.h>
#define MAX_NAME_LENGTH 32
/**
 * Структура для хранения данных о человеке
 */

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

/**
 * Функция создания структуры Person
 *
 * @param lastName Фамилия
 * @param firstName Имя
 * @param middleName Отчество
 * @param birthDay
 * @param birthMonth
 * @param birthYear
 * @return Указатель на созданную структуру
 */
struct Person* createPerson(const char* lastName,
                            const char* firstName,
                            const char* middleName,
                            unsigned char birthDay,
                            unsigned char birthMonth,
                            int birthYear);

/**
 * Функция открытия Database
 *
 * @param path Путь базы данных
 * @return указатель на структуру Database
 */
struct Database* openDatabase(const char* path);

/**
 * Функция закрытия Database
 *
 * @param d Указатель на структуру
 */
void closeDatabase(struct Database* d);
/**
 * Функция получения указателя на Person по ID
 *
 * @param d Указатель на Database
 * @param id Требуемый ID
 * @return Укзатель на Person
 */
struct Person* getPersonByID(struct Database* d, int id);
/**
 * Функция получения указателя на Person по индексу
 *
 * @param d Указатель на Database
 * @param numb ID для получения требуемого Person
 * @return Указатель на Person
 */
struct Person* getPersonByIndex(struct Database* d,unsigned int numb);
/**
 * Функция нахождения количества структур Person в Database
 *
 * @param d Указатель на Database
 * @return Число структур Person
 */
unsigned int getPersonCount(struct Database* d);
/**
 * Функция добавления Person в Database
 *
 * @param d Указатель на Database
 * @param person Указатель на Person
 */
void addPerson(struct Database* d, struct Person* person);
/**
 * Функция удаления Person из Database по ID
 *
 * @param d Указатель на Database
 * @param id ID для удаления Person
 */
void removePerson(struct Database* d, int id);

/**
 * Просмотр всей базы данных в сокращенном виде (id, фамилия, инициалы);
 *
 * @param d Указатель на базу данных
 */
void printShort(struct Database* d);

/**
 * Функция печати всей информации о человеке из базы данных по указанному ID
 *
 * @param d Указатель на базу данных
 * @param id ID требуемого Person
 */
void printPerson(struct Database* d,int id);

