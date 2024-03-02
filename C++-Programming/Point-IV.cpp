#include <iostream>

using namespace std; // std 네임스페이스 사용 선언

// 'Point' 클래스 선언
class Point {
public:
    double x, y; // x, y 좌표를 나타내는 멤버 변수

    // 생성자: x, y 좌표를 초기화 (기본값 0, 0)
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // 다른 점까지의 거리를 계산하는 함수
    double distanceTo(const Point& other) const {
        double dx = x - other.x; // x 좌표 차이
        double dy = y - other.y; // y 좌표 차이
        return naiveSqrt(dx * dx + dy * dy); // 유클리드 거리 공식
    }

    // 제곱근을 간단히 계산하는 함수
    double naiveSqrt(double value) const {
        if (value == 0 || value == 1) return value; // 0 또는 1인 경우 바로 반환
        double start = 0, end = value, result;
        while (start <= end) {
            double mid = (start + end) / 2;
            if (mid * mid == value) return mid; // 정확한 제곱근 찾음
            if (mid * mid < value) {
                start = mid + 0.0001;
                result = mid;
            }
            else {
                end = mid - 0.0001;
            }
        }
        return result; // 근사값 반환
    }
};

// 'Shape' 클래스 선언
class Shape : public Point {
private:
    Point points[4]; // 도형을 구성하는 최대 4개의 점
    int pointCount; // 사용된 점의 개수

public:
    // 생성자 오버로딩: 2점, 3점, 4점으로 도형 생성
    Shape(Point p1, Point p2) : pointCount(2) {
        points[0] = p1; points[1] = p2;
    }
    Shape(Point p1, Point p2, Point p3) : pointCount(3) {
        points[0] = p1; points[1] = p2; points[2] = p3;
    }
    Shape(Point p1, Point p2, Point p3, Point p4) : pointCount(4) {
        points[0] = p1; points[1] = p2; points[2] = p3; points[3] = p4;
    }

    // 도형의 둘레를 계산하는 함수
    double perimeter() const {
        double result = 0;
        for (int i = 0; i < pointCount; ++i) {
            result += points[i].distanceTo(points[(i + 1) % pointCount]);
        }
        return result; // 총 둘레 반환
    }

    // 도형의 넓이를 계산하는 함수
    double area() const {
        if (pointCount == 2) {
            return 0; // 선분의 넓이는 0
        }
        else if (pointCount == 3) {
            // 삼각형의 넓이 계산 (헤론의 공식 사용)
            double a = points[0].distanceTo(points[1]);
            double b = points[1].distanceTo(points[2]);
            double c = points[2].distanceTo(points[0]);
            double s = (a + b + c) / 2;
            return naiveSqrt(s * (s - a) * (s - b) * (s - c));
        }
        else if (pointCount == 4) {
            // 사각형의 넓이 계산 (직사각형 가정)
            double width = points[0].distanceTo(points[1]);
            double height = points[1].distanceTo(points[2]);
            return width * height;
        }
        return 0; // 그 외 경우는 0 반환
    }
};

int main() {
    // 점 객체 생성
    Point p1(0, 0), p2(3, 0), p3(3, 4), p4(0, 4);

    // 도형 객체 생성
    Shape line(p1, p2);
    Shape triangle(p1, p2, p3);
    Shape rectangle(p1, p2, p3, p4);

    // 도형의 둘레와 넓이 출력
    cout << "Line length: " << line.perimeter() << endl;
    cout << "Triangle perimeter: " << triangle.perimeter() << ", area: " << triangle.area() << endl;
    cout << "Rectangle perimeter: " << rectangle.perimeter() << ", area: " << rectangle.area() << endl;

    return 0;
}
