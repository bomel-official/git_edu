#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For generating random numbers
#include <ctime>   // For initializing the random number generator

// Function to initialize the grades vector with random values
void InitRandomGrades(std::vector<int>& grades, int numStudents) {
    srand(static_cast<unsigned>(time(0))); // Initialize the random number generator
    for (int i = 0; i < numStudents; i++) {
        int grade = rand() % 101; // Generate a random number from 0 to 100
        grades.push_back(grade);
    }
}

void PrintVectorUsingIndexLoop(const std::vector<std::string>& names, const std::vector<int> grades, const int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        std::cout << names[i] << ": " << grades[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> names;
    std::vector<int> grades;

    int choice;
    int numStudents;

    std::cout << "Choose the initialization method:" << std::endl;
    std::cout << "1. Demonstration analysis with default input values" << std::endl;
    std::cout << "2. Analysis with random input values" << std::endl;
    std::cout << "3. Analysis with user-provided input values" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        // Demonstration initialization
        names = {"Ivan", "Maria", "Peter", "Olga", "Alex", "Natalia", "Sergey", "Elena", "Dmitry", "Anna"};
        grades = {85, 90, 78, 65, 92, 76, 88, 72, 95, 80};
    } else if (choice == 2) {
        // Initialization with random input values
        std::cout << "Enter the number of students: ";
        std::cin >> numStudents;
        InitRandomGrades(grades, numStudents);
    } else if (choice == 3) {
        // User-provided initialization
        std::cout << "Enter the number of students: ";
        std::cin >> numStudents;
        std::cin.ignore(); // Clear the buffer after entering the number
        for (int i = 0; i < numStudents; i++) {
            std::string name;
            int grade;
            std::cout << "Enter the name of student " << i + 1 << ": ";
            std::cin.ignore(); // Clear the buffer before entering the name
            std::getline(std::cin, name);
            std::cout << "Enter the grade for student " << name << ": ";
            std::cin >> grade;
            names.push_back(name);
            grades.push_back(grade);
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    // Perform grade analysis using the names and grades vectors
    // You can add analysis code here if necessary

    // Display the names and grades of the students
    std::cout << "Names of students and their grades:" << std::endl;
    PrintVectorUsingIndexLoop(names, grades, numStudents);

    return 0;
}