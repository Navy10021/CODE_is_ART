#include<iostream>
#include<set>
using namespace std;

int main(){

    set <string> arr = {"Dance"};
    int n;
    cin >> n;

    while(n--){
        string str1, str2;
        cin >> str1 >> str2;
        if (arr.find(str1) != arr.end() || arr.find(str2) != arr.end()){
            arr.insert(str1);
            arr.insert(str2);
        }
    }
    cout << arr.size() -1 << "\n";  // Dance 제외

    for(auto e : arr){
        cout << e << " ";
    }
}
