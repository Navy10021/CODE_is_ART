#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

std::string removePunctuation(const std::string& word){
    std::string res = word;
    res.erase(std::remove_if(res.begin(), res.end(), ::ispunct), res.end());
    return res;
}

void countWordFreq(const std::string& str){
    std::istringstream iss(str);    // 문자열 파싱 
    std::map<std::string, int> wordFrequncy; // {문자 : 카운트}

    std::string word;
    int totalwords = 0;

    while(iss >> word){
        word = removePunctuation(word);
        if (!word.empty()){
            wordFrequncy[word]++;
            totalwords++;
        }
    }
    std::cout << "Total number of words : " << totalwords << "\n";

    std::string res;
    for (const auto& pair : wordFrequncy){
        if (pair.second == 1) res = "once";
        else if (pair.second == 2) res = "twice";
        else res = std::to_string(pair.second) + " times"; 
        
        std::cout << " Word " << pair.first << " appears " << res << "\n";
    }
}

int main(){
    std::string given_str;
    given_str = "Doubt thou the stars are fire Doubt that the sun doth move. Doubt truth to be a liar. But never dout I love.";
    countWordFreq(given_str);
}
