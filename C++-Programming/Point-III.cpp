#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return this->x == other.x && this->y == other.y;
    }

    double slope(const Point& other) const {
        if (this->x == other.x) {
            if (this->y == other.y) {
                return -1e9;  // 두 점이 같은 경우
            }
            return 1e9;  // "무한대" 기울기를 대표하는 값 (수직)
        }
        return (double)(other.y - this->y) / (other.x - this->x);
    }
};

class Figure {
public:
    Point p1, p2, p3, p4;
    bool isQuadrilateral; // 네 번째 점을 사용하는지 여부

    // 세 점으로 생성된 도형 생성자
    Figure(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3), isQuadrilateral(false) {}
    // 네 점으로 생성된 도형 생성자
    Figure(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4), isQuadrilateral(true) {}

    string determineShape() const {
        if (!isQuadrilateral) {
            if (p1 == p2 && p2 == p3) {
                return "Point";
            }

            double slope1 = p1.slope(p2);
            double slope2 = p2.slope(p3);

            if (slope1 == slope2) {
                return "Line";
            }
            return "Triangle";
        }
        else {
            return "Rectangle";
        }
    }

    double get_distance(const Point& first, const Point& second) const {
        double result = sqrt(pow((first.x - second.x), 2) + pow((first.y - second.y), 2));
        return result;
    }

    virtual double calculateArea() = 0;
    virtual void printInfo() {
        string shapeType = determineShape();
        cout << "The shape is a: " << shapeType << endl;
    }
};

class Triangle : public Figure {
public:
    using Figure::Figure;

    double calculateArea() override {
        double area = 0.5 * abs(
            p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y)
        );
        return area;
    }

    void printInfo() {
        Figure::printInfo();
        if (Figure::determineShape() == "Triangle") {
            cout << "The area of the triangle is: " << calculateArea() << endl;
        }
    }
};

class Rectangle : public Figure {
public:
    using Figure::Figure;

    double calculateArea() override {
        return get_distance(p1, p2) * get_distance(p2, p3);
    }
    void printInfo() {
        Figure::printInfo();
        if (Figure::determineShape() == "Rectangle") {
            cout << "The area of the rectangle is: " << calculateArea() << endl;
        }
    }
};


class Line : public Figure {
public:
    using Figure::Figure;

    double calculateArea() override {
        return 0;  // 선분의 면적은 0
    }
};


int main() {
    Triangle tri(Point(0, 0), Point(1, 0), Point(1, 8));
    tri.printInfo();

    Line line(Point(0, 0), Point(1, 1), Point(2, 2));
    line.printInfo();

    Rectangle rect(Point(0, 0), Point(4, 0), Point(4, 5), Point(0, 5));
    rect.printInfo();

    return 0;
}
