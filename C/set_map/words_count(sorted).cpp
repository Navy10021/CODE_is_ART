#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
1. 빈도수가 높은 단어 앞에 배치
2. 단어 길이가 길수록 앞에 배치
3. 알파벳 사전 순
*/
bool compare(pair<string, int> a, pair<string, int> b){
    // 1. 빈도수 : 많은게 앞에
    if (a.second != b.second){
        return a.second > b.second;
    }
    // 2. 길이순 : 긴게 앞에
    else if (a.first.length() != b.first.length()){
        return a.first.length() > b.first.length();
    }
    // 3. 사전순 : 알파벳 빠른게 앞에
    else{
        return a.first < b.first;
    }
}

int main(){
    int num_words, min_length;
    cin >> num_words >> min_length;

    // map <word : count>
    map<string, int> m;

    while(num_words--){
        string word;
        cin >> word;
        // 0. 길이가 M 이상
        if(word.length() >= min_length){
            m[word]++;
        }
    }
    // map -> vector로 변환하여 정렬
    vector<pair<string, int>> wordVector(m.begin(), m.end());
    sort(wordVector.begin(), wordVector.end(), compare);

    // 출력
    for (const auto &pair : wordVector){
        cout << pair.first << " (" << pair.second << ")\n";
    }
    return 0;
}

