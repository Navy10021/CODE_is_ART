#include <iostream>
#include <string>
using namespace std;

// Base class for all electronic devices
class ElectronicDevice {
protected:
    string brand;
    int basePrice;

public:
    ElectronicDevice(string brand, int basePrice) : brand(brand), basePrice(basePrice) {}

    virtual int calculatePrice() const = 0;

    virtual void displayInfo() const = 0;

    virtual ~ElectronicDevice() {}
};

// Derived class for Smartphones
class Smartphone : public ElectronicDevice {
protected:
    int storageCapacity; // in GB

public:
    Smartphone(string brand, int basePrice, int storageCapacity)
        : ElectronicDevice(brand, basePrice), storageCapacity(storageCapacity) {}

    int calculatePrice() const override {
        return basePrice + storageCapacity * 10;
    }

    void displayInfo() const override {
        cout << "Smartphone: " << brand << ", Storage: " << storageCapacity << "GB, Price: $" << calculatePrice() << endl;
    }
};

// Derived class for Tablets
class Tablet : public ElectronicDevice {
private:
    int screenSize; // in inches

public:
    Tablet(string brand, int basePrice, int screenSize)
        : ElectronicDevice(brand, basePrice), screenSize(screenSize) {}

    int calculatePrice() const override {
        return basePrice + screenSize * 20;
    }

    void displayInfo() const override {
        cout << "Tablet: " << brand << ", Screen Size: " << screenSize << "\", Price: $" << calculatePrice() << endl;
    }
};

// Derived class for SmartWatches
class SmartWatch : public ElectronicDevice {
private:
    bool hasGPS;

public:
    SmartWatch(string brand, int basePrice, bool hasGPS)
        : ElectronicDevice(brand, basePrice), hasGPS(hasGPS) {}

    int calculatePrice() const override {
        return basePrice + (hasGPS ? 50 : 0);
    }

    void displayInfo() const override {
        cout << "SmartWatch: " << brand << ", GPS: " << (hasGPS ? "Yes" : "No") << ", Price: $" << calculatePrice() << endl;
    }
};

// Camera class for composition in EnhancedSmartphone!
class Camera {
private:
    int megapixels;

public:
    Camera(int megapixels) : megapixels(megapixels) {}

    int getQualityScore() const {
        return megapixels * 2;
    }
};

// EnhancedSmartphone class demonstrating composition
class EnhancedSmartphone : public Smartphone {
private:
    Camera camera;

public:
    EnhancedSmartphone(string brand, int basePrice, int storageCapacity, int cameraMegapixels)
        : Smartphone(brand, basePrice, storageCapacity), camera(cameraMegapixels) {}

    int calculatePrice() const override {
        return Smartphone::calculatePrice() + camera.getQualityScore();
    }

    void displayInfo() const override {
        cout << "Enhanced Smartphone: " << brand << ", Storage: " << storageCapacity << "GB, Camera Quality Score: " << camera.getQualityScore() << ", Price: $" << calculatePrice() << endl;
    }
};

// Main function to demonstrate the usage
int main() {
    Smartphone myPhone("Galaxy", 500, 128);
    Tablet myTablet("iPad", 600, 10);
    SmartWatch myWatch("Fitbit", 200, true);
    EnhancedSmartphone myEnhancedPhone("Pixel", 700, 256, 12);

    myPhone.displayInfo();
    myTablet.displayInfo();
    myWatch.displayInfo();
    myEnhancedPhone.displayInfo();

    return 0;
}
