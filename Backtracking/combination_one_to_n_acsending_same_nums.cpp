// 1~N 자연수 중 중복 없이 M개를 고르는 수열 + 같은 수를 여러번 고르는 것이 가능 + 비내림차순
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
//int is_used[10];

void func(int k){   // 현재 k까지의 수를 선택함.
    if (k==M){      // M개를 모두 선택했다면 arr[i]에 기록한 값을 출력.
        for (int i=0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    // k=0 일떄 시작점 = 1;
    int st = 1;
    // k!=0 일때 시작점 arr[k-1] : 비내림차순(오름차순)
    if (k!=0) st = arr[k-1];
    
    for(int i=1; i <= N; i++){  // 1~N
        //if (!is_used[i]){       // 아직 i가 미사용되었다면,
            arr[k] = i;         // k번째 수를 i로 정함.
            //is_used[i] = 1;     // i를 사용했다고 표시
            func(k+1);          // k+1 수를 선택 
            //is_used[i] = 0;     // k번째 수를 i로 정한 모든 경우에 대해 확인. 다시 i를 미사용
        //}
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}
