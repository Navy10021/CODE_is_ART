#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper function to convert memory sizes
int convertToBytes(int size, const string& unit) {
    if (unit == "KB") return size * 1024;
    if (unit == "MB") return size * 1024 * 1024;
    if (unit == "GB") return size * 1024 * 1024 * 1024;
    if (unit == "TB") return (size * 1024L) * (1024L * 1024L * 1024L);
    return size; // Bytes by default
}

// Base class for components
class Component {
public:
    virtual void print_info() = 0; // Pure virtual function for polymorphism
    virtual ~Component() {}; // Virtual destructor for cleanup
};

// Derived class for CPU
class CPU : public Component {
public:
    int frequency;
    double clock;

    CPU(int _frequency, double _clock) : frequency(_frequency), clock(_clock) {};

    void print_info() override {
        cout << "CPU Frequency: " << frequency << "MHz, Clock Speed: " << clock << "GHz" << endl;
    };

    double effectiveSpeed() {
        return frequency * clock;
    }

    ~CPU() {};
};

// Derived class for storage devices from Component
class StorageDevice : public Component {
public:
    int size;

    StorageDevice(int _size) : size(_size) {}

    // The print_info is still pure virtual, as we want to enforce that derived storage classes implement it
    virtual void print_info() = 0;

    virtual void readData() {
        cout << "Reading data from storage device." << endl;
    }

    virtual void writeData() {
        cout << "Writing data to storage device." << endl;
    }

    virtual ~StorageDevice() {}
};

// Derived class for RAM from StorageDevice
class RAM : public StorageDevice {
public:
    int bit;
    int cell;

    RAM(int _size, int _bit, int _cell) : StorageDevice(_size), bit(_bit), cell(_cell) {}

    void print_info() override {
        cout << "RAM: " << size << "GB, Bit: " << bit << ", Cell Capacity: " << cell << " per bit" << endl;
    };

    ~RAM() {}
};

// Derived class for Cache from StorageDevice
class Cache : public StorageDevice {
public:
    Cache(int _size) : StorageDevice(_size) {}

    void print_info() override {
        cout << "Cache Size: " << size << "KB" << endl;
    };

    ~Cache() {}
};

// Derived class for Magnetic Disk from StorageDevice
class MagneticDisk : public StorageDevice {
public:
    MagneticDisk(int _size) : StorageDevice(_size) {}

    void print_info() override {
        cout << "Magnetic Disk Storage: " << size << "TB" << endl;
    };

    ~MagneticDisk() {}
};

// Derived class for Tape from StorageDevice
class Tape : public StorageDevice {
public:
    Tape(int _size) : StorageDevice(_size) {}

    void print_info() override {
        cout << "Tape Capacity: " << size << "TB" << endl;
    };

    ~Tape() {}
};

// PC class that contains CPU and Storage Devices
class PC {
private:
    CPU* cpu;
    vector<StorageDevice*> storageDevices;

public:
    PC(CPU* _cpu) : cpu(_cpu) {}

    void addStorageDevice(StorageDevice* device) {
        storageDevices.push_back(device);
        cout << "Added a new storage device." << endl;
        device->print_info();
    }

    void print_info() {
        cpu->print_info();
        for (auto& device : storageDevices) {
            device->print_info();
        }
    }

    ~PC() {
        delete cpu; // Clean up CPU
        for (auto& device : storageDevices) {
            delete device; // Clean up storage devices
        }
    }
};

int main() {
    // Instantiate components
    CPU* myCPU = new CPU(3400, 3.4); // Frequency in MHz, clock speed in GHz
    RAM* myRAM = new RAM(8, 64, 1); // Memory in GB, bit size, cell capacity
    Cache* myCache = new Cache(256); // Cache size in KB
    MagneticDisk* myDisk = new MagneticDisk(1); // Storage in TB
    Tape* myTape = new Tape(10); // Capacity in TB

    // Create a PC and add components
    PC myPC(myCPU);
    myPC.addStorageDevice(myRAM);
    myPC.addStorageDevice(myCache);
    myPC.addStorageDevice(myDisk);
    myPC.addStorageDevice(myTape);

    // Print PC info
    myPC.print_info();

    return 0;
}
