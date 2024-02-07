#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Math{
    public:
        // Constructor 
        Math() {}
        // Two pure virtual functions
        virtual double calculate() const = 0;
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
    private:
        double radius;
    
    public:
        Geometry(double r) : radius(r) {}
        double calculate() const override{
            return radius * radius * M_PI;
        }
        
        string get_name() const override{
            return "Circle Area";
        }
    // Destructor
    ~ Geometry() {}
};

int main(void){
    QuadraticEquation qe(1, -5, 6);
    Geometry geo(3);
    
    cout << qe.get_name() << endl;
    cout << qe.calculate() << endl;
    cout << geo.get_name() << endl;
    cout << geo.calculate() << endl;
    
    return 0;
}

