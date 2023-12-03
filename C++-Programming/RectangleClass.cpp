#include <iostream>
using namespace std;

class Point{
    private:
        int x;
        int y;
    
    public:
        Point(const int &xpos, const int &ypos)
            : x(xpos), y(ypos) {}
        
        int GetX() const{
            return x;
        }
        int GetY() const{
            return y;
        }

        bool SetX(int xpos){
            if (0 > xpos || xpos > 100){
                cout << "Out of range." << endl;
                return false;
            }
            x = xpos;
            return true;
        } 

        bool SetY(int ypos){
            if (0 > ypos || ypos > 100){
                cout << "Out of range." << endl;
                return false;
            }
            y = ypos;
            return true;
        } 
};

class Rectangle{
    private:
        Point upLeft;
        Point lowRight;
    public:
        Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):
            upLeft(x1, y1), lowRight(x2, y2) {}

        void ShowRecInfo() const{
            cout << "Up Left : " << "[" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << endl;
            cout << "Low Right : " << "[" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << endl;
        }
};

int main(){
    Rectangle rec(1, 1, 5, 5);
    rec.ShowRecInfo();

    return 0;
}
