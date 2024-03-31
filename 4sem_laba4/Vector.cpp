#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    unsigned int size;

public:
    Vector(unsigned int size) : size(size) {
        data = new T[size];
    }

    ~Vector() {
        delete[] data;
    }

    // Метод для векторного произведения
    Vector<T> crossProduct(const Vector<T>& other) const {
        if (size != 3 || other.size != 3) {
            std::cerr << "Cross product is only defined for vectors of size 3" << std::endl;
            return Vector<T>(0);
        }
        
        Vector<T> result(3);
        result.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
        result.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
        result.data[2] = data[0] * other.data[1] - data[1] * other.data[0];
        return result;
    }

    // Метод для скалярного произведения
    T dotProduct(const Vector<T>& other) const {
        if (size != other.size) {
            std::cerr << "Vectors must have the same size" << std::endl;
            return T();
        }

        T result = T();
        for (unsigned int i = 0; i < size; ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }
};