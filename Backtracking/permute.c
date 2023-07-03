#include <iostream>
using namespace std;

void permute(string& a, int l, int r){
    // base condition
    if (l == r) cout << a << ' ';
    else{
        for (int i = l; i <= r; i++){
            swap(a[l], a[i]);       // swap
            permute(a, l+1, r);     // next fixed
            swap(a[l], a[i]);       // backtracking
        }
    }
}

int main()
{
    string s = "ABC";
    int n = s.size();
    permute(s, 0, n-1);
    return 0;
}
