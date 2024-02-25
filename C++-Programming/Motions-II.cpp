#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Motion {
protected:
    double distance;

public:
    Motion(double d) : distance(d) {}

    virtual double calcFinalVelocity() const = 0;
    virtual string getDescription() const { return "Generic Motion"; } 
    // 사실상 Motion의 instance가 생성이 불가하므로, 위의 method는 사용될 일이 없다.
    // 다만, 하위 class에서 getDescription을 override 하지 않았을 경우, Generic Motion이 return 될 것이다.

    double getDistance() const { return distance; }
};

class VelocityTimeMotion : public Motion {
private:
    double time;           // Time in seconds
    double initialVelocity; // Initial velocity in m/s

public:
    VelocityTimeMotion(double t, double v) : Motion(v*t), time(t), initialVelocity(v) {}

    double calcFinalVelocity() const override {
        return initialVelocity;  // Velocity remains constant in uniform motion
    }

    string getDescription() const override { return "Velocity-Time Motion"; }
};

class AcceleratedMotion : public Motion {
private:
    double time;           // Time in seconds
    double initialVelocity; // Initial velocity in m/s
    double acceleration;   // Acceleration in m/s^2

public:
    AcceleratedMotion(double t, double v, double a) : Motion(v* t + 0.5 * a * pow(t, 2)), time(t), initialVelocity(v), acceleration(a) {}

    double calcFinalVelocity() const override {
        return initialVelocity + acceleration * time;  // Final velocity after acceleration
    }

    string getDescription() const override { return "Accelerated Motion"; }
};

class ProjectileMotion : public Motion {
private:
    double initialVelocity; // Initial velocity in m/s
    double angle;           // Projection angle in degrees

public:
    //ProjectileMotion(double v, double a) : Motion(0), initialVelocity(v), angle(a) {
    //    distance = (pow(initialVelocity, 2) * sin(2 * (angle * 3.14 / 180))) / 9.8; // Range of the projectile
    //} 위와 같은 case에서도 정상적으로 작동을 하게 됨
    ProjectileMotion(double v, double a) : Motion((pow(v, 2)* sin(2 * (a * 3.14 / 180))) / 9.8), initialVelocity(v), angle(a) {}

    double calcFinalVelocity() const override {
        // Simplification for demonstration purposes
        return initialVelocity;
    }

    string getDescription() const override { return "Projectile Motion"; }
};

class CircularMotion : public Motion {
private:
    double radius; // Radius of the circular path in meters
    double speed;  // Constant speed in m/s

public:
    CircularMotion(double r, double s) : Motion(2 * 3.14 * r), radius(r), speed(s) {}

    double calcFinalVelocity() const override {
        return speed; // Speed remains constant in circular motion
    }

    string getDescription() const override { return "Circular Motion"; }
};


int main() {
    // VelocityTimeMotion : 100m
    double time = 5.0, velocity = 20.0;
    VelocityTimeMotion vtm(time, velocity);
    cout << vtm.getDescription() << " - Distance: " << vtm.getDistance() << " m\n";

    // AcceleratedMotion
    double acceleration = 2.0;
    AcceleratedMotion am(time, velocity, acceleration);
    cout << am.getDescription() << " - Distance: " << am.getDistance() << " m, Final Velocity: " << am.calcFinalVelocity() << " m/s\n";

    // ProjectileMotion
    double initialVelocity = 30.0, angle = 45.0;
    ProjectileMotion pm(initialVelocity, angle);
    cout << pm.getDescription() << " - Distance: " << pm.getDistance() << " m\n";

    // CircularMotion
    double radius = 10.0, speed = 5.0;
    CircularMotion cm(radius, speed);
    cout << cm.getDescription() << " - Distance (one full loop): " << cm.getDistance() << " m, Final Velocity: " << cm.calcFinalVelocity() << " m/s\n";

    return 0;
}
