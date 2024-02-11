#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class LibraryItem {
protected:
    string title;
    string id;

public:
    LibraryItem(string title, string id) : title(title), id(id) {}

    virtual void display() const {
        cout << "Item: " << title << ", ID: " << id << endl;
    }

    const string& getId() const {
        return id;
    }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
    string author;

public:
    Book(string title, string id, string author)
        : LibraryItem(title, id), author(author) {}

    void display() const override {
        cout << "Book: ";
        LibraryItem::display();
        cout << "Author: " << author << endl;
    }
};

class Magazine : public LibraryItem {
    int issueNumber;

public:
    Magazine(string title, string id, int issueNumber)
        : LibraryItem(title, id), issueNumber(issueNumber) {}

    void display() const override {
        cout << "Magazine: ";
        LibraryItem::display();
        cout << "Issue: " << issueNumber << endl;
    }
};

class DVD : public LibraryItem {
    int duration; // Duration in minutes

public:
    DVD(string title, string id, int duration)
        : LibraryItem(title, id), duration(duration) {}

    void display() const override {
        cout << "DVD: ";
        LibraryItem::display();
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

class Patron {
    string name;
    map<string, LibraryItem*> borrowedItems;

public:
    Patron(string name) : name(name) {}

    void borrowItem(LibraryItem* item) {
        borrowedItems[item->getId()] = item;
    }

    void returnItem(const string& itemId) {
        borrowedItems.erase(itemId);
    }

    void displayBorrowedItems() const {
        cout << "Patron: " << name << " has borrowed:" << endl;
        for (const auto& pair : borrowedItems) {
            pair.second->display();
        }
    }
};

class Library {
    vector<LibraryItem*> items;
    vector<Patron*> patrons;

public:
    ~Library() {
        for (auto* item : items) {
            delete item;
        }
        for (auto* patron : patrons) {
            delete patron;
        }
    }

    void addItem(LibraryItem* item) {
        items.push_back(item);
    }

    void addPatron(Patron* patron) {
        patrons.push_back(patron);
    }

    void displayItems() const {
        cout << "Library Items:" << endl;
        for (const auto* item : items) {
            item->display();
        }
    }

    void displayPatrons() const {
        cout << "Library Patrons:" << endl;
        for (const auto* patron : patrons) {
            patron->displayBorrowedItems();
        }
    }
};

int main() {
    Library library;

    // Creating library items
    LibraryItem* book1 = new Book("The Great Gatsby", "B001", "F. Scott Fitzgerald");
    LibraryItem* magazine1 = new Magazine("National Geographic", "M001", 202);
    LibraryItem* dvd1 = new DVD("Inception", "D001", 148);

    // Adding items to the library
    library.addItem(book1);
    library.addItem(magazine1);
    library.addItem(dvd1);

    // Creating patrons
    Patron* patron1 = new Patron("John Doe");
    Patron* patron2 = new Patron("Jane Smith");

    // Adding patrons to the library
    library.addPatron(patron1);
    library.addPatron(patron2);

    // Borrowing items
    patron1->borrowItem(book1);
    patron2->borrowItem(magazine1);
    patron2->borrowItem(dvd1);

    // Displaying library information
    library.displayItems();
    library.displayPatrons();

    // The Library destructor automatically cleans up the dynamically allocated LibraryItem and Patron objects
    return 0;
}