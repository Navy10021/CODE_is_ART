#include <bits/stdc++.h>
using namespace std;

// N개의 숫자카드. 정수 M개가 주어졌을 때, 숫자카드를 몇개 가지고 있는지
//특정 숫자를 insert할 때, 오름차순이 유지된 채 가장 왼쪽과 오른쪽을 찾음(오른쪽 - 왼쪽 = 인덱스 횟수).


int a[100005];
int n;          // array size 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);       // 반드시 정렬되어야 함.
    
    int m;
    cin >> m;
    while(m--){
        int tgt;
        cin >> tgt;
        cout << upper_bound(a, a+n, tgt) - lower_bound(a, a+n, tgt) << '\n';  // 카드의 개수 = 가장 오른쪽 인덱스 - 가장 왼쪽 인덱스 
    }
}

