// int *ptr = (int*)malloc(sizeof(int)) - В C++ можно использовать int *ptr = new int; для выделения динамической памяти под целое число. Освобождение памяти в C++ производится с помощью delete ptr;.
// int *ptrArr = (int*)malloc(sizeof(int)*N) - В C++ можно использовать int *ptrArr = new int[N]; для выделения динамической памяти под массив из N целых чисел. Освобождение памяти в C++ производится с помощью delete[] ptrArr;.
// free(ptr) - В C++ можно использовать delete ptr; для освобождения памяти, выделенной с помощью new.
// free(ptrArr) - В C++ можно использовать delete[] ptrArr; для освобождения памяти, выделенной с помощью new[].

#include <iostream>

int main() {
    int numRows;
    
    // Запрашиваем у пользователя количество строк для пирамиды
    std::cout << "Enter number of rows in piramid: ";
    std::cin >> numRows;

    // Выделяем динамически двумерный массив для хранения пирамиды
    char** pyramid = new char*[numRows];

    // Заполняем пирамиду
    for (int i = 0; i < numRows; i++) {
        // Выделяем память для текущей строки
        pyramid[i] = new char[i * 2 + 1];

        // Заполняем строку символами '*'
        for (int j = 0; j < i * 2 + 1; j++) {
            pyramid[i][j] = '*';
        }
    }

    // Выводим пирамиду на экран
    for (int i = 0; i < numRows; i++) {
        // Добавляем отступ для формирования пирамиды
        for (int j = 0; j < numRows - i - 1; j++) {
            std::cout << " ";
        }

        // Выводим строку пирамиды
        for (int j = 0; j < i * 2 + 1; j++) {
            std::cout << pyramid[i][j];
        }

        std::cout << std::endl;
    }

    // Освобождаем выделенную память
    for (int i = 0; i < numRows; i++) {
        delete[] pyramid[i];
    }
    delete[] pyramid;

    return 0;
}