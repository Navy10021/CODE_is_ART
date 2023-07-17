/*
연속한 숫자의 합 : 주어진 배열에서 연속되는 구간의 합이 target인 경우의 수 개수
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
vector<int> nums;
int n, target;

int main(void){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> target;
    
    // array 만들기 
    int num;
    for(int i; i<n; i++){
        cin >> num;
        nums.push_back(num);
    }
    nums.push_back(0);  // 마지막 원소를 채워줘야함.
    
    
    // 연속되는 원소들의 합 two-pointer
    int st = 0, en = 1;
    int cnt = 0;    // tmp_sum == target되는 경우의 수 
    int tmp_sum = nums[0];
    
    while(1){
        if (tmp_sum == target) cnt++;
        if (tmp_sum <= target) tmp_sum += nums[en++];
        if (tmp_sum > target) tmp_sum -= nums[st++];
        if (en == int(nums.size())) break;
    }
    cout << cnt;
}
