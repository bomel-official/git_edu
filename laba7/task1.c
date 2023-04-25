// Ответы на вопросы:
// 1. Количество итераций для каждого из алгоритмов может быть разным для одного и того же словаря,
// в зависимости от начального порядка слов в массиве. В общем случае расчёской сортировке
// требуется меньше итераций, чем сортировке выбором и пузырьковой сортировке,
// так как она более эффективна для случаев, когда массив частично отсортирован.
// Однако, в худшем случае, все три алгоритма имеют асимптотическую сложность O(n^2),
// поэтому при больших размерах массивов они могут быть очень медленными.

// 2. Время выполнения каждого алгоритма может различаться в зависимости от
// характеристик компьютера, его загрузки и размера массива. Однако, если условия
// выполнения алгоритмов одинаковы (т.е. массивы имеют одинаковый размер и содержат
// одинаковые элементы), то время выполнения должно быть сопоставимым.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20


void selection_sort(char words[][MAX_WORD_LENGTH], int n);
void bubble_sort(char words[][MAX_WORD_LENGTH], int n);
void comb_sort(char words[][MAX_WORD_LENGTH], int n);
void print_words(char words[][MAX_WORD_LENGTH], int n);

int main()
{
	setlocale(LC_ALL, "Rus");

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int choice, iterations, i = 0;

    printf("Enter %d words:\n", MAX_WORDS);
    for (i = 0; i < MAX_WORDS; i++) {
        scanf("%s", words[i]);
    }

    printf("\nSelect sorting algorithm:\n");
    printf("1. Selection sorting\n");
    printf("2. Bubble sorting\n");
    printf("3. Comb sorting\n");
    printf("4. Do all these algorithms\n");
    printf("Your choise: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nSelection sorting:\n");
        selection_sort(words, MAX_WORDS);
        break;
    case 2:
        printf("\nBubble sorting:\n");
        bubble_sort(words, MAX_WORDS);
        break;
    case 3:
        printf("\nComb sorting:\n");
        comb_sort(words, MAX_WORDS);
        break;
    case 4:
        printf("\nSelection sorting:\n");
        selection_sort(words, MAX_WORDS);
        printf("\nBubble sorting:\n");
        bubble_sort(words, MAX_WORDS);
        printf("\nComb sorting:\n");
        comb_sort(words, MAX_WORDS);
        break;
    default:
        printf("\nIncorrect choise\n");
        return 1;
    }

    printf("\nSorted words:\n");
    print_words(words, MAX_WORDS);

    return 0;
}

void print_words(char words[][MAX_WORD_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void selection_sort(char words[][MAX_WORD_LENGTH], int n) {
    int i, j, min_idx;
    int count = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[j], words[min_idx]) < 0) {
                min_idx = j;
            }
            count++;
        }
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[min_idx]);
        strcpy(words[min_idx], words[i]);
        strcpy(words[i], temp);
    }
    printf("Selection Sort:\n");
    print_words(words, n);
    printf("Total iterations: %d\n", count);
}

void bubble_sort(char words[][MAX_WORD_LENGTH], int n) {
    int i, j;
    int count = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
            count++;
        }
    }
    printf("Bubble Sort:\n");
    print_words(words, n);
    printf("Total iterations: %d\n", count);
}

void comb_sort(char words[][MAX_WORD_LENGTH], int n) {
    int gap = n;
    float shrink = 1.3;
    int swapped = 1;
    int i;
    int count = 0;
    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap = (int)(gap / shrink);
        }
        swapped = 0;
        for (i = 0; i + gap < n; i++) {
            if (strcmp(words[i], words[i + gap]) > 0) {
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, words[i]);
                strcpy(words[i], words[i + gap]);
                strcpy(words[i + gap], temp);
                swapped = 1;
            }
            count++;
        }
    }
    printf("Comb Sort:\n");
    print_words(words, n);
    printf("Total iterations: %d\n", count);
}