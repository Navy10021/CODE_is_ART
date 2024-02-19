#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point {
protected:
    double x, y;

public:
    /* Attributor double x, y; */
    Point(double _x, double _y) : x(_x), y(_y) {}

    /* Accessors */
    double getX() const { return x; }
    double getY() const { return y; }
};

class Features : public Point {
public:
    Features(double _x, double _y) : Point(_x, _y) {}

    double getSlope(const Point& p) const {
        if (x == p.getX()) {
            return INFINITY;
        } else {
            return (p.getY() - y) / (p.getX() - x);
        }
    }

    double getDistance(const Point& p) const {
        return sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2));
    }
};

class Shape : public Features {
public:
    Shape(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4)
            : Features(_x1, _y1), p2(_x2, _y2), p3(_x3, _y3), p4(_x4, _y4) {}

    string getShape() const {
        double slope1 = getSlope(p2);
        double slope2 = getSlope(p3);
        double slope3 = getSlope(p4);

        if (slope1 == slope2 && slope2 == slope3) {
            return "Line";
        } else if (slope1 == slope2 || slope1 == slope3 || slope2 == slope3) {
            return "Triangle";
        } else {
            return "Quadrilateral";
        }
    }

private:
    Features p2, p3, p4;
};

class Area : public Point {
public:
    Area(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4)
            : Point(_x1, _y1), p2(_x2, _y2), p3(_x3, _y3), p4(_x4, _y4) {}

    double getArea() const {
        Shape shape(getX(), getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY(), p4.getX(), p4.getY());
        string shapeType = shape.getShape();

        if (shapeType == "Line") {
            return 0;
        } else {
            double area = 0.5 * fabs((getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p4.getY() + p4.getX() * getY()) -
                                    (p2.getX() * getY() + p3.getX() * p2.getY() + p4.getX() * p3.getY() + getX() * p4.getY()));
            return area;
        }
    }


private:
    Features p2, p3, p4;
};

int main() {
    //Point p2(2,2);
    //double ans = Features(1,1).getSlope(p2);
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "Enter x and y coordinates of four points: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Shape shape(x1, y1, x2, y2, x3, y3, x4, y4);
    Area area(x1, y1, x2, y2, x3, y3, x4, y4);

    cout << "Shape formed by the points: " << shape.getShape() << endl;
    cout << "Area between the points: " << area.getArea() << endl;
    //cout << "ans: " << ans << endl;

    return 0;
}
