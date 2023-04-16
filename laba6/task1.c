#include <stdio.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

#define MAX_SIZE 100

int max_consecutive(char arr[], char ch, int n);

int main() {
	setlocale(LC_ALL, "Rus");
    
    char arr[MAX_SIZE];
    int n;
    char ch;

    printf("Input symbol: ");
    scanf("%c", &ch);

    printf("Input array size (not more than %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Input array elements: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    int max_len = max_consecutive(arr, ch, n);
    printf("Amswer for '%c': %d\n", ch, max_len);

    return 0;
}

int max_consecutive(char arr[], char ch, int n) {
    int max_len = 0;
    int len = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == ch) {
            len++;
        } else {
            if (len > max_len) {
                max_len = len;
            }
            len = 0;
        }
    }

    if (len > max_len) {
        max_len = len;
    }

    return max_len;
}