#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 1000

void print(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void append(int **arr, int *size, int value) {
    *size += 1;
    *arr = realloc(*arr, *size * sizeof(int));
    (*arr)[*size - 1] = value;
}

void insert(int **arr, int *size, int index, int value) {
    *size += 1;
    *arr = realloc(*arr, *size * sizeof(int));
    for (int i = *size - 1; i > index; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[index] = value;
}

int main() {
    int size;
    printf("Input the size of the array: ");
    scanf("%d", &size);

    int *arr = (int*) malloc(size * sizeof(int));
    printf("Enter the values of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Initial array: ");
    print(arr, size);

    printf("Enter element to append: ");
    int value;
    scanf("%d", &value);
    append(&arr, &size, value);

    printf("Modified array: ");
    print(arr, size);

    tests(); // Выполнение тестов

    return 0;
}

int tests() {
    // Тесты для функции append:

    // Проверяем добавление одного элемента в пустой массив.
    int *arr = NULL;
    int size = 0;
    append(&arr, &size, 42);
    assert(size == 1 && arr[0] == 42);

    // Проверяем добавление нескольких элементов в массив.
    *arr = NULL;
    size = 0;
    append(&arr, &size, 1);
    append(&arr, &size, 2);
    append(&arr, &size, 3);
    assert(size == 3 && arr[0] == 1 && arr[1] == 2 && arr[2] == 3);

    // Проверяем добавление элементов в уже заполненный массив.
    *arr = calloc(3, sizeof(int));
    size = 3;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    append(&arr, &size, 4);
    append(&arr, &size, 5);
    assert(size == 5 && arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5);

    // Проверяем добавление элемента в массив, который уже занимает всю доступную память.
    *arr = calloc(10, sizeof(int));
    size = 10;
    for (int i = 0; i < size; i++) {
    arr[i] = i;
    }
    append(&arr, &size, 10);
    assert(size == 11 && arr[10] == 10);

    // Проверяем добавление элемента в массив, когда указатель на массив равен NULL.
    *arr = NULL;
    size = 0;
    append(&arr, &size, 42);
    assert(size == 1 && arr[0] == 42);

    // Тесты для функции insert:

    // Проверяем добавление элемента в пустой массив.
    *arr = NULL;
    size = 0;
    insert(&arr, &size, 0, 42);
    assert(size == 1 && arr[0] == 42);

    // Проверяем добавление элемента в начало массива.
    *arr = calloc(3, sizeof(int));
    size = 3;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    insert(&arr, &size, 0, 0);
    assert(size == 4 && arr[0] == 0 && arr[1] == 1 && arr[2] == 2 && arr[3] == 3);

    // Проверяем добавление элемента в конец массива.
    *arr = calloc(3, sizeof(int));
    size = 3;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    insert(&arr, &size, 3, 4);
    assert(size == 4 && arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4);
}