#include <iostream>
#include <cmath>

class Point{
    private:
        double x, y;
    
    public:
        Point(double _x, double _y) : x(_x), y(_y) {}   

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

    return 0;
}
