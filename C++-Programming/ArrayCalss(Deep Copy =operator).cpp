#include <iostream>
#include <algorithm>

using namespace std;

class IntArray {
private:
    int* data;
    size_t size;

public:
    // 기본 생성자
    IntArray() : data(nullptr), size(0) {}

    // 매개변수가 있는 생성자
    IntArray(size_t size) : size(size), data(new int[size]) {}

    // 복사 생성자 (깊은 복사)
    IntArray(const IntArray& other) : size(other.size), data(new int[other.size]) {
        copy(other.data, other.data + other.size, data); // [first, end), result
    }

    // 대입 연산자 오버로딩 (깊은 복사)
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            delete[] data; // 기존 데이터 메모리 해제
            size = other.size;
            data = new int[size];
            copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // 소멸자
    ~IntArray() {
        delete[] data;
    }

    // 배열 요소에 접근하는 함수
    int& operator[](size_t index) {
        return data[index];
    }

    // 배열의 크기를 반환하는 함수
    size_t getSize() const {
        return size;
    }
};

int main() {
    // 5개의 요소를 가진 IntArray 객체 생성
    IntArray arr1(5);
    for (size_t i = 0; i < arr1.getSize(); ++i) {
        arr1[i] = i * 10; // 일부 데이터 초기화
    }

    // arr1을 사용하여 arr2를 초기화 (복사 생성자 호출)
    IntArray arr2 = arr1;

    // arr2의 내용 출력 (복사 후)
    cout << "arr2 after copy: ";
    for (size_t i = 0; i < arr2.getSize(); ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    // arr2의 첫 번째 요소를 변경
    arr2[0] = 100;

    // arr1과 arr2의 내용을 비교하여 독립성 확인
    cout << "arr1 after arr2 modification: ";
    for (size_t i = 0; i < arr1.getSize(); ++i) {
        cout << arr1[i] << " ";
    }
    cout << "\n";

    cout << "arr2 after modification: ";
    for (size_t i = 0; i < arr2.getSize(); ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    return 0;
}