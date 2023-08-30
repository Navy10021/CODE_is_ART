#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool cmp(const int first, const int second){
    return first > second;
    }

int main(){
    int arr[5] = {3,4,1,2,5};
    vector<int> arr2 = {3,4,1,2,5};

    // Sorting
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr, arr + n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << " ";

    sort(arr2.begin(), arr2.end());
    for(auto num : arr2){
        cout << num << " ";
    }
    cout << " ";

    // Stable sort : 동일한 값 사이의 상대적인 순서가 유지.
    stable_sort(arr, arr + n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << " ";

    // max_element
    printf("%d\n", *max_element(arr, arr+n));
    cout << " ";

    // min_element
    printf("%d\n", *min_element(arr2.begin(), arr2.end()));
    cout << " ";

    // next_permutation : 다음 순열로  재배치해주는 함수. 더 이상 다음 순열이 없다면 false 반환 
    vector<string> str = {"A","B","C"};
    do {
        for (auto c : str){
            cout << c << " ";
        }
        cout << "\n";
    } while (next_permutation(str.begin(), str.end()));

    return 0;
}
