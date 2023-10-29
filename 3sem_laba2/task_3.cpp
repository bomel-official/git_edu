#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// Функция для вычисления среднего значения оценок
double CalculateMean(const std::vector<int>& grades) {
    if (grades.empty()) {
        return 0.0; // Вернуть 0, если вектор пуст
    }

    int sum = 0;
    for (const int& grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

// Функция для вычисления медианы оценок
double CalculateMedian(std::vector<int> grades) {
    if (grades.empty()) {
        return 0.0; // Вернуть 0, если вектор пуст
    }

    std::sort(grades.begin(), grades.end());
    int n = grades.size();

    if (n % 2 == 0) {
        // Если количество оценок четное, медиана - среднее двух средних значений
        return (grades[n / 2 - 1] + grades[n / 2]) / 2.0;
    } else {
        // Если количество оценок нечетное, медиана - среднее значение среднего элемента
        return static_cast<double>(grades[n / 2]);
    }
}

// Функция для вычисления моды оценок и вывода имен, соответствующих моде
void CalculateMode(const std::vector<int>& grades, const std::vector<std::string>& names) {
    if (grades.empty()) {
        std::cout << "No mode found as the list is empty." << std::endl;
        return;
    }

    std::unordered_map<int, int> gradeCount;
    int maxCount = 0;
    int mode = 0;
    for (int grade : grades) {
        gradeCount[grade]++;
        if (gradeCount[grade] > maxCount) {
            maxCount = gradeCount[grade];
            mode = grade;
        }
    }

    std::cout << "Overall mode of the grades: " << mode << std::endl;

    std::cout << "Names of students with overall mode grade: ";
    for (int i = 0; i < grades.size(); i++) {
        if (mode == grades[i]) {
            std::cout << names[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> names = {"Ivan", "Maria", "Peter", "Olga", "Alex", "Natalia", "Sergey", "Elena", "Dmitry", "Anna"};
    std::vector<int> grades = {85, 90, 78, 65, 92, 76, 85, 72, 95, 80};

    // Вызов функций для вычисления и вывода среднего значения, медианы и моды
    double mean = CalculateMean(grades);
    double median = CalculateMedian(grades);
    CalculateMode(grades, names);

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;

    return 0;
}