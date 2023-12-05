#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// Accout class : Entity class

class Account{
    private:
        int accID;          // 계좌번호
        int balance;        // 잔 액
        char * cusName;     // 고객 이름

    public:
        Account(int ID, int money, const char * cusName);
        Account(const Account& ref);
        int GetaccID() const;
        void Deposit(int money);
        int Withdraw(int money);
        void ShowAccInfo() const;
        ~Account();
};


// Constructor
Account::Account(int ID, int money, const char * cusName)
    : accID(ID), balance(money){
        this->cusName = new char[strlen(cusName) + 1];
            strcpy(this->cusName, cusName);
        }
        
// Copy Constructor
Account::Account(const Account& ref)
    : accID(ref.accID), balance(ref.balance){
        cusName = new char[strlen(ref.cusName)+1];
        strcpy(cusName, ref.cusName);
    }

int Account::GetaccID() const{
    return accID;
}

void Account::Deposit(int money){
    balance += money;
}

int Account::Withdraw(int money){
    if (balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const {  // 함수 내 멤버변수에 저장된 값을 변경하지 않겠다.
    cout << "Account ID : " << accID << endl;
    cout << "Customer's Name : " << cusName << endl;
    cout << "Balance : " << balance << endl;
}

Account::~Account(){
    delete []cusName;       // Destructor
}


// Account Handler : Control Class

class AccountHandler{
    private:
        Account * accArr[100];
        int accNum;
    
    public:
        AccountHandler();
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccInfo(void) const;
        ~AccountHandler();
};

// Constructor
AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu(void) const{
    cout << "====== MENU ======" << endl;
    cout << "1 : Make Account" << endl;
    cout << "2 : Deposit money" << endl;
    cout << "3 : Withdraw money" << endl;
    cout << "4 : Account Info" << endl;
    cout << "5 : EXIT" << endl;
}

void AccountHandler::MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;
    cout << "[Make Account]" << endl;
    cout << "Your ID : "; cin >> id;
    cout << "Your name : "; cin >> name;
    cout << "money : "; cin >> balance;
    cout << endl;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetaccID() == id){
            cout << id << " -> This account number has aready exists." << endl << endl;
            return;
        }
    }

    accArr[accNum++] = new Account(id, balance, name);  // 객체를 생성해서, 이 객체의 주소값을 배열에 저장.
}

void AccountHandler::DepositMoney(void){
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Your ID : "; cin >> id;
    cout << "money : "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetaccID() == id){
            accArr[i]->Deposit(money);
            cout << money << " Deposit is completed." << endl;
            return;
        }
    }
    cout << "Can't find your ID" << endl;
}

void AccountHandler::WithdrawMoney(void){
    int money;
    int id;
    cout << "[Withdraw]" << endl;
    cout << "Your ID : "; cin >> id;
    cout << "money : "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetaccID() == id){
            if(accArr[i]->Withdraw(money) == 0){
                cout << "Insufficient MONEY." << endl;
                return;
            }
            cout << money << " Withdraw is completed." << endl;
            return;
        }
    }
    cout << "Can't find your ID" << endl;
}

void AccountHandler::ShowAllAccInfo(void) const{
    for (int i = 0; i < accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler(){
    for (int i=0; i<accNum; i++){
        delete accArr[i];
    }
}


int main(void){
    AccountHandler manager;
    int choice;

    while(1){
        manager.ShowMenu();
        cout << "Enter number : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection. Please check entered number." << endl;
        }
    }
    return 0;
}
