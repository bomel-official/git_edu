#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getInput();
bool testInput(char*);
int strToInt(char*);
void printInt(int);

int main() {
    char* inputStr = getInput();
    if (testInput(inputStr)) {
        int num = strToInt(inputStr);
        printInt(num);
    } else {
        printf("You cannot convert this string to integer\n");
    }
    free(inputStr);
    return 0;
}


char* getInput() {
    char* input = malloc(sizeof(char) * 100);
    printf("Input string: ");
    scanf("%s", input);
    return input;
}

bool testInput(char* str) {
    int num;
    if (sscanf(str, "%d", &num) == 1) {
        return true;
    } else {
        return false;
    }
}

int strToInt(char* str) {
    return atoi(str);
}

void printInt(int num) {
    printf("%d\n", num);
}