#include "sorting_.h"

void swap(int *a, int *b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

void inputArray(int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(const int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

bool isOrdered(const int *a, const size_t n) {
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

void append(int *const a, size_t *n, const int x) {
    a[*n] = x;
    (*n)++;
}

// Сортировка Выбором >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void selectionSort(int *a, const size_t n) {
    for (register size_t i = 0; i < n; ++i) {
        size_t indexMin = i;
        for (register size_t j = i + 1; j < n; ++j)
            if (a[j] < a[indexMin])
                indexMin = j;
        if (indexMin != i)
            swap(&a[i], &a[indexMin]);
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Вставками >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insertionSort(int *a, const size_t n) {
    for (register size_t i = 1; i < n; ++i) {
        int t = a[i];
        register size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Пузырьком >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubbleSort(int *a, const size_t n) {
    for (register size_t i = 0; i < n - 1; ++i)
        for (register size_t j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(&a[j - 1], &a[j]);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void combSort(int *a, const size_t n) {
    size_t step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = false;
        for (register size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
        }
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Быстрая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void qSort(int *a, const size_t n) {
    assert(n > 0);

    register int leftBorder = 0;
    register int rightBorder = n - 1;
    int middle = leftBorder + (rightBorder - leftBorder) / 2;
    int t = a[middle];

    do {
        // часть , где числа меньше t
        while (a[leftBorder] < t)
            leftBorder++;
        // часть , где числа больше t
        while (a[rightBorder] > t)
            rightBorder--;
        if (leftBorder <= rightBorder) {
            swap(&a[rightBorder], &a[leftBorder]);
            leftBorder++;
            rightBorder--;
        }
    } while (leftBorder <= rightBorder);

    if (leftBorder < n)
        qSort(a + leftBorder, n - leftBorder);
    if (rightBorder > 0)
        qSort(a, rightBorder + 1);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Подсчетом >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int getMinElemArray(const int *a, const size_t n) {
    int elemMin = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < elemMin)
            elemMin = a[i];

    return elemMin;
}

int getMaxElemArray(const int *a, const size_t n) {
    int elemMax = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > elemMax)
            elemMax = a[i];

    return elemMax;
}

void countSort(int *a, const size_t n) {
    assert(n > 0);

    int elemMin = getMinElemArray(a, n);
    int elemMax = getMaxElemArray(a, n);
    size_t sizeArrayCountNumbers = elemMax - elemMin + 1;
    int *arrayCountNumbers = (int *) calloc(sizeArrayCountNumbers, sizeof(int));
    for (register size_t i = 0; i < n; ++i)
        arrayCountNumbers[a[i] - elemMin]++;

    size_t k = 0;
    for (register int i = 0; i < sizeArrayCountNumbers; ++i) {
        int x = arrayCountNumbers[i];
        for (register size_t j = 0; j < x; ++j)
            a[k++] = elemMin + i;
    }

    free(arrayCountNumbers);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Слиянием >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void merge(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c) {
    register size_t iReadA = 0;
    register size_t iReadB = 0;
    while (iReadA < sizeA || iReadB < sizeB) {
        if (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB]) {
            c[iReadA + iReadB] = a[iReadA];
            iReadA++;
        } else {
            c[iReadA + iReadB] = b[iReadB];
            iReadB++;
        }
    }
}

static void
mergeSort_(int *source, const size_t leftBorder, const size_t rightBorder, int *buffer) {
    int sizeSource = (int) rightBorder - leftBorder;
    if (sizeSource <= 1)
        return;

    size_t middle = (leftBorder + rightBorder) / 2;
    mergeSort_(source, leftBorder, middle, buffer);
    mergeSort_(source, middle, rightBorder, buffer);

    merge(source + leftBorder, middle - leftBorder, source + middle, rightBorder - middle, buffer);

    if (memcmp(source + leftBorder, buffer, sizeSource * sizeof(int)) != 0)
        memcpy(source + leftBorder, buffer, sizeSource * sizeof(int));
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int *) malloc(n * sizeof(int));
    mergeSort_(a, 0, n, buffer);

    free(buffer);
}

// Сортировка Шелла >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void shellSort(int *const a, const size_t n) {
    for (register size_t s = n / 2; s > 0; s /= 2) {
        for (register int i = s; i < n; ++i) {
            for (register int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);
        }
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSort(int *const a, const size_t n) {
    register size_t i = 1;
    while (i < n) {
        if (a[i - 1] <= a[i])
            i++;
        else {
            swap(&a[i - 1], &a[i]);
            i = i > 1 ? i - 1 : i;
        }
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья (оптимизация) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSortOptimaze(int *const a, const size_t n) {
    register size_t i = 1;
    register size_t j = 2;
    while (i < n) {
        if (a[i - 1] <= a[i]) {
            i = j;
            j++;
        } else {
            swap(&a[i - 1], &a[i]);
            i--;
            if (!i) {
                i = j;
                j++;
            }
        }
    }
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int compareInts(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}