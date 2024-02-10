#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 10; // Maximum number of items in an order

// Abstract class for order items
class OrderItem {
public:
    virtual double getPrice() const = 0;
    virtual string getName() const = 0;
    virtual void display() const = 0;
    virtual ~OrderItem() {}
};

// Derived class for food items
class FoodItem : public OrderItem {
    string name;
    double price;
public:
    FoodItem(string name, double price) : name(name), price(price) {}
    
    double getPrice() const override {
        return price;
    }

    string getName() const override {
        return name;
    }

    void display() const override {
        cout << "Food: " << name << ", Price: $" << price << endl;
    }
};

// Derived class for beverage items
class BeverageItem : public OrderItem {
    string name;
    double price;
    bool isAlcoholic;
public:
    BeverageItem(string name, double price, bool isAlcoholic) 
        : name(name), price(price), isAlcoholic(isAlcoholic) {}
    
    double getPrice() const override {
        return price;
    }

    string getName() const override {
        return name;
    }

    void display() const override {
        cout << "Beverage: " << name << ", Price: $" << price << (isAlcoholic ? ", Alcoholic" : ", Non-Alcoholic") << endl;
    }
};

// Class for managing orders
class Order {
    OrderItem* items[MAX_ITEMS]; // Static array of pointers to OrderItem
    int itemCount;

public:
    Order() : itemCount(0) {}

    ~Order() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }

    bool addItem(OrderItem* item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = item;
            return true;
        }
        return false;
    }

    double calculateTotal() const {
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->getPrice();
        }
        return total;
    }

    void displayOrder() const {
        for (int i = 0; i < itemCount; ++i) {
            items[i]->display();
        }
    }
};

// Class for managing tables
class Table {
    int number;
    Order* currentOrder; // Pointer to dynamically manage the Order

public:
    Table(int number) : number(number), currentOrder(nullptr) {}

    ~Table() {
        delete currentOrder; // Clean up the current order
    }

    void placeOrder(Order* order) {
        delete currentOrder; // Ensure any existing order is properly deleted before assigning a new one
        currentOrder = order; // Assign the new order to the table
    }

    void printBill() const {
        if (currentOrder != nullptr) {
            cout << "Bill for Table " << number << ": $" << currentOrder->calculateTotal() << endl;
            currentOrder->displayOrder();
        } else {
            cout << "No active order for Table " << number << endl;
        }
    }
};

int main() {
    Order* order = new Order();
    order->addItem(new FoodItem("Pizza", 9.99));
    order->addItem(new BeverageItem("Beer", 3.99, true));
    
    Table table1(1);
    table1.placeOrder(order); // Pass the pointer to the new order
    
    table1.printBill();
    
    // Since Table is responsible for deleting its currentOrder, there's no need to delete the order here
    //delete table1;
    return 0;
}