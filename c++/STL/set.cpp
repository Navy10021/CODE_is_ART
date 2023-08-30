/*
set : 균형잡힌 이진트리. 원소 삽입/삭제/탐색 O(log n)
set/map/multiset은 자동으로 데이터 정렬된 상태 유지(오름차순)
*/
#include<iostream>
#include<set>
using namespace std;


int main(){
    set<int> s;

    // 삽입
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(1);
    s.insert(7);
    
    // 출력 
    for(auto iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " ";
    }
    printf("\n");

    // 탐색
    int arr[3] = {1,2,3};
    for (int i = 0; i<3; i++){
        int num = arr[i];

        if(s.find(num) != s.end())
            printf("Find.\n");
        else
            printf("No existed.\n");
    }

    // Set 크기
    printf("number of elements : %d\n", s.size());
    
    // s.count(k) : 원소 k의 개수 반환 -> 존재하면 1 / 존재하지 않으면 0
    printf("1 is exist? %d\n", s.count(1));
    printf("2 is exist? %d\n", s.count(2));
    
    //삭제 : s.erase(iter)
    s.erase(s.begin());
    for(auto iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " ";
    }
    printf("\n");

    // swap two set
    int arr_2[] = {1,2,3,4,5,6,7};
    set<int> s1 (arr_2, arr_2 + 3);         // 0~3까지 출력
    set<int> s2 (arr_2+3, arr_2 + 6);       // 3~6까지 출력

    for(auto iter = s1.begin(); iter != s1.end(); iter++){
        cout << *iter << " ";
    }
    printf("\n");
    for(auto iter = s2.begin(); iter != s2.end(); iter++){
        cout << *iter << " ";
    }
    printf("\n");

    s1.swap(s2);
    for(auto iter = s1.begin(); iter != s1.end(); iter++){
        cout << *iter << " ";
    }
    printf("\n");


    // 모든 원소 삭제 
    //s.clear()

}
