#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Base Class
class Storage {
protected:
    int iops;
    double hitRatio;
    char* model;  // Dynamic allocated memory for a model identifier

public:
    // Constructor with model
    Storage(int _iops, const char* _model) : iops(_iops), hitRatio(0.0) {
        model = new char[strlen(_model) + 1];
        strcpy(model, _model);
    }

    // Deep Copy Constructor
    Storage(const Storage& other) : iops(other.iops), hitRatio(other.hitRatio) {
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    virtual double calculateHitRatio() = 0; // pure virtual function

    virtual void printStatus() const {
        cout << "Model : " << model << ", IOPS: " << iops << ", Hit Ratio: " << hitRatio << "%" << endl;
    }

    // Deep Copy assignment operator 
    Storage& operator=(const Storage& other){
        if (this != &other){
            iops = other.iops;
            hitRatio = other.hitRatio;

            // Rellocate memory for the deep copy
            delete[] model;
            model = new char[strlen(other.model) + 1];
            strcpy(model, other.model);
        }
        return *this;
    }

    // Destructor
    virtual ~Storage() {
        delete[] model;
    }
};

// Derived Class
class HDD : public Storage{
public:
    // Constructor
    HDD(int _iops, const char* _model) : Storage(_iops, _model) {}
    // Methods
    double calculateHitRatio() override {
        hitRatio = (iops / 200.0) * 90;
        return hitRatio;
    }
};
// Derived Class-II
class SSD : public Storage {
public:
    // Constructor with model
    SSD(int _iops, const char* _model) : Storage(_iops, _model) {}

    // Implement calculateHitRatio for SSD
    double calculateHitRatio() override {
        hitRatio = (iops / 10.0) * 90;  // Example calculation
        return hitRatio;
    }
};

int main() {
    vector<Storage*> storage;
    HDD hdd1(150, "Samsung");
    SSD ssd1(500, "SKHynix");

    // Corrected: Using the objects directly, since they are stack-allocated
    HDD hdd2 = hdd1; // Deep copy
    SSD ssd2 = ssd1; // Deep copy

    // Storing pointers to the objects in the vector
    storage.push_back(&hdd1);
    storage.push_back(&ssd1);
    storage.push_back(&hdd2); // If you want to store hdd2 as well
    storage.push_back(&ssd2); // If you want to store ssd2 as well
    storage.push_back(new HDD(1000, "GSDS"));
    storage.push_back(new SSD(2000, "GSDS"));

    // Demonstrating polymorphism
    for (Storage* item : storage) {
        item->calculateHitRatio();
        item->printStatus();
    }

    return 0;
}
