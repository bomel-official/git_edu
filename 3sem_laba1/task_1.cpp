// strlen - В C++ можно использовать метод size() для объектов типа string.
// strcpy - В C++ можно использовать метод assign() для копирования строк.
// strcmp - В C++ можно использовать метод compare() для сравнения строк.
// strcat - В C++ можно использовать оператор + для конкатенации строк.
// someString[index] - В C++ можно использовать оператор [] для получения символа по индексу.
// push_back - В C++ можно использовать метод push_back() для добавления символа в конец строки.
// pop_back - В C++ можно использовать метод pop_back() для удаления последнего символа из строки.

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    // Удаление пробелов и пунктуационных знаков
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    input.erase(std::remove_if(input.begin(), input.end(), ::ispunct), input.end());

    // Сортировка букв в строке
    std::sort(input.begin(), input.end());

    std::cout << "Sorted string: " << input << std::endl;

    return 0;
}