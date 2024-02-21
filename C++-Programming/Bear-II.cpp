#include <iostream>
#include <vector>
using namespace std;

class Bear {
protected:
    float weight;
    float aggressiveness;
    int bearType; // 0=Polar, 1=Grizzly, 2=Black, 3=Black Momma
    float totalAggressiveness;
    int cubCnt;
    Bear* cubs[2]; // Array to hold cubs, assuming a max of 2 cubs

public:
    // Constructor
    Bear(float aWeight) : weight(aWeight), aggressiveness(0), bearType(-1), totalAggressiveness(0), cubCnt(0) {
        cubs[0] = cubs[1] = nullptr;
    }

    virtual ~Bear() {} // Virtual destructor for proper cleanup

    void SetWeight(float aWeight) {
        weight = aWeight;
        CalculateAggressiveness(); // Update aggressiveness if weight changes
    }

    float GetWeight() const {
        return weight;
    }
    
    float GetAggressive() const {
        return aggressiveness;
    }

    virtual void CalculateAggressiveness() {
        // Base class does not implement behavior
    }

    void AddCub(Bear* aCub) {
        if (cubCnt < 2) {
            cubs[cubCnt++] = aCub;
            CalculateTotalAggressiveness();
        }
    }

    virtual void CalculateTotalAggressiveness() {
        // In base class, just set to own aggressiveness
        totalAggressiveness = aggressiveness;
        for (int i = 0; i < cubCnt; ++i) {
            if (cubs[i]) {
                totalAggressiveness += cubs[i]->GetAggressive();
            }
        }
    }

    virtual void PrintSelf() const {
        cout << "Bear with Weight: " << weight << ", Aggressiveness: " << aggressiveness << endl;
    }
};

class Polar : public Bear {
public:
    Polar(float aWeight) : Bear(aWeight) {
        CalculateAggressiveness();
    }

    void CalculateAggressiveness() override {
        aggressiveness = weight; // Polar bear specific calculation
    }
};

class Grizzly : public Bear {
public:
    Grizzly(float aWeight) : Bear(aWeight) {
        CalculateAggressiveness();
    }

    void CalculateAggressiveness() override {
        aggressiveness = weight * 0.9f; // Grizzly bear specific calculation
    }
};

class Black : public Bear {
public:
    Black(float aWeight) : Bear(aWeight) {
        CalculateAggressiveness();
    }

    void CalculateAggressiveness() override {
        aggressiveness = weight * 0.7f; // Black bear specific calculation
    }
};

class BlackMomma : public Bear {
public:
    BlackMomma(float aWeight) : Bear(aWeight) {
        CalculateAggressiveness();
    }

    void CalculateAggressiveness() override {
        aggressiveness = weight * 0.7f * 2; // Black Momma specific calculation
    }

    void CalculateTotalAggressiveness() override {
        // Calculate total aggressiveness including cubs for Black Momma
        totalAggressiveness = aggressiveness;
        for (int i = 0; i < cubCnt; ++i) {
            if (cubs[i]) {
                totalAggressiveness += cubs[i]->GetAggressive();
            }
        }
    }

    void PrintSelf() const override {
        cout << "Black Momma bear with " << cubCnt << " cub(s), Weight: " << weight 
             << ", Aggressiveness: " << aggressiveness 
             << ", Total Aggressiveness: " << totalAggressiveness << endl;
    }
};

int main(void){
    vector <Bear*> bears;
    
    bears.push_back(new Polar(300));
    bears.push_back(new Grizzly(320));
    bears.push_back(new Black(280));
    Bear* bear_ptr;
    bear_ptr = new BlackMomma(350);
    bear_ptr->AddCub(new Black(100));
    bears.push_back(bear_ptr);
    
    // Loop and call PrintSelf
    for (const auto& bear : bears){
        bear->PrintSelf();
    }
    
    // clean Up 
    for (auto& bear : bears){
        delete bear;
        bear = nullptr;
    }
    bears.clear();
    
    return 0;
}
