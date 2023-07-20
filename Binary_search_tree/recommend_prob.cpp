/*
N개의 문제가 주어질 때 recommend(1 : 가장 어려운 문제, -1 : 가장 쉬운 문제), add, solve를 해결하는 추천 시스템 만들기
어려운 문제가 여러개라면 번호가 큰문제 && 쉬운 문제가 여러개라면 가장 번호가 작은 문제 출력 
*/

#include <bits/stdc++.h>
using namespace std;

int N, L, P, x;                  // N : 문제의 개수  L : 난이도  P : 문제 번호  x : 1 or -1
string op;
int prob_to_level[100002];       // 문제에 난이도값 저장 
set<int> level_to_prob[102];     // 난이도에 문제 array 저장 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    while(N--){
        cin >> P >> L;
        prob_to_level[P] = L;
        level_to_prob[L].insert(P);
    }
    
    cin >> N;
    while(N--){
        cin >> op;
        if (op == "recommend"){
            cin >> x;
            if (x == 1){
                for(int i=100; i>0; i--){   // 가장 난이도가 높은 것부터 확인하며, 해당 난이도 문제 중 큰 번호 
                    if (level_to_prob[i].empty()) continue;
                    cout << *prev(level_to_prob[i].end()) << '\n';
                    break;
                }
            }
            else { // x == -1
                for(int i=0; i<101; i++){
                    if (level_to_prob[i].empty()) continue;
                    cout << *level_to_prob[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (op == "add"){
            cin >> P >> L;
            prob_to_level[P] = L;
            level_to_prob[L].insert(P);
        }
        else if (op == "solved"){
            cin >> P;
            // level to prob에서 해당 문제(P) 삭제 
            level_to_prob[prob_to_level[P]].erase(P);
        }
    } 
}
