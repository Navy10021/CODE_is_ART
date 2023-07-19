/*
보석 털기 : N개의 보석, 무게 M & 가격 V 
K개의 가방, 담을 수 있는 무게 C && 최대 1개만 넣을 수 있음.
훔칠 수 있는 보석의 '최대 가격'?
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
    
    for(int i = n-1; i >= 0; i--){  // price가 큰 순서데로 뽑아서
        int weight, price;
        tie(price, weight) = jewel[i];
        auto it = bag.lower_bound(weight); // bag의 무게 중 보석의 weight 보다 같거나 큰 숫자 등장하는 인덱스의 이터레이터  
        if (it == bag.end()) continue;
        res += price;
        bag.erase(it);
    }
    cout << res;
}
