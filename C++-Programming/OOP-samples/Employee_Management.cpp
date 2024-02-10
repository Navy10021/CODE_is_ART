#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract Base Class: Employee
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}

    virtual double calculatePay() const = 0;

    virtual void display() const {
        cout << "Employee [Name: " << name << ", ID: " << id << "]: ";
    }

    virtual ~Employee() {}
};

// Derived Class: SalariedEmployee
class SalariedEmployee : public Employee {
    double annualSalary;

public:
    SalariedEmployee(string name, int id, double annualSalary)
        : Employee(name, id), annualSalary(annualSalary) {}

    double calculatePay() const override {
        return annualSalary / 52; // Assuming paid weekly
    }

    void display() const override {
        Employee::display();
        cout << "Salaried Employee, Annual Salary: $" << annualSalary << endl;
    }
};

// Derived Class: HourlyEmployee
class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculatePay() const override {
        return hourlyRate * hoursWorked;
    }

    void display() const override {
        Employee::display();
        cout << "Hourly Employee, Hourly Rate: $" << hourlyRate << ", Hours Worked: " << hoursWorked << endl;
    }
};

// Derived Class: CommissionEmployee
class CommissionEmployee : public Employee {
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(string name, int id, double salesAmount, double commissionRate)
        : Employee(name, id), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculatePay() const override {
        return salesAmount * commissionRate;
    }

    void display() const override {
        Employee::display();
        cout << "Commission Employee, Sales Amount: $" << salesAmount << ", Commission Rate: " << commissionRate << endl;
    }
};

int main() {
    vector<Employee*> employees;

    employees.push_back(new SalariedEmployee("John Doe", 1, 52000));
    employees.push_back(new HourlyEmployee("Jane Smith", 2, 20.5, 40));
    employees.push_back(new CommissionEmployee("James Dean", 3, 15000, 0.1));

    for (const Employee* employee : employees) {
        employee->display();
        cout << "Weekly Pay: $" << employee->calculatePay() << endl << endl;
    }

    // Clean up dynamically allocated memory
    for (Employee* employee : employees) {
        delete employee;
    }

    return 0;
}