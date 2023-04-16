#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Функция поиска элемента в двумерном массиве
void searchElement(int arr[][COLS], int element) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] == element) {
                printf("Element %d found in row %d and column %d\n", element, i+1, j+1);
                return;
            }
        }
    }
    printf("Element %d is not found\n", element);
}

int main() {
    int arr[ROWS][COLS];
    int i, j, element;

    // Заполнение массива рандомными числами
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    // Вывод списка всех элементов массива
    printf("Available elements:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Спрашиваем у пользователя, какой элемент он ищет
    printf("Input element for searching: ");
    scanf("%d", &element);

    // Поиск элемента в массиве
    searchElement(arr, element);

    return 0;
}