// vector arr = {1,3,4,2} start = 1, end = 2 -> 3, 4

#include <bits/stdc++.h>
using namespace std;

vector<char> slicing(vector<char>& arr, int s, int e){
    
    // starting & ending iteration
    auto start = arr.begin() + s;
    auto end = arr.begin() + e + 1;
    
    // To store the sliced vector
    vector<char> res(e - s + 1);
    
    // copy vector
    copy(start, end, res.begin());
    
    return res;
}

// print vector function
void print_vecotr(vector<char>& arr){
    for (auto& i : arr){
        cout << i << ' ';
    }
}

// check
int main(){
    vector<char> arr = {'A','B','C','D','E'};
    int s = 2, e = 5;
    
    vector<char> ans;
    ans = slicing(arr, s, e);
    
    print_vecotr(ans);
}
