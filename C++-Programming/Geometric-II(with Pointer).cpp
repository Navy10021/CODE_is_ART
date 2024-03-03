#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

class Point {
    /* Attributor */
    protected: // inheritance
        double x;
        double y;

    public:
        Point(double _x, double _y) : x(_x), y(_y) {}
        /* If using "Accessor"
        double getX() {return x;}
        double getY() {return y;}
        */
        virtual void display() const {
            cout << "Point - [" << x << ", " << y << "]" << endl;
        }
        virtual double getArea() const = 0; // pure virtual function
        virtual double getPerimeter() const = 0; // pure virtual function

        ~Point() {}
};

class Line : public Point {
    private:
        double endX;
        double endY;

    public:
        Line(double startX, double startY, double endX, double endY) : Point(startX, startY), endX(endX), endY(endY) {}

        void display() const override {
            Point::display();
            cout << "End Point - [" << endX << ", " << endY << "]" << endl;
        }
        
        double getArea() const override {
            return 0;
        }
        
        double getPerimeter() const override{
            return getDistance();
        }
        
        double getDistance() const {
            double dx = endX - x;
            double dy = endY - y;
            return sqrt(dx*dx + dy*dy);
        }
        
        double getSlope() const {
            double dx = endX - x;
            double dy = endY - y;
            return (dx == 0) ? INFINITY : dy / dx;
        }
        ~Line() {}
};

// 원 
class Circle : public Point {
    private:
        double radius;

    public:
        Circle(double centerX, double centerY, double r) : Point(centerX, centerY), radius(r) {}

        void display() const override {
            Point::display();
            cout << "This is Circle || ";
            cout << "Radius: " << radius << endl;
        }

        double getArea() const override {
            return 3.14 * radius * radius;
        }

        double getPerimeter() const override{
            return 2 * 3.14 * radius;
        }
        ~Circle() {}
};

// 타원
class Ellipse : public Point {
    private:
        double semiMajorAxis;
        double semiMinorAxis;

    public:
        Ellipse(double centerX, double centerY, double a, double b) : Point(centerX, centerY), semiMajorAxis(a), semiMinorAxis(b) {}

        void display() const override {
            Point::display();
            cout << "This is Ellipse || ";
            cout << "Semi-Major Axis: " << semiMajorAxis << ", Semi-Minor Axis: " << semiMinorAxis << endl;
        }

        double getArea() const override {
            return 3.14 * semiMajorAxis * semiMinorAxis;
        }

        double getPerimeter() const override {
            return 2 * 3.14 * sqrt((semiMajorAxis * semiMajorAxis + semiMinorAxis * semiMinorAxis) / 2);
        }
        ~Ellipse() {}
};


class Rectangle : public Point {
    private:
        double width;
        double height;

    public:
        Rectangle(double leftTopX, double leftTopY, double w, double h) : Point(leftTopX, leftTopY), width(w), height(h) {}

        void display() const override {
            Point::display();
            cout << "This is Rectangle || ";
            std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }

        double getWidth() const {
            return width;
        }

        double getHeigth() const {
            return height;
        }

        double getArea() const override {
            return width * height;
    }

        double getPerimeter() const override {
            return 2 * (width + height);
        }
        ~Rectangle() {}
};

class Square : public Rectangle {
    public:
        Square(double leftTopX, double leftTopY, double side) : Rectangle(leftTopX, leftTopY, side, side) {}

        void display() const override {
            Rectangle::display();
            std::cout << "Side: " << Rectangle::getWidth() << endl; // Square has equal sides, so getting width is sufficient
        }
        // 상속의 상속은 override에 대한 추가함수 구현 불필요!
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
        side1 = sqrt(pow(vertex2X - vertex1X, 2) + pow(vertex2Y - vertex1Y, 2));
        side2 = sqrt(pow(vertex3X - vertex2X, 2) + pow(vertex3Y - vertex2Y, 2));
        side3 = sqrt(pow(vertex1X - vertex3X, 2) + pow(vertex1Y - vertex3Y, 2));
    }

    void display() const override {
        Point::display();
        cout << "This is Triangle || ";
        cout << "Side1: " << side1 << ", Side2: " << side2 << ", Side3: " << side3 << endl;
    }

    double getArea() const override {
        // Using Heron's formula to calculate the area
        double s = (side1 + side2 + side3) / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double getPerimeter() const override {
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
    vector<Point*> shapes;
    
    shapes.push_back(new Line(0, 0, 3, 4));
    shapes.push_back(new Circle(2, 3, 5));
    shapes.push_back(new Ellipse(2, 3, 6, 4));
    shapes.push_back(new Rectangle(1, 0, 5, 6));
    shapes.push_back(new Square(1, 0, 5));
    shapes.push_back(new Triangle(5, 5, 1, 1, 3, 5));
    shapes.push_back(new EquilateralTriangle(5, 5, 10));
    shapes.push_back(new IsoscelesTriangle(5, 5, 6, 8));
    
    for (auto& s : shapes){
        cout << "Perimeter : " << s->getPerimeter() << endl;
        cout << "Area : " << s->getArea() << endl;
    }
    
    // clean up 
    for (auto& s : shapes){
        delete s;
    }
    shapes.clear();
    
    
    /*
    Line line(0, 0, 3, 4);
    
    // 원형 컨트롤 포인터
    Point* ptr1 = new Circle(2, 3, 5);
    //delete ptr1;    // delete previous object
    ptr1 = new Ellipse(2, 3, 6, 4);
    // 사각형 컨트롤 포인터
    Point* ptr2 = new Rectangle(1, 1, 4, 3);
    //delete ptr2;
    ptr2 = new Square(1, 1, 5);
    // 삼각형 컨트롤 포인터 
    Point* ptr3 = new Triangle(4, 4, 4, 1, 3, 5);
    ptr3 = new EquilateralTriangle(4, 4, 5);
    ptr3 = new IsoscelesTriangle(4, 4, 6, 8);
    
    
    line.display();
    cout << "Distance: " << line.getPerimeter() << endl;
    
    ptr1->display();
    cout << "Area:" << ptr1->getArea() << endl;
    cout << "Perimeter: " << ptr1->getPerimeter() << endl;
    
    ptr2->display();
    cout << "Area: " << ptr2->getArea() << endl;
    cout << "Perimeter: " << ptr2->getPerimeter() << endl;
    
    ptr3->display();
    cout << "Area: " << ptr3->getArea() << endl;
    cout << "Perimeter: " << ptr3->getPerimeter() << endl;
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    */
    return 0;
}
