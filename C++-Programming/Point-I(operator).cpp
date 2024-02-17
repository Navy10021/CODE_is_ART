#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int xpos;
    int ypos;

public:
    Point(int x = 0, int y = 0)
        : xpos(x), ypos(y) {}

    void ShowPoint() const {
        cout << "[" << xpos << ", " << ypos << "]" << std::endl;
    }

    Point operator+(const Point& other) const {
        return Point(xpos + other.xpos, ypos + other.ypos);
    }

    Point operator-(const Point& other) const {
        return Point(xpos - other.xpos, ypos - other.ypos);
    }

    Point operator*(const Point& other) const {
        return Point(xpos * other.xpos, ypos * other.ypos);
    }

    Point operator/(const Point& other) const {
        // Check for division by zero
        if (other.xpos == 0 || other.ypos == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return Point();
        }

        return Point(xpos / other.xpos, ypos / other.ypos);
    }

    Point operator- (){
        Point pos(-xpos, -ypos);
        return pos;
    }

    Point operator~ (){
        Point pos(ypos, xpos);
        return pos;
    }

    Point operator+=(const Point & other){
        xpos += other.xpos; 
        ypos += other.ypos;
        return *this;
    }

    Point operator-=(const Point & other){
        xpos -= other.xpos;
        ypos -= other.ypos;
        return *this;
    }
                            
    Point& operator++(){   // Before Increase
        xpos += 1;
        ypos += 1;
        return *this;  // Return obj it-self.
    }

    const Point operator++(int){ // After Increase
        const Point retObj(xpos, ypos);    // cosnt Point retObj(*this); 값이 변경되지 않는 복사본 저장 및 리턴; const 의미 : xpos, ypos 값 변경 허용X
        xpos += 1;
        ypos += 1;
        return retObj;
    }

    Point& operator--(){
        xpos -= 1;
        ypos -= 1;
        return *this;  // Return Obj itself
    }

    const Point operator--(int){
        const Point retObj(xpos, ypos);
        xpos -= 1;
        ypos -= 1;
        return retObj;
    }

    bool operator==(const Point & other){
        if (xpos == other.xpos && ypos == other.ypos)
            return true;
        else
            return false;
    }

    bool operator!=(const Point & other){
        if (xpos != other.xpos || ypos != other.ypos)
            return true;
        else
            return false;
    }

    double distanceTo(const Point& other) const {
        int dx = xpos - other.xpos;
        int dy = ypos - other.ypos;
        return sqrt(dx * dx + dy * dy);
    }

    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos){
    os << "[" << pos.xpos << ", " << pos.ypos <<"]" << endl;
    return os;
}

istream& operator>>(istream& is, Point& pos){
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main() {
    Point p1;
    Point p2;

    cout << "Enter Point(x, y) :";
    cin >> p1;

    cout << "Enter Point(x, y) : ";
    cin >> p2;

    // Basic arithmetic operations
    Point res_add = p1 + p2;
    Point res_sub = p1 - p2;
    Point res_mul = p1 * p2;
    Point res_div = p1 / p2;
    bool res_equal = p1 == p2;
    bool res_diff = p1 != p2;
    Point res_sw = ~p1;
    Point res_updown = -p1;
    
    cout << "Point 1:"<< p1 << endl;
    cout << "Point 2:"<< p2 << endl;

    // Display results of basic arithmetic operations
    cout << "Addition: " << res_add << endl;
    cout << "Subtraction: " << res_sub << endl;
    cout << "Multiplication: " << res_mul << endl;
    cout << "Division: " << res_div << endl;
    cout << "Equal: " << res_equal << endl;
    cout << "Not Equal: " << res_diff << endl;
    cout << "Switch: " << res_sw << endl;
    cout << "Minus: " << res_updown << endl;

    return 0;
}
