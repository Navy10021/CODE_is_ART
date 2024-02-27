#include <iostream>
#include <cstring> // strlen, strcpy 함수를 사용하기 위해 포함

class String {
private:
    char* data; // 문자열 데이터를 위한 포인터

public:
    // 기본 생성자
    String() : data(new char[1]) {
        *data = '\0'; // 빈 문자열로 초기화
    }

    // 매개변수가 있는 생성자
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // 복사 생성자 (깊은 복사)
    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // 대입 연산자 오버로딩 (깊은 복사)
    String& operator=(const String& other) {
        if (this != &other) { // 자기 자신에게 할당하는 경우를 방지
            delete[] data; // 기존 메모리 해제
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data); // 깊은 복사
        }
        return *this;
    }

    // 소멸자
    ~String() {
        delete[] data;
    }

    // 문자열 출력을 위한 함수
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    // "Hello"를 저장하는 String 객체 생성
    String str1("Hello");

    // str1을 사용하여 str2를 초기화 (복사 생성자 호출)
    String str2 = str1;

    // str2의 내용을 출력 (변경 전)
    std::cout << "str2 before change: ";
    str2.print();

    // str1의 복사본인 str2의 데이터를 변경
    String str3;
    str3 = "Goodbye";
    str2 = str3;    // 대입연산자 

    // 변경 후 str2의 내용을 출력하여 str1과의 독립성 확인
    std::cout << "str1 : ";
    str1.print();
    std::cout << "str2 after change to str3: ";
    str2.print();

    return 0;
}