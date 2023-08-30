#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> words;

    words.push_back("banana");
    words.push_back("apple");
    words.push_back("cherry");
    words.push_back("date");
    words.push_back("blueberry");
    words.push_back("grape");

    // 1. 단어 길이 순 정렬 -> 2. 길이가 같으면 알파벳 순 정렬
    // vector -> sort(vector.begin(), vector.end())
    sort(words.begin(), words.end(), [](const string& a, const string& b){
        if(a.length() != b.length()){
            return a.length() < b.length(); // 길이순
        }
        return a < b;   // 알파벳순
    });

    for (const string& word : words){
        cout << word << "\n";
    }
    return 0;
}
