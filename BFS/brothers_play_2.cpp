/*
순간이동 -> 0초
*/
#include <bits/stdc++.h>
using namespace std;

const int limit = 100001;
int dist[limit+2];   // 0
int my, bro;
queue<int> Q;

// 순간이동(0초)
void teleport(int p){
    int tmp = p;
    if (!tmp) return;
    while(tmp < limit && !dist[bro]){
        if (!dist[tmp]){
            dist[tmp] = dist[p];
            Q.push(tmp);
            if (tmp==bro) return;
        }
        //tmp <<= 1;  // 이동 p*2 -> p*2*2 -> p*2*2*2 -> p*2*2*2*2 ... 
        tmp = tmp*2;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> my >> bro;
    dist[my] = 1;
    Q.push(my);
    teleport(my);
    while (!dist[bro]){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur+1, cur-1}){
            if(nxt < 0 || nxt >= limit) continue;
            if(dist[nxt]) continue;
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
            teleport(nxt);
        }
    }
    cout << dist[bro]-1;
}
