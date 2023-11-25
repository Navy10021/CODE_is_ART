#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);     // 계좌개설 
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllInfo(void);     // 잔액조회

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};  // {1, 2, 3, 4, 5} 

typedef struct{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];    // Account 저장을 위한 배열 
int accNum = 0;         // 저장된 Account 수 

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
            return 0;

        default:
            cout << "Illegal selection." << endl;
        }
    }
    return 0;
}

void ShowMenu(void){
    cout << "---- MENU ----" << endl;
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
    cout << "money :"; cin >> balance;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++; 
} 

void DepositMoney(void){
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Your ID : "; cin >> id;
    cout << "money : "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i].accID == id){
            accArr[i].balance+=money;
            cout << money <<"WON is Deposited." << endl;
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
        if(accArr[i].accID == id){
            if (accArr[i].balance < money){
                cout << "Insufficient MONEY." << endl;
                return;
            }
            accArr[i].balance -= money;
            cout << money << "WON is withdrawed." << endl;
            return;
        }
    }
    cout << "Can't find your ID." << endl;
}
void ShowAllInfo(void){
    for(int i = 0; i < accNum; i++){
        cout << "ID Customer: " << accArr[i].accID << endl;
        cout << "NAME : " << accArr[i].cusName << endl;
        cout << "BALANCE : " << accArr[i].balance << endl;
    }
} 
