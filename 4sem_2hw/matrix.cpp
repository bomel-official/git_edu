#include "matrix.h"
#include <iostream>
#include <cstdlib>

Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    // Allocate memory for the matrix
    data = new int*[m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    // Deallocate memory
    for (unsigned int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int* Matrix::operator[](unsigned int index) {
    return data[index];
}

Matrix& Matrix::operator+=(const Matrix& other) {
    // Check if matrices have the same dimensions
    if (m != other.m || n != other.n) {
        std::cerr << "Error: Matrices must have the same dimensions for addition.\n";
        return *this;
    }

    // Perform element-wise addition
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] += other.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m, n);

    // Check if matrices have the same dimensions
    if (m != other.m || n != other.n) {
        std::cerr << "Error: Matrices must have the same dimensions for addition.\n";
        return result; // Return an empty matrix
    }

    // Perform element-wise addition
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    // Check if matrices have the same dimensions
    if (m != other.m || n != other.n) {
        std::cerr << "Error: Matrices must have the same dimensions for subtraction.\n";
        return *this;
    }

    // Perform element-wise subtraction
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m, n);

    // Check if matrices have the same dimensions
    if (m != other.m || n != other.n) {
        std::cerr << "Error: Matrices must have the same dimensions for subtraction.\n";
        return result; // Return an empty matrix
    }

    // Perform element-wise subtraction
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    // Check if matrices can be multiplied
    if (n != other.m) {
        std::cerr << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.\n";
        return Matrix(0, 0); // Return an empty matrix
    }

    Matrix result(m, other.n);

    // Perform matrix multiplication
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < other.n; ++j) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    // Check if matrices have the same dimensions
    if (m != other.m || n != other.n) {
        return false;
    }

    // Check element-wise equality
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

void Matrix::fillRandom() {
    // Fill with random values from 0 to 9
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = rand() % 10;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    // Output matrix as a table
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << matrix.data[i][j] << "\t";
        }
        os << std::endl;
    }

    return os;
}

int main() {
    Matrix matrix1(5, 5);
    Matrix matrix2(5, 5);

    matrix1.fillRandom();
    matrix2.fillRandom();

    std::cout << "matrix1:" << std::endl;
    std::cout << matrix1 << std::endl;
    std::cout << "matrix2:" << std::endl;
    std::cout << matrix2 << std::endl;

    std::cout << "matrix1 + matrix2:" << std::endl;
    std::cout << matrix1 + matrix2 << std::endl;

    std::cout << "matrix1 - matrix2:" << std::endl;
    std::cout << matrix1 - matrix2 << std::endl;

    std::cout << "matrix1 * matrix2:" << std::endl;
    std::cout << matrix1 * matrix2 << std::endl;

    std::cout << "matrix1 == matrix2:" << std::endl;
    std::cout << (matrix1 == matrix2) << std::endl;

    std::cout << "matrix1 != matrix2:" << std::endl;
    std::cout << (matrix1 != matrix2) << std::endl;


    return 0;
}