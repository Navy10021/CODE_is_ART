#include <iostream>
using namespace std;

class Shape {
public:
    virtual void ShowInfo() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {} // Constructor with default values
    
    void ShowPointInfo() const {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius;
public:
    Circle(int x, int y, int r) : center(x, y), radius(r) {} // Constructor
    
    void ShowInfo() const override { // Override to show circle info
        cout << "Circle Radius: " << radius << " Center: ";
        center.ShowPointInfo();
    }
};

class ColoredCircle : public Circle {
private:
    string color;
public:
    ColoredCircle(int x, int y, int r, string c)
        : Circle(x, y, r), color(c) {} // Constructor with color
    
    void ShowInfo() const override {
        Circle::ShowInfo(); // Call base class(Circle) implementation
        cout << "Color: " << color << endl;
    }
};

class Ring : public Shape {
private:
    Circle inCircle;
    Circle outCircle;
public:
    Ring(int inX, int inY, int inR, int outX, int outY, int outR)
        : inCircle(inX, inY, inR), outCircle(outX, outY, outR) {} // Constructor
    
    void ShowInfo() const override { // Override to show ring info
        cout << "Inner Circle Info: " << endl;
        inCircle.ShowInfo();
        cout << "Outer Circle Info: " << endl;
        outCircle.ShowInfo();
    }
};

class StyledRing : public Ring {
private:
    string style;
public:
    StyledRing(int inX, int inY, int inR, int outX, int outY, int outR, string s)
        : Ring(inX, inY, inR, outX, outY, outR), style(s) {} // Constructor with style
    
    void ShowInfo() const override {
        Ring::ShowInfo(); // Call base class(Ring) implementation
        cout << "Style: " << style << endl;
    }
};

int main(void) {
    ColoredCircle coloredCircle(3, 3, 7, "Red");
    StyledRing styledRing(1, 1, 4, 2, 2, 9, "Dashed");

    cout << "Colored Circle Info: " << endl;
    coloredCircle.ShowInfo(); // Show information about the colored circle

    cout << endl; // Just for clearer output separation

    cout << "Styled Ring Info: " << endl;
    styledRing.ShowInfo(); // Show information about the styled ring

    return 0;
}
