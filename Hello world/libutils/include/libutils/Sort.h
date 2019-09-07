#pragma once
#include <stdbool.h>

void selectionSort(int *mas,int n);
void merge(const int *p1, int n1, const int *p2, int n2, int *dst, bool forward);
void swap(int *n1, int *n2);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int n);
void shakerSort(int *arr, int n);
void quickSort(int *data, int first, int last);
void naturalMergeSort(int* arr, int n);

