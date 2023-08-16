#include <iostream>
#include <string>
#include <sstream>

int countWords(const std::string& str){
    std::istringstream iss(str);    // 문자열 단어 추출
    int wordCount = 0;

    while(iss >> std::ws){  // ws(공백문자)를 건너 뛰도록 한다
        wordCount++;
    }
    return wordCount;
}
