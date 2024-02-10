#include <iostream>
#include <string>

using namespace std;

class ILoanStrategy {
public:
    virtual void executeLoan() const = 0;
    virtual ~ILoanStrategy() = default;
};

class ShortTermLoan : public ILoanStrategy {
public:
    void executeLoan() const override {
        cout << "Item loaned for 7 days." << endl;
    }
};

class LongTermLoan : public ILoanStrategy {
public:
    void executeLoan() const override {
        cout << "Item loaned for 30 days." << endl;
    }
};

class Item {
protected:
    string title;
    unsigned int id;

public:
    Item(const string& title, unsigned int id) : title(title), id(id) {}
    virtual void display() const = 0;
    virtual ~Item() = default;
};

class Book : public Item {
private:
    string author;

public:
    Book(const string& title, unsigned int id, const string& author)
        : Item(title, id), author(author) {}

    void display() const override {
        cout << "Book - Title: " << title << ", Author: " << author << ", ID: " << id << endl;
    }
};

class DVD : public Item {
private:
    int duration; // Duration in minutes

public:
    DVD(const string& title, unsigned int id, int duration)
        : Item(title, id), duration(duration) {}

    void display() const override {
        cout << "DVD - Title: " << title << ", Duration: " << duration << "min, ID: " << id << endl;
    }
};

class LibraryItem : public Item {
private:
    ILoanStrategy* loanStrategy;

public:
    LibraryItem(const string& title, unsigned int id, ILoanStrategy* strategy)
        : Item(title, id), loanStrategy(strategy) {}

    void setLoanStrategy(ILoanStrategy* strategy) {
        loanStrategy = strategy;
    }

    void loanItem() const {
        loanStrategy->executeLoan();
    }

    void display() const override {
        cout << "Library Item - Title: " << title << ", ID: " << id << endl;
    }
};

int main() {
    ShortTermLoan shortTerm;
    LongTermLoan longTerm;

    LibraryItem book("The Great Gatsby", 1, &shortTerm);
    book.display();
    book.loanItem();

    // Dynamically changing loan strategy
    book.setLoanStrategy(&longTerm);
    book.loanItem();

    return 0;
}