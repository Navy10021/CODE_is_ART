#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string isbn;
    int price;
public:
    Book(const string& title, const string& isbn, int value) : title(title), isbn(isbn), price(value) {}
    
    // Copy constructor
    Book(const Book& ref) : title(ref.title), isbn(ref.isbn), price(ref.price) {}
    
    // Assignment operator overloading
    Book& operator=(const Book& ref) {
        title = ref.title;
        isbn = ref.isbn;
        price = ref.price;
        return *this;
    }
    
    void ShowBookInfo() {
        cout << "Title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;
    }
};

class EBook : public Book {
private:
    string DRMKey;
public:
    EBook(const string& title, const string& isbn, int value, const string& key) : Book(title, isbn, value), DRMKey(key) {}
    
    // Copy constructor
    EBook(const EBook& ref) : Book(ref), DRMKey(ref.DRMKey) {}
    
    // Assignment operator overloading
    EBook& operator=(const EBook& ref) {
        Book::operator=(ref);
        DRMKey = ref.DRMKey;
        return *this;
    }
    
    void ShowEBookInfo() {
        ShowBookInfo();
        cout << "Key Num : " << DRMKey << endl;
    }
};

int main() {
    EBook ebook1("Good C++", "123-456-789", 25000, "ABX21");
    EBook ebook2 = ebook1;   // Copy constructor called
    ebook2.ShowEBookInfo();
    cout << endl;
    
    EBook ebook3("dummy", "dummy", 0, "dummy");
    ebook3 = ebook2;         // Assignment operator called
    ebook3.ShowEBookInfo();
    cout << endl;
    
    return 0;
}