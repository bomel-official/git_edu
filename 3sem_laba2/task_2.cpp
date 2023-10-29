#include <iostream>
#include <vector>


void PrintVectorUsingRangeBasedLoop(const std::vector<int>& vec) {
    for (const int& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void PrintVectorUsingIterator(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PrintVectorUsingIndexLoop(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}