#include <iostream>
using namespace std;

// 버블정렬
int main()
{
    int arr[10] = {3,2,1,5,4,6,10,9,8,7};
    int n = 10;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1-i; j++){    
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    // print
    for (int i=0; i<10; i++) cout << arr[i] << ' ';
}
