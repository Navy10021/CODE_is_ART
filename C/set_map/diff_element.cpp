#include <iostream>
#include <set>
using namespace std;


main(){
    set<int> A, B;
    // A 집합 원소 입력
    int N, M;
    int num;
    cin >> N >> M;

    while(N--){
        cin >> num;
        A.insert(num);
    }

    while(M--){
        cin >> num;
        B.insert(num);
    }
    // 대칭차집합
    set<int> symDiff;
    for(int e : A){
        if (B.find(e) == B.end()){
            symDiff.insert(e);
        }
    }
    for(int e: B){
        if (A.find(e) == A.end()){
            symDiff.insert(e);
        }
    }
    int res = symDiff.size();
    cout << res << "\n";
}
