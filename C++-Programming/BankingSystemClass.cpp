#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);     // 계좌개설 
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllInfo(void);     // 잔액조회

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
    private:
        int accID;          // 계좌번호
        int balance;        // 잔 액
        char * cusName;     // 고객 이름
    
    public:
        Account(int ID, int money, char * name)     // Constructor
            : accID(ID), balance(money){
                cusName = new char[strlen(name) + 1];
                strcpy(cusName, name);
            }
        
        // Copy Constructor(Deep Copy) : 멤버와 포인터가 참조하는 대상까지 복사 
        Account(const Account& copy)        // const 참조자 : 참조자 &copy를 통한 값의 변경을 하지 않겠다.
            : accID(copy.accID), balance(copy.balance){
                cusName = new char[strlen(copy.cusName) + 1];
                strcpy(cusName, copy.cusName);
        }
        
        int GetaccID() const {   // 함수 내 멤버변수에 저장된값을 변경하지 않겠다. 
            return accID;
        }

        void Deposit(int money){    // 입금
            balance += money;
        }

        int Withdraw(int money){    // 출금 : 출금액 반환, 잔액 부족시 0 반환
            if (balance < money)
                return 0;
            balance -= money;
            return money;
        }

        void ShowAccInfo() const {  // 함수 내 멤버변수에 저장된 값을 변경하지 않겠다.
            cout << "Account ID : " << accID << endl;
            cout << "Customer's Name : " << cusName << endl;
            cout << "Balance : " << balance << endl;
        }

        ~Account(){
            delete []cusName;       // Destructor
        }
};

Account * accArr[100];      // Account 저장을 위한 배열(객체 포인터 배열)
int accNum = 0;             // Account 개수 

int main(void){
    int choice;
    while(1){
        ShowMenu();
        cout << "Your Choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        
        case DEPOSIT:
            DepositMoney();
            break;

        case WITHDRAW:
            WithdrawMoney();
            break;
        
        case INQUIRE:
            ShowAllInfo();
            break;
        
        case EXIT:
            for (int i = 0; i < accNum; i++)
                delete accArr[i];
            return 0;

        default:
            cout << "Illegal selection..." << endl;
        }
    }
    return 0;
}


void ShowMenu(void) {
    cout << "====== MENU ======" << endl;
    cout << "1 : Make Account" << endl;
    cout << "2 : Deposit money" << endl;
    cout << "3 : Withdraw money" << endl;
    cout << "4 : Account Info" << endl;
    cout << "5 : EXIT" << endl;
}

void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;
    cout << "[Make Account]" << endl;
    cout << "Your ID : "; cin >> id;
    cout << "Your name : "; cin >> name;
    cout << "money : "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);  // 객체를 생성해서, 이 객체의 주소값을 배열에 저장.

}

void DepositMoney(void){
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

void WithdrawMoney(void){
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

void ShowAllInfo(void){
    for (int i = 0; i < accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}
