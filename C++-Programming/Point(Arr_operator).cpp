#include <iostream>
#include <cstdlib>

using namespace std;

class Point {
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);
    friend ostream& operator<<(ostream& os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

ostream& operator<<(ostream& os, const Point* pos) {
    os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
    return os;
}

typedef Point * POINT_PTR;   // 포인터형 정의

class BoundCheckPointArr {
private:
    //Point* arr;
    POINT_PTR * arr;        // Point 객체의 주소값을 요소로 저장    
    int arrlen;

    BoundCheckPointArr(const BoundCheckPointArr& arr){ }
    BoundCheckPointArr& operator=(const BoundCheckPointArr& arr){ }

public:
    // Constructor
    BoundCheckPointArr(int len) : arrlen(len) {
        //arr = new Point[len];
        arr = new POINT_PTR[len];
    }
    // Array [ ] index overloading: 참조값 반환 및 변경 가능
    POINT_PTR& operator[](int idx) {
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    // Array [ ] index overloading for const index: 배열 요소값을 단순히 반환
    POINT_PTR operator[](int idx) const {
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const {
        return arrlen;
    }

    ~BoundCheckPointArr() {
        delete[] arr;
    }
};

int main(void) {
    BoundCheckPointArr arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++) {
        cout << *(arr[i]);
    }

    for (int i = 0; i < arr.GetArrLen(); i++){
        cout << arr[i];
    }
    delete arr[0];
    delete arr[1];
    delete arr[2];
    
    return 0;
}