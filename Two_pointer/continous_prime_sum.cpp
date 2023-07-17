/*
소수의 연속 합 : 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수의 경우의 수
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 4000005;
vector<bool> seive(MX, true);
vector<int> primes;

int main(void){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 에라토스테네스 체(Sieve of Eratosthenes)
    for (int i=2; i*i < MX; i++){
        if (!seive[i]) continue;
        for (int j = i*i; j<MX; j+=i)
            seive[j] = false;
    }
    for (int i = 2; i < MX; i++){
        if (seive[i]) primes.push_back(i);
    }
    primes.push_back(0);
    
    // 연속되는 소수의 합 two-pointer
    int tgt, st = 0, en = 1;
    int cnt = 0;    // tmp_sum == target되는 경우의 수 
    int tmp_sum = primes[0];
    cin >> tgt;
    
    while(1){
        if (tmp_sum == tgt) cnt++;
        if (tmp_sum <= tgt) tmp_sum += primes[en++];
        if (tmp_sum > tgt) tmp_sum -= primes[st++];
        if (en == int(primes.size())) break;
    }
    cout << cnt;
}
