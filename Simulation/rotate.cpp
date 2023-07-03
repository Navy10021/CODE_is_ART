#include <iostream>
using namespace std;

const int MX = 20;
int r, c = MX;
int paper[MX][MX];

void rotate(){
    int tmp[MX][MX];
    
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            tmp[i][j] = paper[i][j];
    
    for (int i=0; i<c; i++)         // row -> col 
        for (int j=0; j<r; j++)     // col -> row
            paper[i][j] = tmp[r-1-j][i];
    swap(r, c);
}

int main()
{
    rotate();
    return 0;
}
