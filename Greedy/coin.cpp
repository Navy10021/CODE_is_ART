#include <iostream>
using namespace std;


int n, k;   // 동전 종류, 전체 합 
int coin[15];      // 동전 값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int res = 0;
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) 
        cin >> coin[i];
        
    for (int i = n-1; i >= 0; i--){
        res += k / coin[i];
        k %= coin[i];
    }
    cout << res;
}
