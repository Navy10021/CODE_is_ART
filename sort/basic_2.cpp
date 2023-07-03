#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {3,2,1,5,4,6,10,9,8,7};
    int n = 10;
    for (int i = n-1; i > 0; i--){
      // max_element(arr, arr+arr_size) // (arr_start, arr_end) // (vector.begin(), vector.end())
        swap (*max_element(arr, arr+i+1), arr[i]);     // max_element는 주소값을 리턴
    }
    
    for (int i=0; i<10; i++) cout << arr[i] << ' ';
}
