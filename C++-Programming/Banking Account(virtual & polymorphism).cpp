#include <iostream>
#include <iomanip>  // for std::fixed() && setprecision()
using namespace std;

// Base Class
class Account {
protected:
    string accountNumber;
    double balance;

public: // Constructor
    Account(const string& _number, double _balance) : accountNumber(_number), balance(_balance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdraw $" << amount << " from account " << accountNumber << endl; // Fixed print statement
        }
        else {
            cout << "Insufficient funds for withdrawal from account " << accountNumber << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    virtual ~Account() {} // Virtual destructor
};

class SavingAccount : public Account {
private:
    double interestRate;

public:
    SavingAccount(const string& _number, double _balance, double _rate)
        : Account(_number, _balance), interestRate(_rate) {}

    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied to savings account " << accountNumber << endl;
    }

    void deposit(double amount) override {
        Account::deposit(amount); // Use base class deposit
        applyInterest();
    }

    void display() const override {
        cout << "Savings ";
        Account::display();
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;
public:
    CheckingAccount(const string& _number, double _balance, double _fee)
        : Account(_number, _balance), transactionFee(_fee) {}

    void deductTransactionFee() {
        if (balance >= transactionFee) {
            balance -= transactionFee;
            cout << "Transaction fee deducted from checking account " << accountNumber << endl;
        }
        else {
            cout << "Insufficient funds to deduct transaction fee from checking account " << accountNumber << endl;
        }
    }

    void withdraw(double amount) override {
        Account::withdraw(amount); // Use base class withdraw first
        deductTransactionFee();
    }

    void display() const override {
        cout << "Checking ";
        Account::display();
    }
};

int main(void) {
    // Example of virtual function and polymorphism
    Account* account1 = new SavingAccount("1001", 10000, 0.1);
    Account* account2 = new CheckingAccount("1003", 10000, 50);

    // Calls overridden function based on the object type.
    account1->deposit(20000);
    account2->deposit(20000);

    account1->display();
    account2->display();

    delete account1; // Freeing allocated memory
    delete account2; // Freeing allocated memory

    // Example of overloading function
    SavingAccount account3("1004", 30000, 0.5);
    CheckingAccount account4("1006", 30000, 100);

    account3.withdraw(10000);
    account4.withdraw(10000);
    account3.display();
    account4.display();

    return 0;
}
