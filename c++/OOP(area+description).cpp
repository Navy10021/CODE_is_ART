#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define M_PI 3.14

// Base class Shape
class Shape {
public:
    virtual double CalculateArea() const = 0;       // 도형 넓이
    virtual double CalculatePerimeter() const = 0;  // 도형 둘래
    virtual string description() const = 0;         // 도형에 대한 설명
};

// Derived class Circle
class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double CalculateArea() const override {
        return M_PI * radius * radius;
    }

    double CalculatePerimeter() const override {
        return 2 * M_PI * radius;
    }

    string description() const override{
        return "  The circle's radius : " + to_string(radius) + ")";
    }

private:
    double radius;
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double CalculateArea() const override {
        return length * width;
    }

    double CalculatePerimeter() const override {
        return 2 * (length + width);
    }

    string description() const override{
        return "  The rectangle's length & width : " + to_string(length) + ", " + to_string(width) + ")";
    }

private:
    double length;
    double width;
};

// Derived class Triangle
class Triangle : public Shape {
public:
    Triangle(double sideA, double sideB, double sideC)
        : sideA(sideA), sideB(sideB), sideC(sideC) {}

    double CalculateArea() const override {
        // Using Heron's formula to calculate area
        double s = (sideA + sideB + sideC) / 2.0;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double CalculatePerimeter() const override {
        return sideA + sideB + sideC;
    }

    string description() const override{
        return "  The triangle's sides : " + to_string(sideA) + ")";
    }


private:
    double sideA;
    double sideB;
    double sideC;
};

int main() {
    // Create instances of different shapes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    // Calculate and display area and perimeter for each shape
    cout << "Circle - Area: " << circle.CalculateArea()
         << ", Perimeter: " << circle.CalculatePerimeter() 
         << circle.description()
         << endl;

    cout << "Rectangle - Area: " << rectangle.CalculateArea()
         << ", Perimeter: " << rectangle.CalculatePerimeter() 
         << rectangle.description()
         << endl;

    cout << "Triangle - Area: " << triangle.CalculateArea()
         << ", Perimeter: " << triangle.CalculatePerimeter() 
         << triangle.description()
         << endl;

    return 0;
}
