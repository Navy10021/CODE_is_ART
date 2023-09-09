#include <stdio.h>

class Shape{
    public:
        Shape(int x, int y);
        virtual void DrawSelf() = 0;
    protected:
        int x_pos;
        int y_pos;
};

// Shape를 상속
class Point : public Shape{
    public:
        Point(int x, int y) : Shape(x, y) {}
        void DrawSelf();
};

class Line : public Shape{
    public:
        Line(int x, int y) : Shape(x, y) {}
        void DrawSelf();
};

// 삼각형
class Triangle : public Shape{
    public:
        Triangle(int x, int y) : Shape(x, y) {}
        void DrawSelf();
};

// Triangle을 상속
class Equilateral : public Triangle{
    public:
        Equilateral(int x, int y) : Triangle(x, y) {}
        void DrawSelf();
};

class Isosceles : public Triangle{
    public:
        Isosceles(int x, int y) : Triangle(x, y) {}
        void DrawSelf();
};

class Scalene : public Triangle{
    public:
        Scalene(int x, int y) : Triangle(x, y) {}
        void DrawSelf();
};

class Quadrilateral : public Shape{
    public:
        Quadrilateral(int x, int y) : Shape(x, y){}
        void DrawSelf();
};

class Rectangle : public Quadrilateral{
    public:
        Rectangle(int x, int y) : Quadrilateral(x, y){}
        void DrawSelf();
};

class Square : public Quadrilateral{
    public:
        Square(int x, int y) : Quadrilateral(x, y){}
        void DrawSelf();
};


Shape::Shape(int x, int y){
    x_pos = x;
    y_pos = y;
}

void Point::DrawSelf(){
    printf("Draw Point at (%d, %d)\n", x_pos, y_pos);
}

void Line::DrawSelf(){
    printf("Draw Line at (%d, %d)\n", x_pos, y_pos);
}

void Triangle::DrawSelf(){
    printf("Draw Triangle at (%d, %d)\n", x_pos, y_pos);
}

void Equilateral::DrawSelf(){
    printf("Draw Equilateral at (%d, %d)\n", x_pos, y_pos);
}

void Isosceles::DrawSelf(){
    printf("Draw Isosceles at (%d, %d)\n", x_pos, y_pos);
}

void Scalene::DrawSelf(){
    printf("Draw Scalene at (%d, %d)\n", x_pos, y_pos);
}

void Quadrilateral::DrawSelf(){
    printf("Draw Quadrilateral at (%d, %d)\n", x_pos, y_pos);
}

void Rectangle::DrawSelf(){
    printf("Draw Rectangle at (%d, %d)\n", x_pos, y_pos);
}

void Square::DrawSelf(){
    printf("Draw Square at (%d, %d)\n", x_pos, y_pos);
}

