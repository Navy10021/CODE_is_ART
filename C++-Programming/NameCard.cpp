#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS {
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void showPositionInfo(int pos) {
        switch (pos) {
            case CLERK:
                cout << "Clerk" << endl;
                break;

            case SENIOR:
                cout << "Senior" << endl;
                break;

            case ASSIST:
                cout << "Assist" << endl;
                break;

            case MANAGER:
                cout << "Manager" << endl;
                break;
        }
    }
}

class NameCard {
private:
    char* name;
    char* company;
    char* phone;
    int position;

public:
    NameCard(const char* _name, const char* _company, const char* _phone, int _position)    // const 
        : position(_position) {
        name = new char[strlen(_name) + 1];
        company = new char[strlen(_company) + 1];
        phone = new char[strlen(_phone) + 1];
        strcpy(name, _name);
        strcpy(company, _company);
        strcpy(phone, _phone);
    }

    void ShowNameCardInfo() const {
        cout << "=== Name Card ===" << endl;
        cout << "- Name : " << name << endl;
        cout << "- Company : " << company << endl;
        cout << "- Phone Num : " << phone << endl;
        cout << "- Position : ";
        COMP_POS::showPositionInfo(position);
        cout << endl;
    }

    ~NameCard() {
        delete[] name;
        delete[] company;
        delete[] phone;
    }
};

int main(void) {
    NameCard manClerk("LEE", "Navy", "010-6475-0000", COMP_POS::CLERK);
    NameCard manAssist("PARK", "Army", "010-8888-7777", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
