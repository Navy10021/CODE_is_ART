// num cards ver 1 
#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int a[MX];
int card[MX];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    
    int m;
    cin >> m;
    for (int i=0; i<m; i++) cin >> card[i];
    for (int i=0; i<m; i++)
        cout << binary_search(a, a+n, card[i]) << ' ';
}


