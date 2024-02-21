#include <iostream>
#include <vector>

using namespace std;

// Computer's Units : CPU, GPU, RAM, SSD, HDD

// Base class
class Unit {
    protected:
        string name;
        double performance;  // 0 ~ 100;
        double price;        // $
    
    public:
        // Constructor
        Unit(string _name, double _performance, double _price)
            : name(_name), performance(_performance), price(_price) {}

        virtual void display() const {
            cout << "Device : " << name << ", Price : $" << price;
            cout << ", Performance Score : " << performance << endl;
        }

        virtual void calculatePerformance() = 0;  // pure virtual function

        double getPrice() const{
            return price;
        }

        double getPerformance() const{
            return performance;
        }
        // Destructor          
        virtual ~Unit() {}
};

// Driven from Unit
class CPU : public Unit {
    private:
        int num_cores;  // Cores in CPU
    
    public:
        CPU(string _name, double _performance, double _price, int _num_cores)
            : Unit(_name, _performance, _price), num_cores(_num_cores) {
                calculatePerformance();
            }
        
        void display() const override{
            cout << "CPU | ";
            Unit::display();
        }

        void calculatePerformance() override {
            // core adds 10% to the base performance
            performance = performance * (1 + (num_cores * 0.1));
        }
};

class GPU : public Unit {
    private:
        int num_cores;  // Cores in GPU
        int memory;     // Memory size in GB
    
    public:
        GPU(string _name, double _performance, double _price, int _num_cores, int _memory)
            :  Unit(_name, _performance, _price), num_cores(_num_cores), memory(_memory) {
                calculatePerformance();
            }
        
        void display() const override {
            cout << "GPU | ";
            Unit::display();
        }

        void calculatePerformance() override {
            // core adds 5% to the base performance, and each GB of memory adds 2%
            performance = performance * (1 + (num_cores * 0.05) + (memory * 0.02));
        }
};

class RAM : public Unit {
    private:
        int memory;     // Memory size in GB
        int speed;      // Speed in MHz

    public:
        RAM(string _name, double _performance, double _price, int _memory, int _speed)
        : Unit(_name, _performance, _price), memory(_memory), speed(_speed) {
            calculatePerformance();
    }

    void display() const override {
        cout << "RAM | ";
        Unit::display();
    }

    void calculatePerformance() override {
        // Let's say each GB of memory adds 1% to the base performance, and every 200 MHz adds another 1%
        performance = performance * (1 + (memory * 0.01) + (speed / 200.0 * 0.01));
    }

};

class HDD : public Unit {
    protected:
        int capacity;   // Storage capacity in GB
        int speed;      // Data transfer speed in MB/s
    
    public:
        HDD(string _name, double _performance, double _price, int _capacity, int _speed)
        : Unit(_name, _performance, _price), capacity(_capacity), speed(_speed) {
        calculatePerformance();
    }

    void display() const override {
        cout << "HDD | ";
        Unit::display();
        cout << ", Capacity: " << capacity << " GB, Speed: " << speed << " MB/s" << endl;
    }

    void calculatePerformance() override {
        // each 100 GB of capacity adds 1% to the base performance, and each 50 MB/s adds another 1%
        performance = performance * (1 + (capacity / 100.0 * 0.01) + (speed / 50.0 * 0.01));
    }
};

class SSD : public HDD {
    public:
        SSD(string _name, double _performance, double _price, int _capacity, int _speed)
        : HDD(_name, _performance, _price, _capacity, _speed) {
        calculatePerformance(); // Recalculate to adjust for SSD specifics
    }

    void display() const override {
        cout << "SSD | ";
        HDD::display(); // Use the base class display and append any SSD-specific details if needed
    }

    void calculatePerformance() override {
        // a base 20% increase in performance over HDD calculation
        performance = performance * (1.2 + (capacity / 100.0 * 0.02) + (speed / 50.0 * 0.02));
    }
};
class Computer {
protected:
    string name;
    double basePrice;
    double basePerformance;
    double totalPrice;
    double totalPerformance;
    Unit* units[10];  // Array of pointers to hold up to 10 units
    int unitsIdx;

public:
    Computer(string _name, double _basePrice, double _basePerformance)
        : name(_name), basePrice(_basePrice), basePerformance(_basePerformance), totalPrice(0.0), totalPerformance(0.0), unitsIdx(0) {
            // Initialize units array to nullptr
            for (int i = 0; i < 10; ++i) {
                units[i] = nullptr;
            }
            calculatePerformance();
            calculatePrice();
        }

    void addUnit(Unit* unit) {
        if (unitsIdx < 10) { // Check to avoid adding more than 10 units
            units[unitsIdx++] = unit;
            calculatePerformance();
            calculatePrice();
        } else {
            cout << "Cannot add more units, maximum capacity reached." << endl;
        }
    }

    virtual void calculatePerformance() {
        totalPerformance = basePerformance;
        for (int i = 0; i < unitsIdx; i++) {
            if (units[i]) { // Ensure the pointer is not null before dereferencing
                totalPerformance += units[i]->getPerformance();
            }
        }
    }

    virtual void calculatePrice() {
        totalPrice = basePrice;
        for (int i = 0; i < unitsIdx; i++) {
            if (units[i]) { // Ensure the pointer is not null before dereferencing
                totalPrice += units[i]->getPrice();
            }
        }
    }

    virtual void display() const {
        cout << "Computer: " << name << ", Total Price: $" << totalPrice;
        cout << ", Total Performance: " << totalPerformance << endl;
    }

    virtual void display_detail() const {
        display();
        for (int i =0; i < unitsIdx; i++){
            if (units[i]){
                units[i]->display();
            }
        }
    }

    virtual ~Computer() {
        // Destructor to clean up dynamically allocated Unit objects
        for (int i = 0; i < unitsIdx; ++i) {
            delete units[i]; // Safe to delete nullptr if no unit was added at a position
        }
    }
};

class SuperComputer : public Computer {
    private:
        int numberOfNodes; // Represents the number of computing nodes in the supercomputer
        double coolingSystemEfficiency; // A metric for the efficiency of the cooling system, can affect performance

    public:
        // Constructor
        SuperComputer(string _name, double _basePrice, double _basePerformance, int _numberOfNodes, double _coolingSystemEfficiency)
            : Computer(_name, _basePrice, _basePerformance), numberOfNodes(_numberOfNodes), coolingSystemEfficiency(_coolingSystemEfficiency) {
                calculatePerformance(); // Adjust initial performance based on the number of nodes and cooling efficiency
            }

        // Overriding display to show supercomputer-specific attributes
        void display() const override {
            Computer::display(); // Call base class display
            cout << "Nodes: " << numberOfNodes << ", Cooling System Efficiency: " << coolingSystemEfficiency << endl;
        }

        void display_detail() const override{
            display();
            for (int i =0; i < unitsIdx; i++){
                if (units[i]){
                    units[i]->display();
                }
            }
        }

        // Overriding calculatePerformance to factor in the number of nodes and cooling efficiency
        void calculatePerformance() override {
            Computer::calculatePerformance(); // Calculate base performance from units
            // Assuming each node adds a flat performance score, modified by cooling efficiency
            totalPerformance += (numberOfNodes * 100) * coolingSystemEfficiency; // Example calculation
    }

        void calculatePrice() override {
            Computer::calculatePrice();
            // add Cooling system cost
            double coolingSystemCost = 10000 * coolingSystemEfficiency;
            double nodesCost = 5000 * numberOfNodes;
            totalPrice += numberOfNodes + coolingSystemCost + nodesCost;
        }
};


int main(void){
    /*
    CPU cpu("Intel Core i9", 50, 450, 8);
    GPU gpu("NVIDIA RTX 3080", 70, 700, 2, 10);
    RAM ram("Corsair Vengeance", 40, 150, 16, 3200);
    HDD hdd("Seagate Barracuda", 30, 100, 2000, 150);
    SSD ssd("Samsung Evo", 60, 200, 1000, 550);

    vector<Unit*> computerUnits;
    computerUnits.push_back(&cpu);
    computerUnits.push_back(&gpu);
    computerUnits.push_back(&ram);
    computerUnits.push_back(&hdd);
    computerUnits.push_back(&ssd);

    for (const auto& unit : computerUnits){
        unit->display();
    }
    */
    // Create computer
    Computer myComputer("Gaming PC", 1000, 100);

    // Create units and add them to the computer
    // Note: Dynamically allocating units to demonstrate deletion in Computer's destructor
    myComputer.addUnit(new CPU("Intel Core i9", 90, 450, 8));
    myComputer.addUnit(new GPU("NVIDIA RTX 3080", 95, 700, 8704, 10));
    myComputer.addUnit(new RAM("Corsair Vengeance", 85, 150, 16, 3200));
    myComputer.addUnit(new HDD("Seagate Barracuda", 80, 100, 2000, 150));
    myComputer.addUnit(new SSD("Samsung Evo", 95, 200, 1000, 550));

    // Create a supercomputer instance
    SuperComputer mySuperComputer("Hercules", 50000, 1000, 64, 1.1);

    // Add high-performance computing units to the supercomputer
    // Note: For simplicity, assuming these units are compatible and the performance impact is cumulative
    mySuperComputer.addUnit(new CPU("Xeon Platinum 8180M", 150, 10000, 28));
    mySuperComputer.addUnit(new GPU("NVIDIA Tesla V100", 200, 8000, 5120, 16));
    mySuperComputer.addUnit(new RAM("Crucial DDR4-2666", 100, 400, 64, 2666));
    mySuperComputer.addUnit(new SSD("Intel Optane SSD 900P", 120, 1500, 480, 2500));

    // Display
    //myComputer.display();
    //mySuperComputer.display();
    myComputer.display_detail();
    mySuperComputer.display_detail();

    return 0;
}
