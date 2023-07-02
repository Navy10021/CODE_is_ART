#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {3,2,1,5,4,6,10,9,8,7};
    int n = 10;
    for (int i = n-1; i > 0; i--){
        int mx_idx = 0;
        for (int j = 1; j <= i; j++){
            if(arr[mx_idx] < arr[j]) mx_idx = j;
        }
        swap(arr[mx_idx], arr[i]);
    }
    
    for (int i=0; i<10; i++) cout << arr[i] << ' ';
}
