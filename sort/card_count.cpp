#include <bits/stdc++.h>
using namespace std;

// 카드 중가장 많이 가지고 있는 정수를 출력 

int N;
long long card[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    // 카드 크기순 정렬
    for (int i=0; i<N; i++)
        cin >> card[i];
    sort(card, card+N);
    
    int cnt = 0;
    long long max_val = -(1ll << 62) - 1;
    int max_cnt = 0;
    
    for (int i=0; i<N; i++){
        if (i == 0 || card[i-1] == card[i]) cnt++;  // i == 0 또는 이전카드와 같은 경우 count++
        else{   // 새로운 수가 등장한 경우 max count를 업데이트하고, count = 1
            if (cnt > max_cnt){
                max_cnt = cnt;
                max_val = card[i-1];
            }
            cnt = 1;
        }
    }
    if (cnt > max_cnt) max_val = card[N-1];
    cout << max_val;
}
