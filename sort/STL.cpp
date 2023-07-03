#include <bits/stdc++.h>
using namespace std;


int main(void){
    int a[6] = {1,4,5,2,6,7};
    sort(a, a+6);
    for (int i=0; i<6; i++) cout << a[i] << ' ';
    cout << '\n';
    
    // vector 
    vector<int> b = {1,4,5,2,6,7};
    sort(b.begin(), b.end());    // (b.begin, b.begin() + 6)
    for (int i=0; i<6; i++) cout << b[i] << ' ';
    
}


