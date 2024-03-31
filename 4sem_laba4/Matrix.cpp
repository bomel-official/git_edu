#include <iostream>
#include <cstdlib> // Для функции rand
#include <ctime>   // Для функции time

template<typename T>
class Matrix {
private:
    T** data;
    unsigned int rows;
    unsigned int cols;

public:
    // Конструктор с указанием количества строк и столбцов
    Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (unsigned int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    // Деструктор
    ~Matrix() {
        for (unsigned int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Метод для заполнения матрицы случайными значениями
    void fillRandom() {
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                data[i][j] = static_cast<T>(rand() % 100); // Генерация случайного числа от 0 до 99
            }
        }
    }

    // Перегрузка оператора сложения для матриц
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions mismatch for addition" << std::endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора вычитания для матриц
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions mismatch for subtraction" << std::endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора умножения для матриц
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Matrix dimensions mismatch for multiplication" << std::endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Перегрузка оператора сравнения на равенство для матриц
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Перегрузка оператора сравнения на неравенство для матриц
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    // Вспомогательная функция для вывода матрицы
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.rows; ++i) {
            for (unsigned int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    // Создание матрицы int размером 2x3
    Matrix<int> matrix1(3, 3);
    matrix1.fillRandom(); // Заполнение случайными значениями
    std::cout << "Matrix 1:" << std::endl << matrix1 << std::endl;

    // Создание матрицы int размером 2x3
    Matrix<int> matrix2(3, 3);
    matrix2.fillRandom(); // Заполнение случайными значениями
    std::cout << "Matrix 2:" << std::endl << matrix2 << std::endl;

    // Сложение матриц
    Matrix<int> sum = matrix1 + matrix2;
    std::cout << "Sum of matrices:" << std::endl << sum << std::endl;

    // Вычитание матриц
    Matrix<int> difference = matrix1 - matrix2;
    std::cout << "Difference of matrices:" << std::endl << difference << std::endl;

    // Умножение матриц
    Matrix<int> product = matrix1 * matrix2;
    std::cout << "Product of matrices:" << std::endl << product << std::endl;

    // Проверка на равенство матриц
    if (matrix1 == matrix2) {
        std::cout << "Matrices are equal." << std::endl;
    } else {
        std::cout << "Matrices are not equal." << std::endl;
    }

    return 0;
}