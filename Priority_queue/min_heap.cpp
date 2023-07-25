/*최소 힙 : 배열에서 가장 작은 값을 출력하고 제거하는 프로그램*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    while(n--){
        cin >> x;
        if (x){
            PQ.push(x);
        }
        else{
            if(PQ.empty()) cout << 0 << '\n';
            else{
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        }
    }
    return 0;
}
