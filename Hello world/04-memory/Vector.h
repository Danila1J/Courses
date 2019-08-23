#include <stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/**
Структура для работы с динамическим массивом float

*/
struct Vector {
	float* data; /*< Динамический массив float */
	size_t capacity; /*< Число элементов под которые выделена память*/
	size_t size; /*< Реальное число элементов в массиве*/
};
/**
@brief Функция инициализирует структуру Vector с указанным количеством элементов

@param v указатель на структуру
@param n количество элементов
*/
void vectorInit(struct Vector* const v, size_t n);

/**
 * @brief Функция печати Vector в консоль
 *
 * @param s Указатель на структру Vector
 */
void vectorPrint(const struct Vector* const s);

/**
 * @brief Функция освобождения структуры Vector
 *
 * @param s Указатель на структуру
 */
void vectorFree(struct Vector* s);

/**
 * @brief Функция поиска индекса первого встречающегося значения удовлетворяющему предикату
 *
 * @param s Указатель на Vector
 * @param p Предикат
 * @return Индекс первого встречающегося значения удовлетворяющему предикату
 */
int firstIndexOf(const struct Vector* const s,predicate p);

/**
 * @brief Функция поиска индекса последнего встречающегося значения удовлетворяющему предикату
 *
 * @param structVector Указатель на Vector
 * @param p Предикат
 * @return Индекс последнего встречающегося значения удовлетворяющему предикату
 */
int lastIndexOf(const struct Vector* const structVector,predicate p);

/**
 * @brief Функция вставки нового значения в Vector по индексу
 *
 * @param structVector Указатель на Vector
 * @param index Индекс куда нужно вставить
 * @param f Новое значение для вставки
 */
void vectorInsert(struct Vector* const structVector,int index,float f);

/**
 * @brief Функция удаления значения по индексу из Vector
 *
 * @param structVector Указатель на Vector
 * @param index Индекс удаляемого значения
 */
void vectorRemove(struct Vector* const structVector,int index);

