#include <iostream>
#include <string>
#include <vector>

// Объявление класса Vehicle
class Vehicle {
public:
    // Конструкторы
    Vehicle() : brand("Unknown"), year(0) {}
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

    // Атрибуты
    std::string brand;
    int year;

    // Функции-члены
    void start() { std::cout << "Vehicle is starting...\n"; }
    void stop() { std::cout << "Vehicle is stopping...\n"; }
};

// Объявление класса Employee
class Employee {
public:
    // Конструкторы
    Employee() : name("Unknown"), age(0), vehicle(nullptr) {}
    Employee(const std::string& name, int age, Vehicle* vehicle) : name(name), age(age), vehicle(vehicle) {}

    // Атрибуты
    std::string name;
    int age;
    Vehicle* vehicle;

    // Функции-члены
    void work() { std::cout << "Employee is working...\n"; }
    void takeVacation() { std::cout << "Employee is on vacation...\n"; }
};

// Объявление класса Company
class Company {
public:
    // Конструкторы
    Company() : companyName("Unknown") {}
    Company(const std::string& companyName) : companyName(companyName) {}

    // Атрибуты
    std::string companyName;
    std::vector<Employee*> employees;  // Список сотрудников
    std::vector<Vehicle*> vehicles;    // Список транспортных средств

    // Функции-члены
    void organizeEvent() { std::cout << "Company is organizing an event...\n"; }
    void conductMeeting() { std::cout << "Company is conducting a meeting...\n"; }
};

// Объявление класса Vehicle с производными классами Truck и Car
class Truck : public Vehicle {
public:
    // Конструкторы
    Truck() : capacity(0), cargo("None") {}
    Truck(const std::string& brand, int year, int capacity, const std::string& cargo)
        : Vehicle(brand, year), capacity(capacity), cargo(cargo) {}
    Truck(int capacity, const std::string& cargo) : capacity(capacity), cargo(cargo) {}

    // Дополнительные атрибуты
    int capacity;
    std::string cargo;

    // Дополнительные функции-члены
    void loadCargo() { std::cout << "Truck is loading cargo...\n"; }
    void unloadCargo() { std::cout << "Truck is unloading cargo...\n"; }
};

class Car : public Vehicle {
public:
    // Конструкторы
    Car() : passengers(0), transmission("Mechanic") {}
    Car(const std::string& brand, int year, int passengers, const std::string& transmission)
        : Vehicle(brand, year), passengers(passengers), transmission(transmission) {}
    Car(int passengers, const std::string& transmission) : passengers(passengers), transmission(transmission) {}

    // Дополнительные атрибуты
    int passengers;
    std::string transmission;

    // Дополнительные функции-члены
    void refuel() { std::cout << "Car is refueling...\n"; }
    void drive() { std::cout << "Car is driving...\n"; }
};

int main() {
    // Пример использования классов с добавленными связями
    Company company("ABC Corp");

    Employee employee1("John Doe", 30, new Car("Honda", 2023, 5, "Electric"));
    Employee employee2("Jane Smith", 28, new Truck("Ford", 2021, 5000, "Goods"));

    company.employees.push_back(&employee1);
    company.employees.push_back(&employee2);

    company.organizeEvent();

    return 0;
}