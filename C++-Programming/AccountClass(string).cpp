#include <iostream>
#include <iomanip>  // for std::fixed() and std::setprecision()
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string &number, double initialBalance) : accountNumber(number), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient funds for withdrawal from account " << accountNumber << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string &number, double initialBalance, double rate)
        : Account(number, initialBalance), interestRate(rate) {}

    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied to savings account " << accountNumber << endl;
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
    CheckingAccount(const string &number, double initialBalance, double fee)
        : Account(number, initialBalance), transactionFee(fee) {}

    void deductTransactionFee() {
        if (balance >= transactionFee) {
            balance -= transactionFee;
            cout << "Transaction fee deducted from checking account " << accountNumber << endl;
        } else {
            cout << "Insufficient funds to deduct transaction fee from checking account " << accountNumber << endl;
        }
    }

    void display() const override {
        cout << "Checking ";
        Account::display();
    }
};

int main() {
    SavingsAccount savings("SA123", 1000.0, 0.05);
    CheckingAccount checking("CA456", 500.0, 2.0);

    savings.display();
    savings.deposit(200.0);
    savings.applyInterest();
    savings.display();

    checking.display();
    checking.withdraw(100.0);
    checking.deductTransactionFee();
    checking.display();

    return 0;
}

