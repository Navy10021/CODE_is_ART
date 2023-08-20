#include <iostream>
#include <string>

// genCombination : 각 인덱스에서 문자를 포함하거나, 제외하여 주어진 문자열의 조합 생성
void genCombination(std::string& str, std::string& curr, int idx, int n){
    /*
    if (idx == str.length()){
        std::cout << curr << "\n";
        return;
    }
    */
   if (curr.length() == n){
    std::cout << curr << "\n";
    return;
   }
   if (idx >= str.length()){
    return;
   }

    // 1.현재 인데스의 문자를 포함.
    curr.push_back(str[idx]);
    genCombination(str, curr, idx+1, n);

    // 2.현재 인덱스의 문자를 미포함.
    curr.pop_back();
    genCombination(str, curr, idx+1, n);
}

// printCombination : 프로세스 초기화. ""에서 시작.
void printCombination(const std::string& str, int n){
    std::string curr = "";
    genCombination(const_cast<std::string&> (str), curr, 0, n);
}

int main(){
    std::string input = "ABCD";
    int n = 3;
    printCombination(input, n);
    return 0;
}
