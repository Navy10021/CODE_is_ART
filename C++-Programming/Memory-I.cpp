#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Base Class
class Storage {
protected:
    int iops;
    double hitRatio;

public:
    // Constructor
    Storage(int _iops) : iops(_iops), hitRatio(0.0) {}

    // Deep Copy Constructor
    Storage(const Storage& other) : iops(other.iops), hitRatio(other.hitRatio) {}

    virtual double calculateHitRatio() = 0; // pure virtual function

    virtual void printStatus() const {
        cout << "IOPS: " << iops << ", Hit Ratio: " << hitRatio << "%" << endl;
    }
    // Destructor
    virtual ~Storage() {}
};

// Drived Class
class MechanicalDrive : public Storage {
public:
    MechanicalDrive(int _iops) : Storage(_iops) {}
    MechanicalDrive(const MechanicalDrive& other) : Storage(other) {}
    virtual ~MechanicalDrive() {}
};

// Drived Class-II
class SolidStateDrive : public Storage {
public:
    SolidStateDrive(int _iops) : Storage(_iops) {}
    SolidStateDrive(const SolidStateDrive& other) : Storage(other) {}
    virtual ~SolidStateDrive() {}
};


class HDD : public MechanicalDrive {
public:
    HDD(int _iops) : MechanicalDrive(_iops) {}
    HDD(const HDD& other) : MechanicalDrive(other) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 200.0) * 90;
        return hitRatio;
    }
};


class SSD : public SolidStateDrive {
public:
    SSD(int _iops) : SolidStateDrive(_iops) {}
    SSD(const SSD& other) : SolidStateDrive(other) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 10.0) * 90;
        return hitRatio;
    }
};


class RAM : public Storage {
public:
    RAM(int _iops) : Storage(_iops) {}
    RAM(const RAM& other) : Storage(other) {}

    double calculateHitRatio() override {
        hitRatio = 100.0; 
        return hitRatio;
    }
};


class ROM : public Storage {
public:
    ROM(int _iops) : Storage(_iops) {}
    ROM(const ROM& other) : Storage(other) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 300.0) * 90;
        return hitRatio;
    }
};


class Cache : public Storage {
public:
    Cache(int _iops) : Storage(_iops) {}
    Cache(const Cache& other) : Storage(other) {}

    double calculateHitRatio() override {
        hitRatio = 95.0; 
        return hitRatio;
    }
};


class OpticalDrive : public Storage {
public:
    OpticalDrive(int _iops) : Storage(iops) {}
    OpticalDrive(const OpticalDrive& other) : Storage(other) {}

    double calculateHitRatio() override {
        hitRatio = (iops / 500.0) * 90; 
        return hitRatio;
    }
};


int main() {
    vector<unique_ptr<Storage>> storageDevices;

    
    storageDevices.push_back(make_unique<HDD>(150));
    storageDevices.push_back(make_unique<SSD>(3000));
    auto ramOriginal = make_unique<RAM>(50000);
    storageDevices.push_back(move(ramOriginal)); 
    storageDevices.push_back(make_unique<ROM>(100));
    storageDevices.push_back(make_unique<Cache>(4500));
    storageDevices.push_back(make_unique<OpticalDrive>(50));

    
    if (!storageDevices.empty()) { 
        auto ramCopy = make_unique<RAM>(*static_cast<RAM*>(storageDevices.back().get()));
        storageDevices.push_back(move(ramCopy));
    }

    
    RAM* originalRAM = new RAM(50000);
    RAM* copiedRAM = new RAM(*originalRAM);

    originalRAM->calculateHitRatio();
    copiedRAM->calculateHitRatio();

    originalRAM->printStatus();
    copiedRAM->printStatus();

    delete originalRAM;
    delete copiedRAM;

    for (auto& device : storageDevices) {
        device->calculateHitRatio();
        device->printStatus();
    }

    return 0;
}
