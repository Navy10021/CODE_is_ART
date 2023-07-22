/*
허프만 코딩 : 매번가장 작은 2개의 묶음을 빼고(pop), 힙에 추가(push) 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> PQ;  // 오름차순 (1 - 2- 3- 4)
    
    int n;
    cin >> n;
    
    while (n--){
        int x;
        cin >> x;
        PQ.push(x);
    }
    
    int res = 0;
    while (PQ.size() > 1){
        int a = PQ.top(); PQ.pop();     // 가장 작은 수 
        int b = PQ.top(); PQ.pop();     // 2번째로 작은수 
        res += (a+b);
        PQ.push(a+b);
    }
    cout << res;
}

