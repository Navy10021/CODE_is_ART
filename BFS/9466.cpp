#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int N;

bool isCycle(int idx){
    int cur = idx;
    for (int i=0; i < N; i++){ // N번 돌면서 s_0 -> s_1 -> s_2 ... 사이에 idx == cur 이면 has cycle
        cur = arr[cur]; // s_i -> s_i+1
        if (cur == idx) return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        // 학생 index는 1부터..
        for (int i = 1; i <= N; i++) cin >> arr[i]; // cur -> next;
        int res = 0;
        for (int i = 1; i <= N; i++)
            if(!isCycle(i))         // 사이클에 들어가지 않는 경우 answer++
                res++;
        cout << res << '\n';
    }
}

