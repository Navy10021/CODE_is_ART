#include <iostream>
#include <cstring>

using namespace std;


class Computer{
    private:
        char owner[50];
    
    public:
        Computer(const char * name){
            strcpy(owner, name);
        }

        void Calculate() const{
            cout << "Computer is calculating..." << endl;
        }
};

class NoteBook : public Computer{
    private:
        int Battery;
    
    public:
        NoteBook(const char * name, int _Battery)
            : Computer(name), Battery(_Battery){}
        
        void Charging() {
            Battery += 5;
        }
        void UseBattery() {
            Battery -= 1;
        }
        void MovingCalculate(){
            if (GetBetteryInfo() < 1){
                cout << "Need Charging..." << endl;
                return;
            }
            cout << "Moving ";
            Calculate();
            UseBattery();
        }
        int GetBetteryInfo() const{
            return Battery;
        }
};

class Tablet : public NoteBook{
    private:
        char penModel[50];
    
    public:
        Tablet(const char * name, int Battery, const char * pen)
            : NoteBook(name, Battery){
                strcpy(penModel, pen);
            }
        
        void Write(const char * penInfo){
            if (GetBetteryInfo() < 1){
                cout << "Need Charging..." << endl;
                return;
            }
            if (strcmp(penModel, penInfo) != 0){
                cout << "This pen is NOT registed." << endl;
            }
            cout << "Write on the Tablet PC..." << endl;
            UseBattery();
        }
};

int main(void){
    NoteBook NP("Lee", 5);
    Tablet TP("KIM", 5, "ABC-123");

    NP.MovingCalculate();
    TP.Write("ABC-000");
    TP.Write("ABC-123");
    
    cout << NP.GetBetteryInfo() << endl;
    cout << TP.GetBetteryInfo() << endl;

    return 0;
}
