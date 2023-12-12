#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

// Polimorphism : Same function differnt results.
class Employee{
    private:
        char name[100];
    public:
        Employee(char *name){
            strcpy(this->name, name);
        }
        void ShowYourName() const{
            cout << "Name : " << name << endl;
        }
        virtual int GetPay() const = 0;          // Pure virtual function
        virtual void ShowSalaryInfo() const = 0; // Pure virtual function
        virtual ~Employee(){}
};

class PermanentWorker : public Employee{
    private:
        int salary;
    public:
        PermanentWorker(char *name, int money)
            : Employee(name), salary(money){}
        int GetPay() const{
            return salary;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "Salary : " << GetPay() << endl;
        }
};


class TemporaryWorker : public Employee{
    private:
        int workTime;
        int payPerHour;
    public:
        TemporaryWorker(char *name, int pay)
            : Employee(name), workTime(0), payPerHour(pay){}
        
        void AddWorkTime(int time){
            workTime += time;
        }
        int GetPay() const{
            return workTime * payPerHour;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "Salary : " << GetPay() << endl;
        }
};

class SalesWorker : public PermanentWorker{
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(char *name, int money, double ratio)
            : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){}

        void AddSalesResult(int value){
            salesResult += value;
        }

        int GetPay() const{
            return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }

        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "Salary : " << GetPay() << endl;
        }
};

namespace RISK_LEVEL{
    enum {RISK_A = 30, RISK_B = 20, RISK_C = 10};
}

class ForeignSalesWorker : public SalesWorker{
    private:
        const int riskLevel;
    public:
        ForeignSalesWorker(char *name, int money, double ratio, int risk)
            : SalesWorker(name, money, ratio), riskLevel(risk){}
        
        int GetRiskPay() const{
            return (int)(SalesWorker::GetPay() * (riskLevel/100.0));
        }
        int GetPay() const{
            return SalesWorker::GetPay() + GetRiskPay();
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "Salary : " << SalesWorker::GetPay() << endl;
            cout << "Risk Pay : " << GetRiskPay() << endl;
            cout << "SUM : " << GetPay() << endl;
        }

};


class EmployeeHandler{
    private:
        Employee * empList[50];    // All stored objects are Employee's Object based
        int empNum;
    public:
        EmployeeHandler() 
            : empNum(0){}

        void AddEmployee(Employee * emp){
            empList[empNum++] = emp;     // You can store base class(Employee) and Drived class(Permanant, Temporary, Sales Worker)
        }
        void ShowAllSalaryInfo() const{
            for (int i = 0; i < empNum; i++){
                empList[i]->ShowSalaryInfo();
            }
        }
        void ShowTotalSalary() const{
            int sum = 0;
            for (int i = 0; i < empNum; i++){
                sum += empList[i]->GetPay();
            }
            cout << "Salary SUM : " << sum << endl;
        }

        ~EmployeeHandler(){
            for (int i = 0; i < empNum; i++){
                delete empList[i];
            }    
        }
};

int main(void){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 2000));

    TemporaryWorker *alba_ptr = new TemporaryWorker("Ko", 700);
    alba_ptr->AddWorkTime(5);
    handler.AddEmployee(alba_ptr);

    SalesWorker * seller_ptr = new SalesWorker("Hong", 10000, 0.2);
    seller_ptr->AddSalesResult(7000);
    handler.AddEmployee(seller_ptr);

    ForeignSalesWorker * fseller_ptr1 = new ForeignSalesWorker("LIM", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller_ptr1->AddSalesResult(7000);
    handler.AddEmployee(fseller_ptr1);
    
    ForeignSalesWorker * fseller_ptr2 = new ForeignSalesWorker("PARK", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller_ptr2->AddSalesResult(7000);
    handler.AddEmployee(fseller_ptr2);
    
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}