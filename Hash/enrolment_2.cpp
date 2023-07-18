/*
수강신청(Enrolment)
1. 클릭 2번 : 중복된 대기목록 삭제(2번째 로그만 남김)
2. 맨 앞에서 최대 수강 가능 인원 3명 선정 -> 출력 

key : val = 학번 : 순번 -> 같은 학번이 들어오면 순번 업데이트 -> 순번을 기준으로 정렬 
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    
    unordered_map<string, int> m{};
    for(int i = 0; i < n; i++){
        string s_num;
        cin >> s_num;
        if (m.find(s_num) != m.end()){  // map 안에 학번이 존재하면 삭제하고, 새로운 인덱스로 생성 
            m.erase(s_num);
            m[s_num] = i;
        }
        else 
            m[s_num] = i;
    }
    // 결과값 정렬 
    vector<pair<string, int>> res(m.begin(), m.end());
    // 람다식 형태로 cmp 
    sort(res.begin(), res.end(), [](auto& a, auto& b) {return a.second < b.second;});
    
    // k 만큼 또는 그보 다 작은 경우 선택
    int en = min(k, (int)res.size());
    for (int i=0; i<en; ++i){
        cout << res[i].first << '\n';
    }
}
