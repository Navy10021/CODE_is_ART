#include <iostream>
#include <cstring>

using namespace std;

class Rectangle{
    private:
        int wide;
        int height;
    
    public:
        Rectangle(int _wide, int _height) 
            : wide(_wide), height(_height){}
        
        void ShowAreaInfo() const{
            cout << "Area : " << wide * height << endl;
        }
};

class Square : public Rectangle{
    private:
        int slide;
    
    public:
        Square(int _slide)
            : Rectangle(_slide, _slide), slide(_slide){}
};

int main(void){
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
