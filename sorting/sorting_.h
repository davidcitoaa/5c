#ifndef INC_4C_SORTING__H
#define INC_4C_SORTING__H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>

void swap(int *a, int *b);

void inputArray(int *a, size_t n);

void outputArray(const int *a, size_t n);

bool isOrdered(const int *a, size_t n);

void append(int *a, size_t *n, int x);

// Сортировка Выбором >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void selectionSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Вставками >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insertionSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Пузырьком >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubbleSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Расческой
void combSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Быстрая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void qSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Подсчетом >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int getMinElemArray(const int *a, size_t n);

int getMaxElemArray(const int *a, size_t n);

void countSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Слиянием >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void merge(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c);

static void
mergeSort_(int *source, size_t leftBorder, size_t rightBorder, int *buffer);

void mergeSort(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Шелла >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void shellSort(int *a, size_t n);

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int compareInts(const void *a, const void *b);

long long insertionSortN(int *a, size_t size);

long long bubbleSortN(int *a, size_t size);

long long combsortN(int *a, const size_t size);

long long shellSortN(int *a, size_t size);

long long mergeN(const int *a, const size_t n, const int *b, const size_t m, int *c);

long long mergeSortN_(int *source, size_t l, size_t r, int *buffer);

long long mergeSortN(int *a, size_t n);

long long selectionSortN(int *a, size_t size);

#endif //INC_4C_SORTING__H
