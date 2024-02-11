#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StockItem {
protected:
    string name;
    int quantity;
    double price;

public:
    StockItem(string name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}

    virtual void display() const {
        cout << "Item: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

    virtual void restock(int qty) {
        quantity += qty;
        cout << name << " restocked. New quantity: " << quantity << endl;
    }

    virtual void dispatch(int qty) {
        if (qty > quantity) {
            cout << "Not enough stock for " << name << endl;
            return;
        }
        quantity -= qty;
        cout << qty << " unit(s) of " << name << " dispatched. Remaining stock: " << quantity << endl;
    }

    const string& getName() const {
        return name;
    }

    virtual ~StockItem() {}
};

class PerishableGoods : public StockItem {
    string expiryDate;

public:
    PerishableGoods(string name, int quantity, double price, string expiryDate)
        : StockItem(name, quantity, price), expiryDate(expiryDate) {}

    void display() const override {
        StockItem::display();
        cout << "Expiry Date: " << expiryDate << endl;
    }
};

class Electronics : public StockItem {
    int warrantyMonths;

public:
    Electronics(string name, int quantity, double price, int warrantyMonths)
        : StockItem(name, quantity, price), warrantyMonths(warrantyMonths) {}

    void display() const override {
        StockItem::display();
        cout << "Warranty: " << warrantyMonths << " months" << endl;
    }
};

class Clothing : public StockItem {
    string size;

public:
    Clothing(string name, int quantity, double price, string size)
        : StockItem(name, quantity, price), size(size) {}

    void display() const override {
        StockItem::display();
        cout << "Size: " << size << endl;
    }
};

class Warehouse {
private:
    vector<StockItem*> stockItems;

public:
    ~Warehouse() {
        for (StockItem* item : stockItems) {
            delete item;
        }
    }

    void addStockItem(StockItem* item) {
        stockItems.push_back(item);
    }

    void restockItem(const string& itemName, int qty) {
        for (StockItem* item : stockItems) {
            if (item->getName() == itemName) {
                item->restock(qty);
                return;
            }
        }
        cout << "Item " << itemName << " not found for restocking." << endl;
    }

    void dispatchItem(const string& itemName, int qty) {
        for (StockItem* item : stockItems) {
            if (item->getName() == itemName) {
                item->dispatch(qty);
                return;
            }
        }
        cout << "Item " << itemName << " not found for dispatch." << endl;
    }

    void displayStock() const {
        cout << "Warehouse Stock:" << endl;
        for (const StockItem* item : stockItems) {
            item->display();
        }
    }
};

int main() {
    Warehouse warehouse;

    warehouse.addStockItem(new PerishableGoods("Milk", 100, 2.99, "2023-10-01"));
    warehouse.addStockItem(new Electronics("Smartphone", 50, 699.99, 24));
    warehouse.addStockItem(new Clothing("Jeans", 150, 39.99, "M"));

    cout << "Initial Warehouse Stock:" << endl;
    warehouse.displayStock();

    cout << "\nStock Management Operations:" << endl;
    warehouse.restockItem("Milk", 50); // Restock Milk
    warehouse.dispatchItem("Smartphone", 10); // Dispatch Smartphones
    warehouse.dispatchItem("Jeans", 5); // Dispatch Jeans

    cout << "\nUpdated Warehouse Stock:" << endl;
    warehouse.displayStock();

    return 0;
}