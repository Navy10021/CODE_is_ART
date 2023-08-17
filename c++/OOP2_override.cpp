#include <cstdlib>
#include <iostream>
#include <math.h>

class Shape {
public:
    Shape(const double _sideLength) : sideLength(_sideLength) {}

    virtual float area() {
        return static_cast<float>(sideLength * sideLength);
    }

    virtual void print() {
        std::cout << "This is Shape. Area is " << area() << "\n";
    }

protected:
    double sideLength;
};

class Square : public Shape {
public:
    Square(double _sideLength) : Shape(_sideLength) {}

    void print() override {
        std::cout << "This is Square. Area is " << area() << "\n";
    }
};

class Equilateral : public Shape {
public:
    Equilateral(double _sideLength) : Shape(_sideLength) {}

    float area() override {
        return static_cast<float>((std::sqrt(3) / 4) * sideLength * sideLength);
    }

    void print() override {
        std::cout << "This is Equilateral Triangle. Area is " << area() << "\n";
    }
};

int main() {
    Square sq(5.0f);
    Equilateral eq(4.0f);

    sq.print();
    eq.print();
    
    Shape* s1 = &sq;
    Shape* s2 = &eq;
    
    s1->print();
    s2->print();

    return EXIT_SUCCESS;
}
