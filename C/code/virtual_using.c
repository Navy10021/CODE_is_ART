/*
가상함수 테이블을 영어로 한다면 Virtual Function Table입니다. 
여기서 테이블은 배열을 뜻합니다. 즉 가상함수 테이블은 함수 포인터 배열이라고 생각하시면 됩니다. 
*/

#include <iostream>
using namespace std;

class Parent{
public:
    virtual void func1() {
        cout << "이곳은 Parent의 func1입니다." << endl;
    }
    virtual void func2() {
        cout << "이곳은 Parent의 func2입니다." << endl;
    }
    void func3() { //가상함수 X
        cout << "이곳은 Parent의 func3입니다." << endl;
    }
};

class Child : public Parent{
public:
    virtual void func1() {
        cout << "이곳은 Child의 func1입니다." << endl;
    }
};

void main() {
    Parent* p = new Parent;
    Child* c = new Child;
    
    p->func1();  // "이곳은 Parent의 func1입니다."
    c->func1();  // "이곳은 Child의 func1입니다." 
    p->func2();  // "이곳은 Parent의 func2입니다."
    c->func2();  // "이곳은 Parent의 func2입니다."
    p->func3();  // "이곳은 Parent의 func3입니다."
    c->func3();  // "이곳은 Parent의 func3입니다."
}
