#include <stdlib.h>
#include <stdbool.h>
/**
Структура для работы с динамическим массивом float

*/
struct Vector {
	float* data; /*< Динамический массив float */
	size_t capacity; /*< Число элементов под которые выделена память*/
	size_t size; /*< Реальное число элементов в массиве*/
};
/**
Функция инициализирует структуру Vector с указанным количеством элементов
@param v указатель на структуру
@param n количество элементов
*/
void vectorInit(struct Vector* const v, size_t n);
void vectorPrint(const struct Vector* const s);
void vectorFree(struct Vector* const s);
int firstIndexOf(const struct Vector* const s,float f);
int lastIndexOf(const struct Vector* const structVector,float f);
void vectorInsert(struct Vector* const structVector,int index,float f);
void vectorRemove(struct Vector* const structVector,int index);

