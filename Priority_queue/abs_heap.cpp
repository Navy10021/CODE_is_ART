/*
절대값 힙 : 배열에서 절대값이 가장 작은 값을 출력 & POP, 절대값이 여러개일 떄 가장 작은 수를 출력 & POP  
*/
#include <bits/stdc++.h>
using namespace std;

/*
struct cmp{
  bool operator()(int a, int b){    // cmp(앞에 위치할 원소, 뒤에 위치할 원소) = true 
      if (abs(a) > abs(b)) return true;
      else if(abs(a) == abs(b)){
          if (a > b) return true;
          else return false;
      }
    return false; 
  } 
};
*/

class cmp{
    public:
        bool operator() (int a, int b){
            if (abs(a) != abs(b)) return abs(a) > abs(b);   // a > b -> true
            return a > 0 && b < 0;                          // if abs(a) == abs(b) --> a > b -> true
        }
};

int main(void){
    int n, x;
    priority_queue<int, vector<int>, cmp> abs_PQ;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    while(n--){
        cin >> x;
        if (x == 0){
            if (abs_PQ.empty()) cout << 0 << '\n';
            else {
            cout << abs_PQ.top() << '\n';
            abs_PQ.pop();
            }
        }
        else {
            abs_PQ.push(x);
        }
    }
    return 0;
}
