#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ComputingUnit {
protected:
    string model;
    int cores;

public:
    ComputingUnit(string model, int cores) : model(model), cores(cores) {}

    virtual void performComputation() const = 0;
    virtual int computePower() const = 0;

    virtual void display() const {
        cout << "Model: " << model << ", Cores: " << cores << endl;
    }

    virtual ~ComputingUnit() {}
};

class CPU : public ComputingUnit {
public:
    CPU(string model, int cores) : ComputingUnit(model, cores) {}

    void performComputation() const override {
        cout << "Performing computation using CPU: " << model << endl;
    }

    int computePower() const override {
        return cores * 1;
    }
};

class GPU : public ComputingUnit {
public:
    GPU(string model, int cores) : ComputingUnit(model, cores) {}

    void performComputation() const override {
        cout << "Performing computation using GPU: " << model << endl;
    }

    int computePower() const override {
        return cores * 10; // Assuming GPUs have 10x the computing power of CPUs
    }
};

class Server {
    vector<ComputingUnit*> units;
    string serverName;

public:
    Server(string name) : serverName(name) {}

    ~Server() {
        for (auto* unit : units) {
            delete unit;
        }
    }

    void addComputingUnit(ComputingUnit* unit) {
        units.push_back(unit);
    }

    int totalComputePower() const {
        int totalPower = 0;
        for (const auto* unit : units) {
            totalPower += unit->computePower();
        }
        return totalPower;
    }

    void display() const {
        cout << "Server: " << serverName << ", Total Compute Power: " << totalComputePower() << endl;
        for (const auto* unit : units) {
            unit->display();
        }
    }
};

class DataCenter {
    vector<Server*> servers;

public:
    ~DataCenter() {
        for (auto* server : servers) {
            delete server;
        }
    }

    void addServer(Server* server) {
        servers.push_back(server);
    }

    void displayServers() const {
        cout << "Data Center Servers:" << endl;
        for (const auto* server : servers) {
            server->display();
            cout << endl;
        }
    }
};

int main() {
    DataCenter dataCenter;

    Server* server1 = new Server("Server1");
    server1->addComputingUnit(new CPU("Intel i9", 8));
    server1->addComputingUnit(new GPU("NVIDIA RTX 3080", 8704));

    Server* server2 = new Server("Server2");
    server2->addComputingUnit(new CPU("AMD Ryzen 9", 12));
    server2->addComputingUnit(new GPU("AMD Radeon RX 6800", 3840));

    dataCenter.addServer(server1);
    dataCenter.addServer(server2);

    dataCenter.displayServers();

    // Automatically cleans up the dynamically allocated Server and ComputingUnit objects
    return 0;
}