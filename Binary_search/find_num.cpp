// 수찾기
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;          // array size 

int binary_search(int target){
    int st = 0;
    int en = n-1;
    
    while (st <= en){ // end < start 이면 target이 존재하지 않는 것으로 OUT 
        int mid = (st + en) / 2;    // min index 
        // 1. 작은 경우 왼쪽을 날림
        if (a[mid] < target)
            st = mid + 1;
        // 2. 큰 경우 오른쪽을 날림 
        else if (a[mid] > target)
            en = mid -1;
        // 3. a[mid] == target : 찾은 경우  
        else
            return 1;   // true 
    }
    return 0;       // en < st 이면 while 문 탈출 
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);   // 정렬
    
    int m;
    cin >> m;
    while (m--){
        int tgt;
        cin >> tgt;
        cout << binary_search(tgt) << '\n';
    }
}
