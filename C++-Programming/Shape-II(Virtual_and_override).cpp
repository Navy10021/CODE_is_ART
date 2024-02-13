#include <iostream>

class Shape {
public:
    // Virtual function for calculating area
    virtual double calculateArea() const {
        std::cout << "Area of the base Shape class\n";
        return 0.0;
    }

    // Function for displaying shape information
    void display() const {
        std::cout << "This is a Shape\n";
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the virtual function for Circle
    double calculateArea() const override {
        std::cout << "Area of the Circle\n";
        return 3.14 * radius * radius;
    }

    // Function for displaying circle information
    void display() const {
        std::cout << "This is a Circle with radius " << radius << "\n";
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the virtual function for Rectangle
    double calculateArea() const override {
        std::cout << "Area of the Rectangle\n";
        return length * width;
    }

    // Overloaded function for displaying rectangle information
    void display(bool detailed) const {
        if (detailed)
            std::cout << "This is a Rectangle with length " << length << " and width " << width << "\n";
        else
            std::cout << "This is a Rectangle\n";
    }
};

int main() {
    // Example of virtual function and polymorphism
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    // Calls the appropriate overridden function based on the actual object type
    std::cout << "Area of shape1: " << shape1->calculateArea() << std::endl;
    std::cout << "Area of shape2: " << shape2->calculateArea() << std::endl;

    // Example of function overloading
    Rectangle rectangle(3.0, 4.0);
    std::cout << "Area of rectangle: " << rectangle.calculateArea() << std::endl;

    // Calls the overloaded display function based on the parameter
    rectangle.display(true);  // Detailed display
    rectangle.display(false); // Simple display

    delete shape1;
    delete shape2;

    return 0;
}
