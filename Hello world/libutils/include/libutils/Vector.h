#include <stdlib.h>
#include <stdbool.h>

typedef bool (*predicate) (float);

/**
Структура для работы с динамическим массивом float

*/
struct Vector;
/**
@brief Функция инициализирует структуру Vector с указанным количеством элементов

@param s указатель на структуру
@param n количество элементов
*/
void vector_create(struct Vector* const s, size_t n);

/**
 * @brief Функция печати Vector в консоль
 *
 * @param s Указатель на структру Vector
 */
void vector_print(const struct Vector* const s);

/**
 * @brief Функция освобождения структуры Vector
 *
 * @param s Указатель на структуру
 */
void vector_free(struct Vector* s);

/**
 * @brief Функция поиска индекса первого встречающегося значения удовлетворяющему предикату
 *
 * @param structVector Указатель на Vector
 * @param p Предикат
 * @return Индекс первого встречающегося значения удовлетворяющему предикату
 */
int vector_search(const struct Vector* const structVector, predicate p);

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
void vector_insert(struct Vector* const structVector, int index, float f);

/**
 * @brief Функция удаления значения по индексу из Vector
 *
 * @param structVector Указатель на Vector
 * @param index Индекс удаляемого значения
 */
void vector_remove(struct Vector* const structVector, size_t index);

int vector_get(struct Vector* v,size_t index);
void vector_sort(struct Vector* v,int n);
void vector_add(struct Vector* v,float f);
void vector_set(struct Vector* v,size_t index, float f);

