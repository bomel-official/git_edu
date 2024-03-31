#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // Для использования _getch()

class Point2D {
private:
    int x;
    int y;

public:
    Point2D(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

class Arena; // Предварительное объявление класса Arena

class Character {
protected:
    Point2D position;

public:
    Character(int x, int y) : position(x, y) {}

    virtual void move() = 0;

    Point2D getPosition() const { return position; }
};

class Prey : public Character {
public:
    Prey(int x, int y) : Character(x, y) {}

    virtual void move() override;
};

class Predator : public Character {
public:
    Predator(int x, int y) : Character(x, y) {}

    virtual void move() override;
};

class Arena {
private:
    int width;
    int height;
    Prey prey;
    Predator predator;

    static Arena* instance; // Единственный экземпляр Arena

    Arena(int width, int height) : width(width), height(height), prey(width / 2, height / 2), predator(0, 0) {}

public:
    static Arena& getInstance() {
        if (!instance) {
            instance = new Arena(30, 30); // Размеры поля 10x10
        }
        return *instance;
    }

    Point2D getPreyPosition() const { return prey.getPosition(); }
    Point2D getPredatorPosition() const { return predator.getPosition(); }

    void startGame();
};

Arena* Arena::instance = nullptr;

void Prey::move() {
    int dx = 0, dy = 0;
    char key = _getch();
    switch (key) {
        case 'w':
            dy = -1;
            break;
        case 's':
            dy = 1;
            break;
        case 'a':
            dx = -1;
            break;
        case 'd':
            dx = 1;
            break;
        case 'q': // Движение вверх и влево (диагонально)
            dy = -1;
            dx = -1;
            break;
        case 'e': // Движение вверх и вправо (диагонально)
            dy = -1;
            dx = 1;
            break;
        case 'z': // Движение вниз и влево (диагонально)
            dy = 1;
            dx = -1;
            break;
        case 'c': // Движение вниз и вправо (диагонально)
            dy = 1;
            dx = 1;
            break;
        default:
            break;
    }

    // Обновляем позицию жертвы
    position = Point2D(position.getX() + dx, position.getY() + dy);
}

void Predator::move() {
    // Получаем текущие позиции хищника и жертвы
    int predX = position.getX();
    int predY = position.getY();
    int preyX = Arena::getInstance().getPreyPosition().getX();
    int preyY = Arena::getInstance().getPreyPosition().getY();

    // Вычисляем направление движения к жертве
    int dx = abs(predX - preyX);
    int dy = abs(predY - preyY);
    
    // Выбираем случайное расстояние от 1 до 3
    int distance = rand() % 3 + 1;
    
    if (dx > dy) {
        // Обновляем позицию хищника
        int moveDirection = (predX < preyX) ? 1 : ((predX > preyX) ? -1 : 0);
        position = Point2D(predX + moveDirection * distance, predY);
    } else {
        // Обновляем позицию хищника
        int moveDirection = (predY < preyY) ? 1 : ((predY > preyY) ? -1 : 0);
        position = Point2D(predX, predY + moveDirection * distance);
    }
}

void Arena::startGame() {
    srand(time(nullptr));

    int movesLeft = 100; // Заданное количество шагов

    while (movesLeft > 0) {
        // Вывод игрового поля
        system("cls"); // Очищаем консоль
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == prey.getPosition().getX() && y == prey.getPosition().getY()) std::cout << "P ";
                else if (x == predator.getPosition().getX() && y == predator.getPosition().getY()) std::cout << "H ";
                else std::cout << ". ";
            }
            std::cout << std::endl;
        }
        std::cout << "Moves left: " << movesLeft << std::endl;

        // Ход персонажей
        prey.move();
        predator.move();

        // Проверка условий завершения игры
        if (abs(prey.getPosition().getX() - predator.getPosition().getX()) <= 1 &&
            abs(prey.getPosition().getY() - predator.getPosition().getY()) <= 1) {
            std::cout << "Predator caught the prey!" << std::endl;
            break;
        }

        // Ждем нажатия клавиши перед следующим ходом
        _getch();

        --movesLeft;
    }

    if (movesLeft == 0) std::cout << "Game over! Moves limit reached." << std::endl;
}

int main() {
    Arena& arena = Arena::getInstance();
    arena.startGame();

    return 0;
}
