#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Base Class 
class Force{
    // Attribute : force 
    protected:
        double force;
        
    public:
        // Constructor 
        Force(double _force)
            : force(_force) {} 
        // Destructor
        virtual ~Force() {};
        
        // Methods
        virtual void display(){
            cout << "Force : " << force << endl;
        }
        virtual void displayDetails() = 0; // pure virtual
};


// Drived Class 
class LinearMotion : public Force{
    // member variables : mass, acceleration
    protected:
        double mass;
        double acceleration;
    
    public:
        // Constructor
        LinearMotion(double _m, double _acc)
            : Force(force), mass(_m), acceleration(_acc){
                calForce();
            }
        
        void calForce(){
            force = mass * acceleration;
        }
        
        void displayDetails() override{
            cout << "This is Linear Force Motion, ";
            Force::display();
        }
};

class AcceleratedMotion : public LinearMotion{
    private:
        double velocity;
        double time; 
    
    public:
        // Constructor
        AcceleratedMotion(double _m, double _v, double _t)
            : LinearMotion(_m, acceleration), velocity(_v), time(_t){
                calAcceleration();
                calForce();
            }
        
        void calForce(){
            LinearMotion::calForce();
        }
        
        void calAcceleration(){
            acceleration = velocity / time;
        }
        
        void displayDetails() override{
            cout << "This is Accelerated Force Motion, ";
            Force::display();
        }
};

class ProjectileMotion : public Force{
    private:
        double mass;
        double angle;
        double acceleration;
    public:
        // Constructor
        ProjectileMotion(double _m, double _a)
            : Force(force), mass(_m), angle(_a){
                acceleration = 9.8 * sin(angle);
                calForce();
            }
            
        void calForce(){
            force = mass * acceleration;
        }
        
        void displayDetails() override{
            cout << "This is Projectile Force Motion, ";
            Force::display();
        }
};

class CentripetalForceMotion : public Force{
    private:
        double mass;
        double velocity;
        double radius;
    public:
        CentripetalForceMotion(double _m, double _v, double _r)
            : Force(force), mass(_m), velocity(_v), radius(_r){
                calForce();
            }
            
        void calForce(){
            force = mass * (velocity*velocity) / radius;
        }
        
        void displayDetails() override{
            cout << "This is Centripetal Force Motion, ";
            Force::display();
        }
};

int main(void){
    vector<Force*> forces;
    forces.push_back(new LinearMotion(10, 5));
    forces.push_back(new AcceleratedMotion(10, 10, 5));
    forces.push_back(new ProjectileMotion(10, 270));
    forces.push_back(new CentripetalForceMotion(10, 10, 5));
    
    // Display 
    for (auto & f : forces){
        f->displayDetails();
    }
    
    // Clean up 
    for (auto & f : forces){
        delete f;
    }
    forces.clear();
    
    return 0;
}