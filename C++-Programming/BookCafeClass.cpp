#include <iostream>
#include <algorithm> // for std::sort

using namespace std;
const int MAX_BOOKS = 5;

// Book Class
class Book {
private:
    string title;
    int bookID;
public:
    Book(const string& bookTitle, int ID)
        : bookID(ID), title(bookTitle) {}

    virtual double CalculateDiscountedPrice() const = 0; // Pure virtual
    virtual void DisplayInfo() const {
        cout << "Book ID: " << bookID << " || Title: " << title;
    }

    virtual ~Book() {}
};

class FictionBook : public Book {
private:
    string genre;
    double basePrice;
public:
    FictionBook(const string& title, int ID, const string& bookGenre, double price)
        : Book(title, ID), genre(bookGenre), basePrice(price) {}

    double CalculateDiscountedPrice() const override {
        // Fiction books have a discount based on the genre
        if (genre == "Mystery") {
            return basePrice * 0.9;
        }
        else {
            return basePrice * 0.8;
        }
    }

    void DisplayInfo() const override {
        Book::DisplayInfo();
        cout << " || Type: Fiction || Genre: " << genre << " || Discounted Price: $" << CalculateDiscountedPrice() << endl;
    }
};

class NonFictionBook : public Book {
private:
    int pageCount;
    double basePrice;
public:
    NonFictionBook(const string& title, int ID, int pages, double price)
        : Book(title, ID), pageCount(pages), basePrice(price) {}

    double CalculateDiscountedPrice() const override {
        // Non-fiction books have a discount based on the page count
        if (pageCount > 500) {
            return basePrice * 0.85;
        }
        else {
            return basePrice * 0.9;
        }
    }

    void DisplayInfo() const override {
        Book::DisplayInfo();
        cout << " || Type: Non-Fiction || Page Count: " << pageCount << " || Discounted Price: $" << CalculateDiscountedPrice() << endl;
    }
};

class Bookstore {
private:
    Book* booksArr[MAX_BOOKS];
    int numBooks;
public:
    Bookstore() : numBooks(0) {}   // Constructor

    ~Bookstore() {	// Destructor
        for (int i = 0; i < numBooks; i++) {
            delete booksArr[i];
        }
    }

    void AddBook(Book* book) {
        if (numBooks < MAX_BOOKS) {
            booksArr[numBooks++] = book;
        }
        else {
            cout << "Maximum book limit reached. Cannot add more." << endl;
            delete book;
        }
    }

    double TotalDiscountedPrice() const {
        double total = 0.0;
        for (int i = 0; i < numBooks; i++) {
            total += booksArr[i]->CalculateDiscountedPrice();
        }
        return total;
    }

    void sortByDiscountedPrice() {
        sort(booksArr, booksArr + numBooks, [](const Book* a, const Book* b) {
            return a->CalculateDiscountedPrice() > b->CalculateDiscountedPrice();
        });
    }

    void DisplayBooks() const {
        for (int i = 0; i < numBooks; i++) {
            booksArr[i]->DisplayInfo();
        }
    }
};

int main(void) {
    Bookstore MyBookstore;
    Book* ptr;

    ptr = new FictionBook("The Da Vinci Code", 501, "Mystery", 19.99);
    MyBookstore.AddBook(ptr);

    ptr = new NonFictionBook("Sapiens", 502, 450, 24.99);
    MyBookstore.AddBook(ptr);

    ptr = new FictionBook("To Kill a Mockingbird", 503, "Drama", 15.99);
    MyBookstore.AddBook(ptr);

    ptr = new NonFictionBook("The Elements of Style", 504, 105, 12.99);
    MyBookstore.AddBook(ptr);

    ptr = new FictionBook("1984", 505, "Dystopian", 18.99);
    MyBookstore.AddBook(ptr);

    cout << "Total Discounted Price in the bookstore: $" << MyBookstore.TotalDiscountedPrice() << endl;
    MyBookstore.sortByDiscountedPrice();
    MyBookstore.DisplayBooks();

    return 0;
}
