#include <stdlib.h>

/**
 * Перечислимый тип Type для указания способа хранения матрицы
 * FLAT - матрица хранится в виде одномерного массива
 * ROW - массив указателей на массивы строк
 * COLUMN - массив указателей на массивы столбцов
 * VIRTUAL - подматрица в базовой матрице
 */
enum Type {
	FLAT,
	ROW,
	COLUMN,
	VIRTUAL
};

/**
 * Структура Матрицы
 * void* data - указатель на данные
 * enum Type type - способ хранения матрицы
 * rows - кол-во строк в матрице
 * cols - кол-во столбцов в матрице
 * shiftRow и shiftCol смещение подматрицы относительно базовой матрицы ( нужно если матрица имеет тип VIRTUAL )
 */

struct Matrix {
	void* data;
	enum Type type;
	size_t rows;
	size_t cols;
	size_t shiftRow;
	size_t shiftCol;
};
/**
 * @brief Функция инициализации матрицы числами от numberFrom до numberTo включительно
 *
 * Если чисел не хватает для заполнения матрицы то она продолжает заполняться с numberFrom и так далее
 *
 * @param matrix Указатель на матрицу
 * @param numberFrom Инициализация числами от
 * @param numberTo Инициализация числами до
 */
void InitMatrix(struct Matrix*matrix, int numberFrom,int numberTo);

/**
 * @brief Функция создания матрица с хранением типа Virtual
 *
 * Если матрица типа Virtual выходит за границы базовый матрицы, то матрица Virtual "обрезается"
 *
 * @param structMatrixBase Указатель на базовую матрицу
 * @param indRow Индекс строки 1 элемента матрицы Virtual
 * @param indCol Индекс столбца 1 элемента матрицы Virtual
 * @param rows Количество строк в матрице типа Virtual
 * @param cols Количество столбцов в матрице типа Virtual
 * @return Указатель на созданную матрицу
 */
struct Matrix* CreateVirtualMatrix(struct Matrix* structMatrixBase, size_t indRow, size_t indCol, size_t rows, size_t cols);

/**
 * @brief Функция создания матрицы
 *
 * @param type Тип матрицы (FLAT,ROW,COLUMN)
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на созданную матрицу
 */
struct Matrix* CreateMatrix(enum Type type, size_t rows, size_t cols);

/**
 *  @brief Функция установки значения по индексам в матрице
 *
 * @param matrix Указатель на матрицу
 * @param f Значение которое мы хотим установить
 * @param indRow Индекс строки
 * @param indCol Индекс столбца
 */
void SetMatrixValue(struct Matrix* matrix,float f, size_t indRow, size_t indCol);

/**
 * @brief Функция получения значения по индексам в матрице
 *
 * @param structMatrix Указатель на матрицу
 * @param indRow Индекс строки
 * @param indCol Индекс столбца
 * @return Полученное значение
 */
float GetMatrixValue(const struct Matrix* structMatrix, size_t indRow, size_t indCol);

/**
 * @brief Функция уничтоения матрицы
 *
 * @param structMatrix Указатель на матрицу
 */
void DestroyMatrix(struct Matrix* structMatrix);

/**
 * @brief Функция для обмена строк двух матриц
 *
 * @param matrix_1 Матрица 1
 * @param matrix_2 Матрица 2
 * @param indRow_1 Индекс строки первой матрицы
 * @param indRow_2 Индекс строки второй матрицы
 */
void SwapRows(struct Matrix* matrix_1, struct Matrix* matrix_2, size_t indRow_1, size_t indRow_2);

/**
 * @brief Функция печати матрицы в консоль
 *
 * @param structMatrix Указатель на матрицу
 */
void PrintMatrix(const struct Matrix* structMatrix);

