#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

// Base class
class Point{
    protected:
        int x;
        int y;
    public:
        // Constructor
        Point(int _x, int _y) : x(_x), y(_y) {}
        // functions
        int getX() const { return x; }
        int getY() const { return y; }
        // Destructor
        ~Point() {}
};

// Features class
class Features : public Point {
    public:
        Features(int _x, int _y) : Point(_x, _y) {}

        double getDistance(const Point& p) const {
            int dx = p.getX() - x;
            int dy = p.getY() - y;
            return sqrt(dx*dx + dy*dy);
        }

        double getSlope(const Point& p) const {
            if (x == p.getX()){
                return numeric_limits<double>::infinity();
            }
            else{
                return (p.getY() - y) / (p.getX() - x);
            }
        }

        ~Features() {}
};

class Shape : public Features {
    public:
        Shape(int _x, int _y) : Features(_x, _y) {}

        void getShape(const Point& p1, const Point& p2, const Point& p3){
            double arr[3];
            arr[0] = Features::getSlope(p1);
            arr[1] = Features::getSlope(p2);
            arr[2] = Features::getSlope(p3);
            int is_same = 0;
            for (int i = 0; i < 3; i++){
                for (int j = i+1; j < 3; j++){
                    if (arr[i] == arr[j])
                    is_same++;
                }
            }
            if (is_same == 0){
                cout << "is Quadrilateral" << endl;
            }
            else if (is_same == 1){
                cout << "is Triangle" << endl;
            }
            else{
                cout << "is Line" << endl;
            }
        }

        ~Shape() {}
};

class Area : public Point {
    public:
        Area(int _x, int _y) : Point(_x, _y) {}
        // formula
        double getArea(const Point& p1, const Point& p2, const Point& p3) const {
            double area = 0.0;
            vector<Point> polygon = {p1, p2, p3};
            
            cout << "Calculate Area : " << endl;
        }

        ~Area() {} 
};

int main(void){
    Point p1(1, 1);
    Point p2(2, 0);
    Point p3(1, -1);

    Shape s1(0, 0);
    s1.getShape(p1, p2, p3);

    return 0;
}
