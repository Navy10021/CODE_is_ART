#include <iostream>
#include <cstring>
#include <vector>
#include <string> // Include for std::string

using namespace std;

// Base Class
class Storage {
protected:
    int iops;
    double hitRatio;
    string model;  // Use std::string for model identifier

public:
    // Constructor with model using std::string
    Storage(int _iops, const string& _model) : iops(_iops), hitRatio(0.0), model(_model) {}

    // The default copy constructor and copy assignment operator are fine now
    // No need for a custom destructor

    virtual double calculateHitRatio() = 0; // pure virtual function

    virtual void printStatus() const {
        cout << "Model : " << model << ", IOPS: " << iops << ", Hit Ratio: " << hitRatio << "%" << endl;
    }

    // Destructor is not needed now as std::string manages its own memory
    virtual ~Storage() {}
};

// Derived Class for HDD
class HDD : public Storage {
public:
    HDD(int _iops, const string& _model) : Storage(_iops, _model) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 200.0) * 90;
        return hitRatio;
    }
};

// Derived Class for SSD
class SSD : public Storage {
public:
    SSD(int _iops, const string& _model) : Storage(_iops, _model) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 10.0) * 90;
        return hitRatio;
    }
};

int main() {
    vector<Storage*> storage;
    HDD hhd1 = HDD(150, "Samsung");
    HDD hhd2 = hhd1;
    SSD ssd1 = SSD(200, "SKhynix");
    SSD ssd2 = ssd1;

    storage.push_back(&hhd1);
    storage.push_back(&hhd2);
    storage.push_back(&ssd1);
    storage.push_back(&ssd2);
    /*
    storage.push_back(new HDD(150, "Samsung"));
    storage.push_back(new SSD(500, "SKHynix"));
    */
    // Demonstrating polymorphism
    for (Storage* item : storage) {
        item->calculateHitRatio();
        item->printStatus();
    }

    // Cleanup dynamically allocated objects
    for (Storage* item : storage) {
        delete item;
    }
    storage.clear();

    return 0;
}
