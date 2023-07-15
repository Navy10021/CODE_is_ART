#include <bits/stdc++.h>
using namespace std;

// N개의 숫자카드. 정수 M개가 주어졌을 때, 숫자카드를 몇개 가지고 있는지

/* 
특정 숫자를 insert할 때, 오름차순이 유지된 채 가장 왼쪽과 오른쪽을 찾음(오른쪽 - 왼쪽 = 인덱스 횟수).
1. 왼쪽 인덱스 찾기 
a[mid] >= target : 왼쪽 구간 
a[mid] < target : 오른쪽 구간

2. 오른쪽 인덱스 찾기 
a[mid] > target : 왼쪽 구간
a[mid] <= target : 오른쪽 구간 
*/

int a[100005];
int n;          // array size 

int lower_idx(int target, int len){
    int st = 0;
    int en = len;       // end start index는 array last element 다음 위치이므로 len
    while (st < en){
        int mid = (st + en) / 2;
        if (a[mid] >= target)
            en = mid;
        else    // a[mid] < target
            st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while (st < en){
        int mid = (st + en) / 2;
        if (a[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    
    int m;
    cin >> m;
    while(m--){
        int tgt;
        cin >> tgt;
        cout << upper_idx(tgt, n) - lower_idx(tgt, n) << '\n';  // 카드의 개수 = 오른쪽 인덱스 - 왼쪽 인덱스 
    }
}

