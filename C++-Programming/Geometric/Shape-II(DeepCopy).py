#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
using namespace std;
# define M_PI 3.1415

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    // Deep Copy
    Circle& operator=(const Circle& other){
        if (this != &other){
            this->radius = other.radius;
        }
        return *this;
    }
    double area() const override { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
    void display() const override {
        cout << "Circle - Radius: " << radius << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double length, double width) : length(length), width(width) {}
    Rectangle& operator=(const Rectangle& other){
        if (this != &other){
            this->length = other.length;
            this->width = other.width;
        }
        return *this;
    }
    double area() const override { return length * width; }
    double perimeter() const override { return 2 * (length + width); }
    void display() const override {
        cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
    void display() const override {
        cout << "Triangle - Sides: " << a << ", " << b << ", " << c << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    void display() const override {
        cout << "Square - Side: " << length << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

class Polygon : public Shape {
private:
    vector<double> sides;
    double circumRadius; // For area calculation of a regular polygon
public:
    Polygon(const vector<double>& sides, double circumRadius) 
        : sides(sides), circumRadius(circumRadius) {}

    double area() const override {
        if (sides.size() < 3) return 0; // Not a polygon
        double perimeter = this->perimeter();
        double angle = (360.0 / sides.size()) * (M_PI / 180.0); // Convert degrees to radians
        return 0.5 * sides.size() * circumRadius * circumRadius * sin(angle);
    }

    double perimeter() const override {
        double total = 0;
        for (auto side : sides) {
            total += side;
        }
        return total;
    }

    void display() const override {
        cout << "Polygon - Sides: " << sides.size() << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    Circle circle1(10);
    Circle circle2 = circle1;   // Deep Copy
    Rectangle rec1(10, 5);
    Rectangle rec2(10, 3);
    //rec2 = rec1;

    shapes.push_back(&circle1);
    shapes.push_back(&circle2);
    shapes.push_back(&rec1);
    shapes.push_back(&rec2);

    for (const auto& shape : shapes) {
        shape->display();
    }

    return 0;
}
