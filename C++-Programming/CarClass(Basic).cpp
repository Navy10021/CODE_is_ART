#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
        ACC_STEP = 10, BRK_STEP = 10
    };
}

class Car{
    private:
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    
    public:
        void InitMembers(const char* ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

void Car::InitMembers(const char* ID, int fuel){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState(){
    cout << "ID :" << gamerID << endl;
    cout << "Fuel volume : " << fuelGauge << endl;
    cout << "Current speed : " << curSpeed << endl;
}

void Car::Accel(){
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;
    
    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
    if (curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

// Main
int main(void){
    Car run77;      // Object
    run77.InitMembers("Run77", 100);
    run77.Accel();
    run77.Accel();
    run77.Accel();
    run77.ShowCarState();

    run77.Break();
    run77.ShowCarState();

    return 0;
}
