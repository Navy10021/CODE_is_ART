#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> Q;
    
    int t;
    string operation;
    int n;
    
    cin >> t;
    
    while(t--){
    cin >> operation >> n;
    
    if (operation == "I") Q.push_back(n);
    
    else if (operation == "D" && n == 1){
        int max_val = *max_element(Q.begin(), Q.end());
        Q.erase(remove(Q.begin(), Q.end(), max_val), Q.end());
        }
    else if (operation == "D" && n == -1){
        int min_val = *min_element(Q.begin(), Q.end());
        Q.erase(remove(Q.begin(), Q.end(), min_val), Q.end());
        }
    }
    
    if (Q.empty()) cout << "EMPTY";
    
    else if(!Q.empty()){
        int max_res = *max_element(Q.begin(), Q.end());
        int min_res = *min_element(Q.begin(), Q.end());
        cout << max_res << ' ' << min_res;
    }
}
