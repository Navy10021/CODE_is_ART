#include <stdio.h>
#include <math.h>

class Shape {
protected:
    float side;

public:
    Shape(float _side) : side(_side) {} // Constructor

    float getX(void) const {
        return side;
    }

    virtual float area(void) {
        return side * side;
    }

    void print() {
        printf("This is Shape. Area is %.5f\n", area());
    }
};

class Square : public Shape {
public:
    Square(float side) : Shape(side) {} // Constructor that calls the base class constructor

    float area() override {
        return Shape::side * Shape::side;
        // or return getX() * getX();
    }

    void print() {
        printf("This is Square. Area is %.5f\n", area());
    }
};

class Equilateral : public Shape {
public:
    Equilateral(float side) : Shape(side) {} // Constructor that calls the base class constructor

    float area() override {
        return (sqrt(3.0) / 4) * Shape::side * Shape::side; // Calculate the area of an equilateral triangle
    }

    void print() {
        printf("This is Equilateral. Area is %.5f\n", area());
    }
};

int main() {
    Square square(5.0f);     // Create a square with a side length of 5.0
    Equilateral equil(4.0f);

    square.print();
    equil.print();

    Shape* s1 = &square;    // Create a pointer to the Shape object
    Shape* s2 = &equil;
    s1->print();
    s2->print();

    return 0;
}
