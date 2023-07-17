/*
나무자르기 : N개의 나무로 부터 나무 M미터를 얻기 위해 절단기에 설정할 수 있는 최대 높이 구하기
{20, 15, 10, 17} -> H : 15 -> {15, 15, 10, 15}로 자르고 총 7M를 가지고 감.
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
int tree[1000002];

// H 만큼 잘랐을 때 남은 나무길이가 M 이상인가?
bool solve(int H){
    long long cur = 0;
    for (int i=0; i<N; ++i){
        if (tree[i] <= H) continue; // H 보다 작으면 continue  
        cur += (tree[i] - H);       // H 보다 긴 경우 자른 나머지값 구하기 
    }
    return cur >= M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;          // N개의 나무수, M미터 이상 
    for (int i = 0; i < N; ++i)
        cin >> tree[i];     // tree 크기 입력 
    
    // binary search 
    int st = 0;
    int en = *max_element(tree, tree+N);
    
    while (st < en){
        int mid = (st + en + 1) / 2;    // +1 주의 !
        if (solve(mid)) st = mid;       // st = mid 주의 !
        else en = mid - 1;              // en = mid - 1 주의 !
    }
    cout << st;
}
