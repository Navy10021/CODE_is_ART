#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Math{
    public:
        // Constructor 
        Math() {}
        // Two pure virtual functions
        virtual double calculate() const = 0; // pure virtual function은 모두 만들어야함. 
        virtual string get_name() const = 0;
        // Virtual Destructor is important for base class
        virtual ~Math() {}
};

class Algebra : public Math{
    protected:
        double a;
        double b;
    
    public:
        // Constructor with initialization a and b 
        Algebra(double _a, double _b) : a(_a), b(_b) {} 
        
        double calculate() const override {
            return (-b) / a;
        }
        
        string get_name() const override{
            return "Algebra";
        }
        // Destructor
        ~ Algebra() {}
};

class QuadraticEquation : public Algebra{
    private:
        double c;
    
    public:
        QuadraticEquation(double _a, double _b, double _c) : Algebra(_a, _b), c(_c) {}
        
        double calculate() const override {
            double discriminant = (b * b)  - (4 * a * c);
            
            if (discriminant < 0){
                cout << "No real roots." << endl;
                return 0;
            }
            return (-b + sqrt(discriminant)) / (2 * a);
        }
        
        string get_name() const override{
            return "Quadratic Equation";
        }
        // Destructor
        ~ QuadraticEquation() {}
};

class Geometry : public Math{
    protected:
        double radius;
    
    public:
        Geometry(double r) : radius(r) {}
        double calculate() const override{
            return radius * radius * 3.14159;
        }
        
        string get_name() const override{
            return "Geometry";
        }
    // Destructor
    ~ Geometry() {}
};

class CircleArea : public Geometry{
    public:
        CircleArea(double r) : Geometry(r) {}
        double calculate() const override{
            return Geometry::calculate();
        }
        string get_name() const override{
            return "Circle Area";
        }
};

int main(void){
    //QuadraticEquation qe(1, -5, 6);
    //Algebra al(3, 4);
    Geometry geo(3);
    CircleArea c(5);
    
    cout << geo.get_name() << endl;
    cout << geo.calculate() << endl;
    cout << c.get_name() << endl;
    cout << c.calculate() << endl;
    
    return 0;
}
