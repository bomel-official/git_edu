#include <iostream>

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() : cashOnHand(500) {}

    cashRegister(int initialAmount) : cashOnHand(initialAmount) {}

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int itemCost;

public:
    dispenserType() : numberOfItems(50), itemCost(50) {}

    dispenserType(int items, int cost) : numberOfItems(items), itemCost(cost) {}

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return itemCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
    }
};

void showSelection() {
    std::cout << "1. Candies\n2. Chips\n3. Gum\n4. Cookies\n";
}

void proceedPayment(dispenserType& product, cashRegister& registerCash) {
    if (product.getNoOfItems() > 0) {
        std::cout << "Product price: " << product.getCost() << std::endl;

        int amount;
        std::cout << "Put money: ";
        std::cin >> amount;

        if (amount >= product.getCost()) {
            product.makeSale();
            registerCash.acceptAmount(product.getCost());
            std::cout << "Product successfully sold. Thanks for purchase!\n";
        } else {
            std::cout << "Not enough money. Please, put a needed amount.\n";
        }
    } else {
        std::cout << "Suddenly product is out of stock.\n";
    }
}

void sellProduct(cashRegister& registerCash) {
    int choice;

    std::cout << "Select product (1-4): ";
    std::cin >> choice;

    int numberOfItems;
    int price;


    switch (choice) {
        case 1: // Candies
            numberOfItems = 0;
            price = 150;
            break;
        case 2: // Chips
            numberOfItems = 1;
            price = 80;
            break;
        case 3: // Gum
            numberOfItems = 5;
            price = 30;
            break;
        case 4: // Cookies
            numberOfItems = 50;
            price = 10;
            break;

        default:
            std::cout << "Wrong product selection.\n";
            return;
            break;
    }

    dispenserType dispenser(numberOfItems, price);
    proceedPayment(dispenser, registerCash);
}

int main() {
    cashRegister registerCash;

    showSelection();
    sellProduct(registerCash);

    return 0;
}