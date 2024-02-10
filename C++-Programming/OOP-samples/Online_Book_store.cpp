#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
protected:
    string title;
    double price;

public:
    Product(string title, double price) : title(title), price(price) {}

    virtual void display() const {
        cout << "Product: " << title << ", Price: $" << price << endl;
    }

    double getPrice() const {
        return price;
    }

    virtual ~Product() {}
};

class Book : public Product {
    string author;
public:
    Book(string title, string author, double price) : Product(title, price), author(author) {}

    void display() const override {
        cout << "Book: ";
        Product::display();
        cout << "Author: " << author << endl;
    }
};

class Journal : public Product {
    int issueNumber;
public:
    Journal(string title, int issueNumber, double price) : Product(title, price), issueNumber(issueNumber) {}

    void display() const override {
        cout << "Journal: ";
        Product::display();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Magazine : public Product {
    string genre;
public:
    Magazine(string title, string genre, double price) : Product(title, price), genre(genre) {}

    void display() const override {
        cout << "Magazine: ";
        Product::display();
        cout << "Genre: " << genre << endl;
    }
};

class Cart {
    vector<Product*> products;

public:
    ~Cart() {
        for (Product* product : products) {
            delete product;
        }
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void displayCart() const {
        cout << "Cart Items: " << endl;
        for (const Product* product : products) {
            product->display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const Product* product : products) {
            total += product->getPrice();
        }
        return total;
    }
};

int main() {
    Cart cart;

    cart.addProduct(new Book("The C++ Programming Language", "Bjarne Stroustrup", 54.99));
    cart.addProduct(new Journal("Journal of Computer Science", 10, 19.99));
    cart.addProduct(new Magazine("National Geographic", "Nature", 6.99));

    cart.displayCart();
    cout << "Total Cart Price: $" << cart.calculateTotal() << endl;

    // The Cart destructor is automatically called at the end of main(), cleaning up the products
    return 0;
}