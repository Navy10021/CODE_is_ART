#include <iostream>
#include <algorithm> // for std::sort

using namespace std;
const int MAX_EMPLOYEES = 5;

// Salary Class
class Employee{
    private:
        string name;
        int ID;
    public:
        Employee(const string& name, int empID) : 
            ID(empID) { this->name = name; }
        virtual double CalculateSalary() const = 0; // Pure virtual
        virtual void DisplayInfo() const{
            cout << "Employee ID : " << ID << " || Name : " << name;
        }

        virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
    private:
        double hourRate;
        int hoursWorked;
    public:
        HourlyEmployee(const string& name, int empID, double rate, int hours)
            : Employee(name, empID), hourRate(rate), hoursWorked(hours) {}
        double CalculateSalary() const override {
            return hourRate * hoursWorked;
        }
        void DisplayInfo() const override{
            Employee::DisplayInfo();
            cout << " || Type : Hourly || Salary : $" << CalculateSalary() << endl;
        }
};

class SalariedEmployee : public Employee {
    private:
        double annualSalary;
    public:
        SalariedEmployee(const string& name, int empID, double salary)
            : Employee(name, empID), annualSalary(salary) {}
        double CalculateSalary() const override {
            return annualSalary / 12;
        }
        void DisplayInfo() const override{
            Employee::DisplayInfo();
            cout << " || Type : Salaried || Salary : $" << CalculateSalary() << endl;
        }
};

class SalaryCalculator {
    private:
        Employee* employeesArr[MAX_EMPLOYEES];
        int numEmp;
    public:
        SalaryCalculator() : numEmp(0) {}		// Constructor

        ~SalaryCalculator(){					// Destructor
            for (int i = 0; i < numEmp; i++){
                delete employeesArr[i];
            }
        }

        void AddEmployee(Employee * emp){
            if (numEmp < MAX_EMPLOYEES){
                employeesArr[numEmp++] = emp;
            }
            else{
                cout << "Maximum employee limit reached. Need to Fire." << endl;
                delete emp;
            }
        }

        double TotalSalary() const {
            double total = 0.0;
            for (int i = 0; i < numEmp; i++){
                total += employeesArr[i]->CalculateSalary();
            }
            return total;
        }

        void sortBySalary(){
            sort(employeesArr, employeesArr + numEmp, [](const Employee* a, const Employee* b){
                return a->CalculateSalary() > b->CalculateSalary();
            });
        }

        void DisplayEmployees() const{
            for (int i = 0; i < numEmp; i++){
                employeesArr[i]->DisplayInfo();
            }
        }
};

int main(void){
    SalaryCalculator MyCompany;
    Employee * ptr;
    ptr = new HourlyEmployee("Cleaner", 101, 15.0, 56);
    MyCompany.AddEmployee(ptr);
    ptr = new SalariedEmployee("AI Engineer", 102, 90000.0);
    MyCompany.AddEmployee(ptr);
    ptr = new SalariedEmployee("BigData Anaysis", 103, 100000.0);
    MyCompany.AddEmployee(ptr);
    ptr = new SalariedEmployee("Computer Engineer", 104, 80000.0);
    MyCompany.AddEmployee(ptr);
    ptr = new HourlyEmployee("Body Gaurd",105, 100.0, 72);
    MyCompany.AddEmployee(ptr);
    ptr = new SalariedEmployee("Lawer", 106, 120000.0);
    MyCompany.AddEmployee(ptr);
        
    cout << "Total Salaries in my company per month : $" << MyCompany.TotalSalary() << endl;
    MyCompany.sortBySalary(); // Soring
    MyCompany.DisplayEmployees();

    return 0;
}
