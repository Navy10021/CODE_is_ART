#include <iostream>
#include <cstring>

using namespace std;

class Person{       // Base class
    private:
        int age;
        char name[50];
    
    public:
        Person(int myage, const char * myname) : age(myage){
            strcpy(name, myname);
        }
        void WhatYourName() const{
            cout << "My name is " << name << endl;
        }

        void HowOldAreYour() const{
            cout << "I'm " << age << "years old" << endl;
        }
};

class UnivStudent : public Person{  // Derived class : Base class의 멤버변수 + 멤버 함수 상속
    private:
        char major[50];
    public:
        UnivStudent(const char * myname, int myage, const char * major)     // UnivStudent constructor.
            : Person(myage, myname){                            // Person constructor 호출.
                strcpy(this->major, major);
            }
        
        void WhoAreYou() const{
            WhatYourName();
            HowOldAreYour();
            cout << "My major is " << major << endl << endl; 
        }
};

int main(void){
    UnivStudent student1("LEE", 37, "Data Sci.");
    UnivStudent student2("KIM", 27, "Computer eng.");

    student1.WhoAreYou();
    student2.WhoAreYou();

    return 0;
}
