#include <iostream>
#include <cstring>

using namespace std;

class Shape{
    public:
        virtual double Area() const{
            cout << "Area of the base Shape class\n";
            return 0.0;
        }
};

class Circle : public Shape{
    private:
        double radius;
    
    public:
        Circle(double r) : radius(r) {}

        // Override
        double Area() const override {
            cout << "Area of the Circle\n";
            return 3.14 * radius * radius;
        }
};

class Rectangle : public Shape {
    private:
        double length;
        double width;
    
    public:
        Rectangle(double L, double W) : length(L), width(W) {}

        // Override
        double Area() const override{
            cout << "Area of the Rectangle\n";
            return length * width;
        }

        double Perimeter() const{
            cout << "Perimeter of the Rectangle\n";
            return 2 * (length + width);
        }
};

int main(){
    // 상속에 따라 Shape 공동 매개 가능
    // Example of virtual function and polymorphism
    Shape * shape1 = new Circle(5.0);
    Shape * shape2 = new Rectangle(4.0, 6.0);

    // Calls the appropriate overridden function based on the actual object type
    cout << "Area of Shape 1 :" << shape1->Area() << endl;
    cout << "Area of Shape 2 :" << shape2->Area() << endl;
    //cout << "Perimeter of rectangle : " << shape2->Perimeter() << endl;  -> 컴파일 에러 : Shape Class에서 정의된 가상함수만 접근!

    Rectangle rec(3.0, 4.0);
    cout << "Area of Rectangle : " << rec.Area() << endl;
    cout << "Perimeter of rectangle : " << rec.Perimeter() << endl;

    delete shape1;
    delete shape2;

    return 0;
}

