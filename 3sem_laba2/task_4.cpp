#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// Функция для вычисления моды оценок и вывода имен, соответствующих моде
void CalculateMode(const std::vector<int>& grades, const std::vector<std::string>& names) {
    if (grades.empty()) {
        std::cout << "No mode found as the list is empty." << std::endl;
        return;
    }

    std::unordered_map<int, int> gradeCount;
    int maxCount = 0;
    for (int grade : grades) {
        gradeCount[grade]++;
        if (gradeCount[grade] > maxCount) {
            maxCount = gradeCount[grade];
        }
    }
    std::vector<int> modes;
    for(auto kv : gradeCount) {
        if (gradeCount[kv.first] == maxCount) {
            modes.push_back(kv.first);
        }
    } 

    if (modes.empty()) {
        std::cout << "No mode found." << std::endl;
    } else {
        std::cout << "Overall mode(s) of the grades: ";
        for (int mode : modes) {
            std::cout << mode << " ";
        }
        std::cout << std::endl;

        std::cout << "Names of students with overall mode grade(s): ";
        for (int i = 0; i < grades.size(); i++) {
            if (std::find(modes.begin(), modes.end(), grades[i]) != modes.end()) {
                std::cout << names[i] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> names = {"Ivan", "Maria", "Peter", "Olga", "Alex", "Natalia", "Sergey", "Elena", "Dmitry", "Anna"};
    std::vector<int> grades = {85, 90, 78, 65, 92, 76, 85, 72, 90, 80};

    // Вызов функций для вычисления и вывода среднего значения, медианы и моды
    CalculateMode(grades, names);

    return 0;
}