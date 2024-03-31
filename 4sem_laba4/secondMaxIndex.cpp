#include <iostream>

template<typename T>
int findSecondMaxIndex(T* arr, int size) {
    if (size < 2) {
        std::cerr << "Error: Array size must be at least 2." << std::endl;
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    for (int i = 0; i < size; ++i) {
        if (i != maxIndex && arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }

    return secondMaxIndex;
}

int main() {
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int intArr[] = {1, 2, 3, 4, 5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};

    int floatIndex = findSecondMaxIndex(floatArr, 5);
    std::cout << "Index of second maximum element in floatArr: " << floatIndex << std::endl;

    int doubleIndex = findSecondMaxIndex(doubleArr, 5);
    std::cout << "Index of second maximum element in doubleArr: " << doubleIndex << std::endl;

    int intIndex = findSecondMaxIndex(intArr, 5);
    std::cout << "Index of second maximum element in intArr: " << intIndex << std::endl;

    int charIndex = findSecondMaxIndex(charArr, 5);
    std::cout << "Index of second maximum element in charArr: " << charIndex << std::endl;

    return 0;
}