/*
수강신청(Enrolment)
1. 클릭 2번 : 중복된 대기목록 삭제(2번째 로그만 남김)
2. 맨 앞에서 최대 수강 가능 인원 3명 선정 -> 출력 
key : val = 학번 : 순번 -> 같은 학번이 들어오면 순번 업데이트 -> 순번을 기준으로 정렬 
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

int main(void){
    unordered_map<string, int> m;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    
    int order = 1;
    for(int i = 0; i < n; i++){
        string s_num;
        cin >> s_num;
        m[s_num] = order;
        order ++;
    }
    // 결과값 정렬 
    vector<pair<string, int>> res(m.begin(), m.end());
    sort(res.begin(), res.end(), cmp);

    cout << "My answer is " << '\n';
    for (auto e : res){
        if (k == 0) break; 
        cout << e.first << ' ';
        k--;
        
    }
}
