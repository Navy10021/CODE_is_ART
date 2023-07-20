/*
보석 털기 : N개의 보석, 무게 M & 가격 V 
K개의 가방, 담을 수 있는 무게 C && 최대 1개만 넣을 수 있음.
훔칠 수 있는 보석의 '최대 가격'?

Tip : 가장 가격(price)이 높은 보석부터 확인하며,
      보석을 담을 수 있는 가방(K) 중 최대무게(C)가 가장 작은 가방을 이용해 보석을 담는 게 이득
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> jewel[300000];   // <price, weight>
multiset<int> bag;               // 자동으로 오름차순 정렬 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;          // n:보석의 개수, k:가방의 개수 
    
    for(int i=0; i<n; i++)
        cin >> jewel[i].second >> jewel[i].first;
    sort(jewel, jewel+n);  // price 순으로 정렬 
    
    for(int i=0; i<k; i++){
        int c;          // c:가방에 담을 수 있는 최대 무게 
        cin >> c;
        bag.insert(c);
    }
    
    int res = 0;
    
    for(int i = n-1; i >= 0; i--){  // 가격(price)이 높은 순의 보석을 확인하면서
        int weight, price;
        tie(price, weight) = jewel[i];
        auto it = bag.lower_bound(weight); // weight 보다 큰 가장 작은 가방의 iterator  
        if (it == bag.end()) continue;     // weight이상의 가방이 없으면 continue
        res += price;
        bag.erase(it);
    }
    cout << res;
}
