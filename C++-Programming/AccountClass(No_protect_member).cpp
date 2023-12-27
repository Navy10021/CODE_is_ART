#include <iostream>
#include <iomanip>  // for std::fixed() and std::setprecision()
using namespace std;

class Account {
private:
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
    // Private member에 접근할 수 있는 별도의 함수를 구현해야함.
    const string& getAccountNum() const{
        return accountNumber;
    }
    double getBalance() const{
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string &number, double initialBalance, double rate)
        : Account(number, initialBalance), interestRate(rate) {}

    void applyInterest() {
        //double newBalance = getBalance() + (getBalance() * interestRate);
        cout << "Interest applied to savings account " << getAccountNum() << endl;
        deposit(getBalance() * interestRate);
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
        if (getBalance() >= transactionFee) {
            withdraw(transactionFee);
            cout << "Transaction fee deducted from checking account " << getAccountNum() << endl;
        } else {
            cout << "Insufficient funds to deduct transaction fee from checking account " << getAccountNum() << endl;
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