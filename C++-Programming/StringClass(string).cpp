#include <iostream>
#include <cstring>

using namespace std;

// Class 선언
class String{
    private:
        int len;
        char *str;

    public:
        String();    // Constructor
        String(const char *s);    // Constructor
        String(const String& s);  // Deep copy 
        ~String();   // Destructor
        int length();
        String& operator= (const String& s);   // 변경된 객체의 주소값 반환
        String& operator+= (const String& s);
        bool operator== (const String& s);
        String operator+ (const String& s);    // 새로운 객체를 생성하여 반환

        friend ostream& operator<< (ostream& os, const String& s);
        friend istream& operator>> (istream& is, String& s);
};

// Class의 멤버함수와 전역함수
String::String(){
    len = 0;
    str = NULL;
}

String::String(const char *s){
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}

// Deep Copy Constructor
String::String(const String& s){
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}

String::~String(){
    if(str != NULL)
        delete []str;
}

int String::length(){
    return len;
}

// Deep Copy = operator
String& String::operator= (const String& s){
    if (str != NULL)
        delete []str;
    len = s.len;       // String class이므로 '\0' 불필요
    str = new char[len];
    strcpy(str, s.str);
    return *this;
}

String& String::operator+= (const String& s){
    len += (s.len - 1);
    char* tempstr = new char[len];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);

    if (str != NULL)
        delete []str;
    str = tempstr;
    return *this;
}

bool String::operator== (const String& s){
    return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s){
    char *tempstr = new char[len + s.len + 1];  
    strcpy(tempstr, str);
    strcat(tempstr, s.str);

    String temp(tempstr);   // Create new Class objection. Same as String temp = tempstr;
    delete []tempstr;
    return temp;
}

// 전역함수
ostream& operator<< (ostream& os, const String& s){
    os << s.str;
    return os;
}

istream& operator>> (istream& is, String& s){
    char str[100];
    is >> str;
    s = String(str);
    return is;
}


int main(void){
    String str1 = "Hello, ";
    String str2 = "NAVY Lee.";
    String str3 = str1 + str2;

    cout << str1 << " " << str1.length() << endl;
    cout << str2 << " " << str2.length() << endl;
    cout << str3 << " " << str3.length() << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "Same strings!" << endl;
    else
        cout << "NOT same string." << endl;
    String str4;
    cout << "Enter String : " ;
    cin >> str4;
    cout << "Your string : " << str4 <<endl;
    return 0;
}




