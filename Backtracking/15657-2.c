#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
char c[10];

void func(int k, int st){
    if (k==M){
        for (int i=0; i<M; i++)
            cout << c[arr[i]] << " ";
        cout << "\n";
        return;
    }
    
    for (int i=st; i<N; i++){
        arr[k]=i;
        func(k+1, i);
    }
    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> c[i];
    sort(c, c + N);
    func(0, 0);
}
