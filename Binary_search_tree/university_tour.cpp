/*
Tour List : 1 : i-th 명소 지정 or 지정 해지  2 : x-th 시계방향으로 x 만큼 이동  3 : 명소 도달까지 움직여야할 칸 수 
*/
#include <bits/stdc++.h>
using namespace std;

int N, Q, t, x;           // N : 구역 개수  Q : 쿼리 개수   t : 명소 or Not 명소   x : 이동 
int curr = 1;             // 현재 위치(1)에서 -> 시계방향 이동 
set<int> univ;            // 명소들의 위치를 저장

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++){
        cin >> t;
        if (t) univ.insert(i);  // 명소(1)만의 인덱스 저장 
        }
        
    while(Q--){
        cin >> t;
        if (t == 1){
            cin >> x;
            if (univ.find(x) != univ.end()) univ.erase(x);  // if x in univ_set -> erase 
            else univ.insert(x);
        }
        
        else if (t == 2){
            cin >> x;
            curr = (curr + x - 1) % N + 1;    // Cycle 에서 시계방향으로 x-th 만큼 이동!!!
        }
        
        else if (t == 3){
            if (univ.empty()) cout << -1 << '\n';
            else{
                auto it = univ.lower_bound(curr);   // curr와 같거나 curr 보다 큰 가장 작은값의 point
                if (it != univ.end())
                    cout << *it - curr << '\n';     // it의 값(가장 근접한 명소 위치) - 현재 위치 = 이동해야 하는 거리 
                else
                    cout << N - curr + *univ.begin() << '\n';
            }
        }
    }
}
