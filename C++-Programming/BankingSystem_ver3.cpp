#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자 선택메뉴
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용 등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌 종류
enum {NORMAL = 1, CREDIT = 2};


// Account Class
class Account{
    private:
        int accID;
        int balance;
        char * cusName;

    public:
        Account(int ID, int money, char * name);    // Constructor
        Account(const Account &ref);                // Deep Copy
        int GetAccID() const;
        virtual void Deposit(int money);            // 가상함수 : Account 상속을 통해 에 공통적인 규약(Deposit)을 정의할 수 있고, Account Class를 상속하는 모든 Class의 객체는 Account 객체로 바라볼(참조*) 수 있다.
        int Withdraw(int money);
        void showAccInfo() const;
        ~Account();                                 // Destructor
};

// Account Class functions
Account::Account(int ID, int money, char * name)
    : accID(ID), balance(money){
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

Account::Account(const Account &ref)
    : accID(ref.accID), balance(ref.balance){
        cusName = new char[strlen(ref.cusName) + 1];
        strcpy(cusName, ref.cusName);
    }

int Account::GetAccID() const{
    return accID;
}

void Account::Deposit(int money){
    balance += money;
}

int Account::Withdraw(int money){
    if(balance < money){
        return 0;
    }
    balance -= money;
    return money;
}

void Account::showAccInfo() const{
    cout << "Account ID : " << accID << endl;
    cout << "Customer Name : " << cusName << endl;
    cout << "Balance : " << balance << endl;
}

Account::~Account(){
    delete []cusName;
}

// Normal Account Class
class NormalAccount : public Account{
    private:
        int interRate;      // % 단위 이자율
    public:
        NormalAccount(int ID, int money, char * name, int rate)
            : Account(ID, money, name), interRate(rate){}
        
        virtual void Deposit(int money){
            Account::Deposit(money);                         // 1. 원금 추가
            Account::Deposit(money * (interRate / 100.0));   // 2. 이자 추가
        }
};

// Credit Account Class
class HighCreditAccount : public NormalAccount{   
    private:
        int specialRate;

    public:
        HighCreditAccount(int ID, int money, char *name, int rate, int special)
            : NormalAccount(ID, money, name, rate), specialRate(special){}
        
        virtual void Deposit(int money){
            NormalAccount::Deposit(money);                       // 1. 원금 + 이자 추가
            Account::Deposit(money * (specialRate / 100.0));     // 2. 특별 이자 추가
        }

};


// Account Handler : Control Class
class AccountHandler{
    private:
        Account * accArr[500];
        int accNum;
    
    public:
        AccountHandler();
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccInfo(void) const;
        ~AccountHandler();
    
    protected:
        void MakeNormalAccount(void);
        void MakeCreditAccount(void);
};

AccountHandler::AccountHandler()
    : accNum(0){}

void AccountHandler::ShowMenu(void) const{
    cout << "======== MENU ========" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. All Account Information" << endl;
    cout << "5. EXIT" << endl;
}

void AccountHandler::MakeAccount(void){
    int choice;
    cout << "--- Type of Account ---" << endl;
    cout << "1. Normal Account" << endl;
    cout << "2. Credit Account" << endl;
    cout << "Your choice : ";
    cin >> choice;

    if (choice == NORMAL){
        MakeNormalAccount();
    }
    else{
        MakeCreditAccount();
    }
}

void AccountHandler::MakeNormalAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "[Make Normal Account]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Name : "; cin >> name;
    cout << "Deposit amount : "; cin >> balance;
    cout << "Interest rate : "; cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void){
        int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout << "[Make Credit Account]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Name : "; cin >> name;
    cout << "Deposit amount : "; cin >> balance;
    cout << "Interest rate : "; cin >> interRate;
    cout << "Credit Level(A->1, B->2, C->3) : "; cin >> creditLevel;
    cout << endl;
    
    switch(creditLevel){
        case 1:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
    }
}

void AccountHandler::DepositMoney(void){
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Deposit amount : "; cin >> money;

    for (int i=0; i<accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << money << "$ has been deposited." << endl;
            return;
        }
    }
    cout << "Please check your ID." << endl;
};

void AccountHandler::WithdrawMoney(void){
    int money;
    int id;
    cout << "[Withdraw]" << endl;
    cout << "Account ID : "; cin >> id;
    cout << "Withdraw amount : "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            if (accArr[i]->Withdraw(money) == 0){
                cout << "Your balance is insufficient." << endl;
                return;
            }
            cout << money << "$ has been withdrawn." << endl << endl;
        }
    }
    cout << "Please check your ID." << endl;
}

void AccountHandler::ShowAllAccInfo(void) const{
    for (int i = 0; i < accNum; i++){
        accArr[i]->showAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler(){
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}


// main function
int main(void){
    AccountHandler manager;
    int choice;

    while(1){
        manager.ShowMenu();
        cout << "Choose your number : ";
        cin >> choice;
        cout << endl;

        switch(choice){
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
                cout << "Illegal selection." << endl;
        }
    }
    return 0;
}
