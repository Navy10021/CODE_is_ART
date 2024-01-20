#include <iostream>
#include <cmath>

class Point {
protected:
    double x;
    double y;

public:
    Point(double _x, double _y) : x(_x), y(_y) {}

    virtual void display() const {
        std::cout << "Point - X: " << x << ", Y: " << y << std::endl;
    }
};

class Line : public Point {
private:
    double endX;
    double endY;

public:
    Line(double startX, double startY, double endX, double endY) : Point(startX, startY), endX(endX), endY(endY) {}

    void display() const override {
        Point::display();
        std::cout << "End Point - X: " << endX << ", Y: " << endY << std::endl;
    }

    double calculateDistance() const {
        return std::sqrt(std::pow(endX - x, 2) + std::pow(endY - y, 2));
    }
};


class Circle : public Point {
private:
    double radius;

public:
    Circle(double centerX, double centerY, double r) : Point(centerX, centerY), radius(r) {}

    void display() const override {
        Point::display();
        std::cout << "Radius: " << radius << std::endl;
    }

    double calculateArea() const {
        return 3.14 * radius * radius;
    }

    double calculateCircumference() const {
        return 2 * 3.14 * radius;
    }
};

class Ellipse : public Point {
private:
    double semiMajorAxis;
    double semiMinorAxis;

public:
    Ellipse(double centerX, double centerY, double a, double b) : Point(centerX, centerY), semiMajorAxis(a), semiMinorAxis(b) {}

    void display() const override {
        Point::display();
        std::cout << "Semi-Major Axis: " << semiMajorAxis << ", Semi-Minor Axis: " << semiMinorAxis << std::endl;
    }

    double calculateArea() const {
        return 3.14 * semiMajorAxis * semiMinorAxis;
    }

    double calculatePerimeter() const {
        return 2 * 3.14 * std::sqrt((semiMajorAxis * semiMajorAxis + semiMinorAxis * semiMinorAxis) / 2);
    }
};


class Rectangle : public Point {
private:
    double width;
    double height;

public:
    Rectangle(double leftTopX, double leftTopY, double w, double h) : Point(leftTopX, leftTopY), width(w), height(h) {}

    void display() const override {
        Point::display();
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }

    double getWidth() const {
        return width;
    }

    double getHeigth() const {
        return height;
    }

    double calculateArea() const {
        return width * height;
    }

    double calculatePerimeter() const {
        return 2 * (width + height);
    }
};

class Square : public Rectangle {
public:
    Square(double leftTopX, double leftTopY, double side) : Rectangle(leftTopX, leftTopY, side, side) {}

    void display() const override {
        Rectangle::display();
        std::cout << "Side: " << Rectangle::getWidth() << std::endl; // Square has equal sides, so getting width is sufficient
    }
};


class Triangle : public Point {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double vertex1X, double vertex1Y, double vertex2X, double vertex2Y, double vertex3X, double vertex3Y)
        : Point(vertex1X, vertex1Y), side1(0), side2(0), side3(0) {
        // Calculate the lengths of the sides
        side1 = std::sqrt(std::pow(vertex2X - vertex1X, 2) + std::pow(vertex2Y - vertex1Y, 2));
        side2 = std::sqrt(std::pow(vertex3X - vertex2X, 2) + std::pow(vertex3Y - vertex2Y, 2));
        side3 = std::sqrt(std::pow(vertex1X - vertex3X, 2) + std::pow(vertex1Y - vertex3Y, 2));
    }

    void display() const override {
        Point::display();
        std::cout << "Side1: " << side1 << ", Side2: " << side2 << ", Side3: " << side3 << std::endl;
    }

    double calculateArea() const {
        // Using Heron's formula to calculate the area
        double s = (side1 + side2 + side3) / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const {
        return side1 + side2 + side3;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double centerX, double centerY, double side)
        : Triangle(centerX - side / 2, centerY - (sqrt(3) / 2) * side / 2,
                   centerX + side / 2, centerY - (sqrt(3) / 2) * side / 2,
                   centerX, centerY + (sqrt(3) / 2) * side / 2) {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double centerX, double centerY, double base, double height)
        : Triangle(centerX - base / 2, centerY - height / 2,
                   centerX + base / 2, centerY - height / 2,
                   centerX, centerY + height / 2) {}
};

int main() {
    Line line(0, 0, 3, 4);
    Circle circle(2, 3, 5);
    Rectangle rectangle(1, 1, 4, 3);
    Square square(5, 5, 2);
    Ellipse ellipse(8, 8, 6, 4);
    Triangle triangle(1, 1, 4, 1, 3, 5);
    EquilateralTriangle equilateralTriangle(8, 8, 4);
    IsoscelesTriangle isoscelesTriangle(15, 15, 6, 8);


    line.display();
    std::cout << "Distance: " << line.calculateDistance() << std::endl;

    circle.display();
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    std::cout << "Circumference: " << circle.calculateCircumference() << std::endl;

    rectangle.display();
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;

    square.display();
    std::cout << "Area: " << square.calculateArea() << std::endl;
    std::cout << "Perimeter: " << square.calculatePerimeter() << std::endl;

    ellipse.display();
    std::cout << "Area: " << ellipse.calculateArea() << std::endl;
    std::cout << "Perimeter: " << ellipse.calculatePerimeter() << std::endl;

    triangle.display();
    std::cout << "Area: " << triangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
    
    equilateralTriangle.display();
    std::cout << "Area: " << equilateralTriangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << equilateralTriangle.calculatePerimeter() << std::endl;

    isoscelesTriangle.display();
    std::cout << "Area: " << isoscelesTriangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << isoscelesTriangle.calculatePerimeter() << std::endl;

    return 0;
}
