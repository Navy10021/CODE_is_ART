/*
map : Dictionary 자료구조 
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, int> m;

    // 삽입 
    m.insert(make_pair("a", 1));
    m.insert(make_pair("a", 1));
    m.insert(make_pair("b", 2));
    m.insert(make_pair("c", 3));
    m["d"] = 4;
    m["e"] = 5;

    // 출력
    for(auto iter = m.begin(); iter !=m.end(); iter++){
        cout << iter->first << ":" << iter->second << " ";
    }
    cout << "\n";

    for(auto &element : m){
        cout << element.first << ":" << element.second << " ";
    }

    // key와 연관된 원소를 pair로 리턴 
    printf("%d\n", m.find("a")->second);
    printf("%d\n", m["b"]);

    // 원소 연관된 원소 개수 
    printf("%d\n", m.count("c"));

}
