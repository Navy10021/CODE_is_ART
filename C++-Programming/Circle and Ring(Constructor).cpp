#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x, int y)
            : xpos(x), ypos(y) {}   // Constructor
        
        void ShowPointInfo() const {
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
};

class Circle{
    private:
        Point center;
        int radius;
    
    public:
        Circle(int x, int y, int r)
            : center(x, y){
                radius = r;
            }    // Constructor
    
        void ShowCircleInfo() const {
            cout << "Radius : " << radius << endl;
            center.ShowPointInfo();
        }
};

class Ring{
    private:
        Circle inCircle;
        Circle outCircle;
    
    public:
        Ring(int inX, int inY, int inR, int outX, int outY, int outR):
            inCircle(inX, inY, inR), outCircle(outX, outY, outR) {}     // Constructor
        
        void showRingInfo() const {
            cout << "Inner Circle Info ..." << endl;
            inCircle.ShowCircleInfo();
            cout << "Outter Circle Info ..." << endl;
            outCircle.ShowCircleInfo();
        }
};


int main(void){
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.showRingInfo();

    return 0;
}
