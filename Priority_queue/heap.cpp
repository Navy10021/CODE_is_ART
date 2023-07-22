#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a, int b){  // 절대값이 작은값에 우선순위, 같다면 더 작은값에 우선순위 
        if (abs(a) > abs(b)) return true; 
        else if(abs(a) == abs(b)){
            if (a > b) return true;
            else return false;
        }
    return false;
    }
};

int main(void){
    priority_queue<int> PQ; // 내림차순 저장 
    //priority_queue<int, vector<int>, greater<int>> PQ;  // 오름차순 저장 : greater<int> 대소관계 바꿀때 사용
    
    PQ.push(10);
    PQ.push(5);
    PQ.push(15);
    PQ.push(20);
    
    int n = PQ.size();
    while(n--){
        cout << PQ.top() << ' ';
        PQ.pop();
    }
    cout << '\n';
    
    priority_queue<int, vector<int>, cmp> abs_PQ;
    abs_PQ.push(1);
    abs_PQ.push(-1);
    abs_PQ.push(-5);
    abs_PQ.push(5);
    abs_PQ.push(10);
    abs_PQ.push(-20);
    abs_PQ.push(15);
    
    n = abs_PQ.size();
    while(n--){
        cout << abs_PQ.top() << ' ';
        abs_PQ.pop();
    }
    
}
