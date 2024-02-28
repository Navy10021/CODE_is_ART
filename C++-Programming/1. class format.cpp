#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Base Class 
class Base{
    // Attricuts : force 
    protected:
        double force;
        
    public:
        // Constructor 
        Base(double _force)
            : force(_force) {} 
        // Destructor
        virtual ~Base() {};
        
        // Methods
        virtual void display(){
            cout << "Force : " << force << endl;
        }
        virtual void displayDetails() = 0; // pure virtual
};


// Drived Class 
class Drived : public Base{
    //
}