#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    string id;
    string make;
    string model;
    int year;
    bool isAvailable;

public:
    Vehicle(string id, string make, string model, int year)
        : id(id), make(make), model(model), year(year), isAvailable(true) {}

    virtual void displayDetails() const {
        cout << "Vehicle ID: " << id << ", Make: " << make
             << ", Model: " << model << ", Year: " << year << endl;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

    const string& getId() const {
        return id;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int seatCount;

public:
    Car(string id, string make, string model, int year, int seatCount)
        : Vehicle(id, make, model, year), seatCount(seatCount) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Seats: " << seatCount << endl;
    }
};

class Motorcycle : public Vehicle {
    bool hasSidecar;

public:
    Motorcycle(string id, string make, string model, int year, bool hasSidecar)
        : Vehicle(id, make, model, year), hasSidecar(hasSidecar) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

class RentalManagement {
    vector<Vehicle*> vehicles;

public:
    ~RentalManagement() {
        for (auto* v : vehicles) {
            delete v;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() const {
        for (const auto* v : vehicles) {
            if (v->getAvailability()) {
                v->displayDetails();
            }
        }
    }

    bool rentVehicle(const string& vehicleId) {
        for (auto* v : vehicles) {
            if (v->getId() == vehicleId && v->getAvailability()) {
                v->setAvailability(false);
                cout << "Vehicle " << vehicleId << " rented successfully." << endl;
                return true;
            }
        }
        cout << "Vehicle " << vehicleId << " is not available." << endl;
        return false;
    }

    void returnVehicle(const string& vehicleId) {
        for (auto* v : vehicles) {
            if (v->getId() == vehicleId && !v->getAvailability()) {
                v->setAvailability(true);
                cout << "Vehicle " << vehicleId << " returned successfully." << endl;
                return;
            }
        }
        cout << "Vehicle " << vehicleId << " was not found." << endl;
    }
};

int main() {
    RentalManagement rentalSystem;

    rentalSystem.addVehicle(new Car("C001", "Toyota", "Camry", 2020, 5));
    rentalSystem.addVehicle(new Motorcycle("M001", "Harley-Davidson", "Street 750", 2019, false));

    cout << "Available vehicles for rent:" << endl;
    rentalSystem.displayAvailableVehicles();

    // Simulating rental operations
    cout << "\nRenting a vehicle:" << endl;
    rentalSystem.rentVehicle("C001");

    cout << "\nAvailable vehicles after renting one:" << endl;
    rentalSystem.displayAvailableVehicles();

    // Simulating return operations
    cout << "\nReturning a vehicle:" << endl;
    rentalSystem.returnVehicle("C001");

    cout << "\nAvailable vehicles after returning one:" << endl;
    rentalSystem.displayAvailableVehicles();

    return 0;
}