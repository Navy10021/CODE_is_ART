#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.1415
using namespace std;

// Base Class
class Motion {
    // Attributs : distance, motion types
    protected:
        double distance;
        string type;

    public:
        // Constructor
        Motion(double _distance, string _type)
            : distance(_distance), type(_type) {}
        // Destructor
        virtual ~Motion() {};

        // Methods
        virtual void calcFinalVelocity() = 0; // pure virtual function
        virtual void getDescription() {
            cout << "Type : " << type;
            cout << "Distance : " << getDistance() << endl;
        }
        double getDistance(){
            return distance;
        }
};


// Derived Class
class VelocityTimeMotion : public Motion{
    private:
        double time;
        double velocity;
    
    public:
        VelocityTimeMotion(double _distance, string _type, double t, double v)
            : Motion(_distance, _type), time(t), velocity(v){
                calcFinalVelocity();
                calcDistance();
            }

        void getDescription() override{
            Motion::getDescription();
            cout << "Finial Velocity : " << velocity << endl;
        }

        void calcFinalVelocity() override{
            velocity = velocity;
        }

        void calcDistance() {
            distance = time * velocity;
        }  
};

class AcceleratedMotion : public Motion{
    private:
        double time;
        double velocity;
        double acceleration;
    
    public:
        AcceleratedMotion(double _distance, string _type, double t, double v, double a)
            : Motion(_distance, _type), time(t), velocity(v), acceleration(a){
                calcFinalVelocity();
                calcDistance();
            }

        void getDescription() override{
            Motion::getDescription();
            cout << "Finial Velocity : " << velocity << endl;
        }

        void calcFinalVelocity() override{
            velocity = velocity + (acceleration * time);
        }

        void calcDistance() {
            distance = (time * velocity) + (0.5 * acceleration * time * time);
        }  
};

class ProjectileMotion : public Motion {
    private:
        double velocity;
        double angle;

    public:
        ProjectileMotion(double _distance, string _type, double v, double theta)
            : Motion(_distance, _type), velocity(v), angle(theta){
                calcFinalVelocity();
                calcDistance();
            }

        void getDescription() override{
            Motion::getDescription();
            cout << "Finial Velocity : " << velocity << endl;
        }
    
        // Check!
        void calcFinalVelocity() override {
            velocity = velocity;
        }

        void calcDistance() {
            double radians = angle * (PI / 180.0);
            distance = (velocity * velocity) * sin(2*radians) / 9.8; 
        }  
};

class CircularMotion : public Motion {
    private:
        double velocity;
        double radius;
        double speed;
    
    public:
        CircularMotion(double _distance, string _type, double s, double r)
            : Motion(_distance, _type), radius(r), speed(s){
                calcFinalVelocity();
                calcDistance();
            }

        void getDescription() override{
            Motion::getDescription();
            cout << "Finial Velocity : " << velocity << endl;
        }

        void calcFinalVelocity() override {
            velocity = speed;
        }

        void calcDistance() {
            distance = 2 * PI * radius; 
        }  
};

int main(void){
    vector<Motion*> motions;
    motions.push_back(new VelocityTimeMotion(0, "Velocity-based", 10, 100));
    motions.push_back(new AcceleratedMotion(0, "Accelerated-based", 10, 100, 10));
    motions.push_back(new ProjectileMotion(0, "Project-based", 100, 180));
    motions.push_back(new CircularMotion(0, "Circular-based", 100, 5));

    for (auto & m : motions){
        m->getDescription();
    }    

    // Clean UP
    for (auto & m : motions){
        delete m;
    }
    motions.clear();

    return 0;
}
