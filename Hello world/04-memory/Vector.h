#include <stdlib.h>
/**
��������� ��� ������ � ������������ �������� float

*/
struct Vector {
	float* data; /*< ������������ ������ float */
	size_t capacity; /*< ����� ��������� ��� ������� �������� ������*/
	size_t size; /*< �������� ����� ��������� � �������*/
};
/**
������� �������������� ��������� Vector � ��������� ����������� ���������
@param v ��������� �� ���������
@param n ���������� ���������
*/
void vectorInit(struct Vector* const v, size_t n);
void vectorPrint(const struct Vector* const s);