#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class
class LibraryItem {
protected:
    string title;
    int itemID;
    bool isCheckedOut;

public:
    LibraryItem(string title, int itemID) : title(title), itemID(itemID), isCheckedOut(false) {}

    virtual void displayDetails() const {
        cout << "Title: " << title << ", ID: " << itemID;
    }

    void checkOutItem() {
        isCheckedOut = true;
        cout << "\nChecked out: " << title << endl;
    }

    void checkInItem() {
        isCheckedOut = false;
        cout << "\nChecked in: " << title << endl;
    }

    virtual ~LibraryItem() {}
};

// Derived class for Book
class Book : public LibraryItem {
private:
    string author;
    string ISBN;

public:
    Book(string title, int itemID, string author, string ISBN)
        : LibraryItem(title, itemID), author(author), ISBN(ISBN) {}

    void displayDetails() const override {
        LibraryItem::displayDetails();
        cout << ", Author: " << author << ", ISBN: " << ISBN;
    }
};

// Derived class for Journal
class Journal : public LibraryItem {
private:
    int volume;
    int issue;
    string publisher;

public:
    Journal(string title, int itemID, int volume, int issue, string publisher)
        : LibraryItem(title, itemID), volume(volume), issue(issue), publisher(publisher) {}

    void displayDetails() const override {
        LibraryItem::displayDetails();
        cout << ", Volume: " << volume << ", Issue: " << issue << ", Publisher: " << publisher;
    }
};

// Derived class for DVD
class DVD : public LibraryItem {
private:
    int runtime; // In minutes
    string genre;

public:
    DVD(string title, int itemID, int runtime, string genre)
        : LibraryItem(title, itemID), runtime(runtime), genre(genre) {}

    void displayDetails() const override {
        LibraryItem::displayDetails();
        cout << ", Runtime: " << runtime << " minutes, Genre: " << genre;
    }
};

int main() {
    vector<LibraryItem*> items;

    // Adding different types of library items to the collection
    items.push_back(new Book("The Great Gatsby", 1, "F. Scott Fitzgerald", "123456789"));
    items.push_back(new Journal("Nature", 2, 500, 30, "Nature Publishing"));
    items.push_back(new DVD("Inception", 3, 148, "Science Fiction"));

    // Demonstrating polymorphism and interaction with items
    for (auto& item : items) {
        item->displayDetails();
        item->checkOutItem(); // Simulate checking out an item
        cout << endl;
    }

    // Demonstrating checking in items
    for (auto& item : items) {
        item->checkInItem();
    }

    // Cleaning up dynamically allocated memory
    for (auto& item : items) {
        delete item;
    }
    items.clear();

    return 0;
}