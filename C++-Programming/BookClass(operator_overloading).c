#include <iostream>
#include <cstring>
using namespace std;

class Book{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(const char * title, const char * isbn, int value) : price(value){
            this->title = new char[strlen(title) + 1];
            this->isbn = new char[strlen(isbn) + 1];
            strcpy(this->title, title);
            strcpy(this->isbn, isbn);
        }
        // Deep Copy
        Book(const Book & ref) : price(ref.price){
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
        // Operator overloading
        Book& operator=(const Book & ref){ // 깊은 복사를 진행
            delete []title;
            delete []isbn;   // 메모리 누수 방지를 위해 삭제

            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
            price = ref.price;
            return *this;
        }
        void ShowBookInfo(){
            cout << "Titile : " << title << endl;
            cout << "ISBN : " << isbn << endl;
            cout << "Price : " << price << endl;
        }
        ~Book(){
            delete [] title;
            delete [] isbn;
        }
};

class EBook : public Book{
    private:
        char * DRMKey;
    public:
        EBook(const char * title, const char * isbn, int value, const char * key) : Book(title, isbn, value){
            DRMKey = new char[strlen(key) + 1];
            strcpy(DRMKey, key);
        }
        EBook (const EBook & ref) : Book(ref) // 상속한 book의 모든 객체를 참조할 수 있다.
        {
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
        }
        EBook& operator=(const EBook& ref){ // 깊은 복사를 진행
            Book::operator=(ref);     // 기초클래스 대입 연산자 필히 호출, EBook 상속한 모든 객체를 참조할 수 있다.
            delete []DRMKey;          // 메모리 누수 방지
            DRMKey= new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
            return *this;
        }
        void ShowEBookInfo(){
            ShowBookInfo();
            cout << "Key Num : " << DRMKey << endl;
        }
        ~EBook(){
            delete []DRMKey;
        }      
};

int main(void){
    EBook ebook1("Good C++", "123-456-789", 25000, "ABX21");
    EBook ebook2 = ebook1;   //복사생성자 호출
    ebook2.ShowEBookInfo();
    cout << endl;
    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2;         //복사생성자 호출
    ebook3.ShowEBookInfo();
    cout << endl;
    return 0;
}

