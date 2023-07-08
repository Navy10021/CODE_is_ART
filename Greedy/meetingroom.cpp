#include <bits/stdc++.h>
using namespace std;


// N개의 회의에 대해 겹치지 않게 하면서 회의실을 사용할 수 있는 최대 개수 
int n;
pair <int, int> s[100005];  // {end, start} : 끝나는 시간이 빠른 회의 선택해야 하므로 

// "가능한 회의" 중에서 "가장 먼저 끝나는 회의"를 선택!
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i=0; i<n; i++)
        cin >> s[i].second >> s[i].first;
    
    // end time 기준으로 정렬 -> 같다면 start time이 빠른 순으로 정렬  
    sort(s, s+n);
    
    // end time 이 순서대로 업데이트 
    int res = 0;
    int cur_time = 0;
    for (int i=0; i<n; i++){
        if (cur_time > s[i].second) continue;
        res++;
        cur_time = s[i].first;
    }
    cout << res;
}
