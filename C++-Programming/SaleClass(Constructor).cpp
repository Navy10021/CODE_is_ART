#include <iostream>
using namespace std;

class FruitSeller{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    
    public:
        FruitSeller(int price, int num, int money)
            : APPLE_PRICE(price), numOfApples(num), myMoney(money) {}
        /*
        void InitMembers(int price, int num, int money){
            if (price < 0){
                cout << "Check apple price." << endl;
            }
            

            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }*/

        int SaleApples(int money){  // 판매 가능한 사과 개수를 리턴
            if (money < 0){
                cout << "Information is wrong." << endl;
                return 0;
            }

            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }

        void ShowSaleRes() const {  // 멤버 변수로 저장된 값을 변경하지 않겠다.
            cout << "The rest apples : " << numOfApples << endl;
            cout << "Sales revenue : " << myMoney << endl << endl;
        }
};

class FruitBuyer{
    private:
        int myMoney;
        int numOfApples;
    
    public:
        FruitBuyer(int money)
            : myMoney(money), numOfApples(0) {}
        /*
        void InitMembers(int money){
            myMoney = money;
            numOfApples = 0;
        }
        */

        void BuyApples(FruitSeller &seller, int money){
            if (money < 0){
                cout << "Information is wrong." << endl;
                return;
            }
            numOfApples += seller.SaleApples(money);  // Message passing(Using other object & function)
            myMoney -= money;
        }

        void ShowBuyRes() const{
            cout << "Balance : " << myMoney << endl;
            cout << "The number of apples : " << numOfApples << endl << endl;
        }
};


int main(void){
    FruitSeller seller(1000, 100, 0);
    //seller.InitMembers(1000, 100, 0);   // price, number, money

    FruitBuyer buyer_1(10000);
    FruitBuyer buyer_2(50000);
    //buyer_1.InitMembers(10000);           // money
    //buyer_2.InitMembers(30000);

    buyer_1.BuyApples(seller, 5000);
    cout << "=== Seller ===" << endl;
    seller.ShowSaleRes();
    cout << "=== Buyer 1 ===" << endl;
    buyer_1.ShowBuyRes();
    cout << "=== Buyer 2 ===" << endl;
    buyer_2.ShowBuyRes();

    buyer_2.BuyApples(seller, 10000);
    cout << "=== Seller ===" << endl;
    seller.ShowSaleRes();
    cout << "=== Buyer 1 ===" << endl;
    buyer_1.ShowBuyRes();
    cout << "=== Buyer 2 ===" << endl;
    buyer_2.ShowBuyRes();
}
