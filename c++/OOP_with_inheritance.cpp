#include <iostream>
#include <cmath>

class Point{
    private:
        double x, y;
    
    public:
        Point(double _x, double _y) : x(_x), y(_y) {}   

        double getX() const{
            return x;
        }
        
        double getY() const{
            return y;
        }

        // 입력받기 위한 생성자
        double distancesTo(const Point& other) const{
            return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
        }
};

class Line{
    // Point inheritance? No -> get Point class
    private:
        Point start, end;
    public:
        Line(const Point& _start, const Point& _end) : start(_start), end(_end) {}

        double length() const {
            return start.distancesTo(end);
        }
};

class Triangle{
    // get Point class
    private:
        Point a, b, c;
    public:
        Triangle(const Point& _a, const Point& _b, const Point& _c) : a(_a), b(_b), c(_c) {}

        double perimeter() const {
            return a.distancesTo(b) + b.distancesTo(c) + c.distancesTo(a);
        }

        double area() const {
            double s = perimeter() / 2.0;
            return std::sqrt(s * (s - a.distancesTo(b)) * (s - b.distancesTo(c)) * (s - c.distancesTo(a)));
        }
};

// Equilateral triangle(정삼각형) : inheritance Triangle class
class EquilateralTriangle : public Triangle{
    public:
        EquilateralTriangle(const Point& center, double sideLength):
            Triangle(
                center,
                Point(center.getX() + sideLength / 2.0, center.getY() + (sideLength * std::sqrt(3)) / 2.0),
                Point(center.getX() - sideLength / 2.0, center.getY() + (sideLength * std::sqrt(3)) / 2.0)
                ) {}
};

// Isosceles triangle(이등변삼각형) : inheritance Triangle class
class IsoscelesTriangle : public Triangle{
    public:
        IsoscelesTriangle(const Point& apex, double baseLength, double sideLength):
            Triangle(
                apex,
                Point(apex.getX() - baseLength / 2.0, apex.getY()),
                Point(apex.getX() + baseLength / 2.0, apex.getY() + sideLength)
                ) {}
};

// Scalene triangle(삼각형)
class ScaleneTriangle : public Triangle {
    public:
        ScaleneTriangle(const Point& _a, const Point& _b, const Point& _c):
            Triangle(_a, _b, _c) {}
};

class Quadrilateral{
    private:
        Point a, b, c, d;
    public:
        Quadrilateral(const Point& _a, const Point& _b, const Point& _c, const Point _d) : a(_a), b(_b), c(_c), d(_d) {}

        double perimeter() const {
            return a.distancesTo(b) + b.distancesTo(c) + c.distancesTo(d) + d.distancesTo(a);
        }

        double area() const {
            double base1 = a.distancesTo(b);
            double base2 = c.distancesTo(d);
            double height = b.distancesTo(c);
            return 0.5 * (base1 + base2) * height;
        }
};

// Rectangle(직사각형)
class Rectangle : public Quadrilateral{
    public:
        Rectangle(const Point& _topLeft, double width, double height):
            Quadrilateral(
                _topLeft, 
                Point(_topLeft.getX() + width, _topLeft.getY()),
                Point(_topLeft.getX() + width, _topLeft.getY() - height),
                Point(_topLeft.getX(), _topLeft.getY() - height)
                ) {}
};

// Square(정사각형) : inheritance Rectangle
class Square : public Rectangle{
    public:
        Square(const Point& _topLeft, double sideLength):
            Rectangle(
                _topLeft,
                sideLength,
                sideLength
            ) {}
};

int main(){
    Point p1(0, 0);
    Point p2(3, 4);
    Point p3(6, 0);
    Point p4(9, 4);

    Line line(p1, p2);                  // Line 클래스를 line 변수로 받기 
    Triangle tri(p1, p2, p3);           // tri 변수 
    Quadrilateral quad(p1, p2, p3, p4);    // qued 변수

    std::cout << "Line length : " << line.length() << "\n";
    std::cout << "Triangle perimeter : " << tri.perimeter()<<"\n";
    std::cout << "Triangle area : " << tri.area() << "\n";
    std::cout << "Quadrilateral perimeter : " << quad.perimeter() << "\n";
    std::cout << "Quadrilateral area : " << quad.area() << "\n";

    // 삼각형
    EquilateralTriangle e_tri(Point(3, 2), 5);  // Point, side length
    IsoscelesTriangle i_tri(Point(0,0), 4, 5);  // Point, base length, side length
    ScaleneTriangle s_tri(p1, p2, p3);          // Point, Point, Point
    std::cout << "=============================" << "\n";
    std::cout << "Equilateral Triangle Area: " << e_tri.area() << "\n";
    std::cout << "Isosceles Triangle Area: " << i_tri.area() << "\n";
    std::cout << "Scalene Triangle Area: " << s_tri.area() << "\n";

    // 사각형 
    double height = 4.0;
    Rectangle rectangle(p1, height*2, height);
    Square square(p1, height);

    std::cout << "=============================" << "\n";
    std::cout << "Rectangle Area: " << rectangle.area() << "\n";
    std::cout << "Square Area: " << square.area() << "\n";
    return 0;
}
