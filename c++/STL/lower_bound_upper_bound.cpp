#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1,4,3,2,5};
    // 1. sorting
    sort(nums.begin(), nums.end());

    // 2.lower_bound : 입력값(x) 이상이 처음 나오는 위치(index) 반환.
    // 없는 경우 입력값 보다 큰 값 중 가장 작은 값의 위치 반환.
    auto lower = lower_bound(nums.begin(), nums.end(), 3);
    // 3.upper_bound : 입력값(x) 보다 큰 값이 처음 나타나는 위치(index) 반환
    auto upper = upper_bound(nums.begin(), nums.end(), 4);

    if (lower != nums.end()){
        cout << "Lower bound of 3 : " << *lower <<" at index " << (lower - nums.begin()) << "\n";
    }
    else{
        cout << "Not found.\n";
    }

    if (upper != nums.end()){
        cout << "Upper bound of 4 : " << *upper << " at index " << (upper - nums.begin()) << "\n";
    }
    else{
        cout << "Not found.\n";
    }
}
