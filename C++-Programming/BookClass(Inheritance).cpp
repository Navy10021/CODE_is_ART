#include <iostream>
#include <cstring>

using namespace std;

class Book{
    private:
        char * title;       // 제목
        char * isbn;        // 도서번호
        int price;          // 정가

    public:
        Book(const char * title, const char * isbn, int money)
            : price(money){
                this->title = new char[strlen(title) + 1];
                this->isbn = new char[strlen(isbn) + 1];
                strcpy(this->title, title);
                strcpy(this->isbn, isbn);
            }

        void ShowBookInfo() const{
            cout << "Title : " << title << endl;
            cout << "ISBN : " << isbn << endl;
            cout << "Price : " << price << endl;
        }
};

class EBook : public Book{
    private:
        char * DRMKey;      // 보안키 
    
    public:
        EBook(const char * title, const char * isbn, int money, const char * key)
            : Book(title, isbn, money){
                DRMKey = new char[strlen(key) + 1];
                strcpy(DRMKey, key);
            }
        
        void ShowE_BookInfo() const{
            ShowBookInfo();
            cout << "Key number : " << DRMKey << endl;
        }
};


int main(void){
    Book book1("Nice C++", "111-123-456", 25000);
    book1.ShowBookInfo();
    cout << endl;

    EBook ebook2("Nice C++ e-book", "111-123-456", 15000, "axefcvsi123");
    ebook2.ShowE_BookInfo();

    return 0;
}
