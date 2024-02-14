#include <iostream>
using namespace std;

class Electronics{
    private:
        int Size;
    
    public:
        Electronics(int size) : Size(size) {}

        virtual int GetPrice() const = 0;

        virtual void PrintSelf() const = 0;

        int GetSize() const{
            return Size;
        }

        void SetSize(int Size){
            this->Size = Size;
        }

        virtual ~Electronics() {}
};


class TV : public Electronics{

    public:
        TV(int size) : Electronics(size) {}

        int GetPrice() const override {
            return GetSize() * 1.8;
        }

        void PrintSelf() const override{
            cout << "It's a TV, Size = " << GetSize() << ", Price = " << GetPrice() << endl;
        }
};

class Cellphone : public Electronics{

    public:
        Cellphone(int size) : Electronics(size) {}

        int GetPrice() const override {
            return GetSize() * 0.7;
        }

        void PrintSelf() const override{
            cout << "It's a Cellphone, Size = " << GetSize() << ", Price = " << GetPrice() << endl;
        }
};

class Computer : public Electronics{

    public:
        Computer(int size) : Electronics(size) {}
        int GetPrice() const override {
            return GetSize() * 0.6;
        }

        void PrintSelf() const override{
            cout << "It's a Computer, Size = " << GetSize() << ", Price = " << GetPrice() << endl;
        }
};

class Laptop : public Computer{
    private:
        Electronics* GPUArr[2];     // 2 GPU as MAX
        int GPUNum;
    public:
        Laptop(int size) : Computer(size), GPUNum(0) {}

        ~Laptop(){
            for (int i=0; i<GPUNum; i++){
                delete GPUArr[i];
            }
        }

        int GetPrice() const override {
            if (GPUNum == 0)
                return Computer::GetPrice();
            
            else
                return Computer::GetPrice() * 2;
        }

        int GPUPrice() const{
            int price = 0;
            for (int i = 0; i < GPUNum; i++){
                price += GPUArr[i]->GetSize() * 0.6;    // Computer Price;
            }
            return price;
        }

        bool AddGPU(Electronics *aGPU){
            if (GPUNum >= 2){
                cout << "Laptop can have two GPU as max." << endl;
                return false;
            }
            else{
                GPUArr[GPUNum++] = aGPU;
                return true;
            }
        }

        void PrintSelf() const override{
            cout << "It's a Laptop with " << GPUNum << " GPU(s), Size = " << GetSize() << " Price = " << GetPrice() << " Total Price = " << GetPrice() + GPUPrice() << endl;
        }
};

int main() {
    TV myTV(600);
    Cellphone myPhone(160);
    Laptop myLaptop(330);

    // Add GPUs
    Electronics * ptr;
    ptr = new Computer(50);
    myLaptop.AddGPU(ptr);
    ptr = new Computer(100);
    myLaptop.AddGPU(ptr);
    ptr = new Computer(100);
    myLaptop.AddGPU(ptr);


    myTV.PrintSelf();
    myPhone.PrintSelf();
    myLaptop.PrintSelf();

    return 0;
}
