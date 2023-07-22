/*
우선순위 큐 : pop(); 할떄 가장 들어온 원소가 나오는 대신 우선순위가 가장 높은 원소가 나오는 Queue
Heap : 이진트리(Binary Tree) 자료구조 -> 부모노드 < 자식노드(2개)
- i 번지의 왼쪽 오른쪽 자식 : 2x, 2x+1 
- i 번지의 부모 : x / 2 
*/
#include <bits/stdc++.h>
using namespace std;

int heap[100005];   // Heap 배열 : idx 의 부모 = idx / 2 && 부모의 left = 2*idx && 부모의 right = 2*idx + 100005
int sz = 0;         // heap에 들어있는 원소의 수 

void push(int x){   // push 함수
    heap[++sz] = x; // idx 1 == root  
    int idx = sz;
    while(idx != 1){// root
        int parent = idx / 2;                   // 부모를 찾고, 부모 <= 자식 
        if (heap[parent] <= heap[idx]) break;   
        swap(heap[parent], heap[idx]);
        idx = parent;
    }
}

int top(){          // 최솟값을 반환하는 함수 
    return heap[1];
}

void pop(){         // 최솟값을 제거하는 함수 
    heap[1] = heap[sz--];   // 루트제거 처리   
    int idx = 1;
    // 왼쪽 자식의 인덱스(2*idx)가 size(sz) 보다 크면 idx는 leaf
    while(2*idx <= sz){
        int lc = 2*idx, rc = 2*idx + 1; // left child, right child 
        int min_child = lc;             // lc or rc 중 작은값 저장 
        if (rc <= sz && heap[rc] < heap[lc]) min_child = rc;
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}



void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(void){
  test();
}
