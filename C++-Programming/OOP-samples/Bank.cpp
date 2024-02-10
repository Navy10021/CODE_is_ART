#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " to Account Number: " << accountNumber << endl;
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds in Account Number: " << accountNumber << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << " from Account Number: " << accountNumber << endl;
        return true;
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber, double balance, double interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest: $" << interest << " added to Account Number: " << accountNumber << endl;
    }

    void display() const override {
        Account::display();
        cout << "Type: Savings, Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, double balance, double overdraftLimit)
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    bool withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded in Account Number: " << accountNumber << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << " from Account Number: " << accountNumber << " (Checking)" << endl;
        return true;
    }

    void display() const override {
        Account::display();
        cout << "Type: Checking, Overdraft Limit: $" << overdraftLimit << endl;
    }
};

const int MAX_ACCOUNTS = 10; // Example limit for accounts per customer
const int MAX_CUSTOMERS = 100; // Example limit for customers in the bank

class Customer {
private:
    string name;
    Account* accounts[MAX_ACCOUNTS]; // Static array of pointer to Account
    int numAccounts = 0;

public:
    Customer(string name) : name(name) {
        for (int i = 0; i < MAX_ACCOUNTS; ++i) {
            accounts[i] = nullptr;
        }
    }

    ~Customer() {
        for (int i = 0; i < numAccounts; ++i) {
            delete accounts[i];
        }
    }

    void addAccount(Account* account) {
        if (numAccounts < MAX_ACCOUNTS) {
            accounts[numAccounts++] = account;
        } else {
            cout << "Maximum number of accounts reached for " << name << "." << endl;
        }
    }

    void displayAccounts() const {
        cout << "Customer: " << name << endl;
        for (int i = 0; i < numAccounts; ++i) {
            accounts[i]->display();
        }
    }
};

class Bank {
private:
    Customer* customers[MAX_CUSTOMERS]; // Static array of pointer to Customer
    int numCustomers = 0;

public:
    Bank() {
        for (int i = 0; i < MAX_CUSTOMERS; ++i) {
            customers[i] = nullptr;
        }
    }

    ~Bank() {
        for (int i = 0; i < numCustomers; ++i) {
            delete customers[i];
        }
    }

    void addCustomer(Customer* customer) {
        if (numCustomers < MAX_CUSTOMERS) {
            customers[numCustomers++] = customer;
        } else {
            cout << "Maximum number of customers reached." << endl;
        }
    }

    void displayCustomers() const {
        for (int i = 0; i < numCustomers; ++i) {
            customers[i]->displayAccounts();
        }
    }
};


int main() {
    Bank bank;

    // Creating customers dynamically
    Customer* customer1 = new Customer("John Doe");
    Customer* customer2 = new Customer("Jane Smith");

    // Creating accounts dynamically and adding them to customers
    Account* johnSavings = new SavingsAccount(123456, 1000.0, 2.5);
    Account* johnChecking = new CheckingAccount(654321, 500.0, 150.0);
    customer1->addAccount(johnSavings);
    customer1->addAccount(johnChecking);

    Account* janeSavings = new SavingsAccount(112233, 1500.0, 3.0);
    Account* janeChecking = new CheckingAccount(332211, 750.0, 200.0);
    customer2->addAccount(janeSavings);
    customer2->addAccount(janeChecking);

    // Adding customers to the bank
    bank.addCustomer(customer1);
    bank.addCustomer(customer2);

    // Display initial state of all customers and their accounts
    cout << "Initial bank state:" << endl;
    bank.displayCustomers();

    // Simulating various account operations
    cout << "\nSimulating account operations:" << endl;
    johnSavings->deposit(200);
    johnChecking->withdraw(100);
    static_cast<SavingsAccount*>(janeSavings)->addInterest(); // Casting to call SavingsAccount specific method
    janeChecking->withdraw(1000); // This should exceed the overdraft limit

    // Display final state of all customers and their accounts
    cout << "\nFinal bank state:" << endl;
    bank.displayCustomers();

    return 0;
}
