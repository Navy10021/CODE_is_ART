#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, M, cnt;
string str;
map<string, bool> m;

int main(){
    cin >> N >> M;

    for (int i=0; i<N; i++){
        cin >> str;
        m[str] = true;
    }
    for (int i = 0; i<M; i++){
        cin >> str;
        if (m[str]) cnt++;
    }
    cout << cnt << "\n";
}
