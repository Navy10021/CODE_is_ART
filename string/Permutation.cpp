#include <iostream>
#include <string>
//#include <vector>

// void genPermutation(cost std::string& string, std::stirng& curr, std::vector<bool>& used){
void genPermutation(const std::string& string, std::string& curr, bool used[]){
    if (curr.length() == string.length()){
        std::cout << curr << "\n";
        return;
    }

    for (int i = 0; i < string.length(); ++i){
        if (!used[i]){
            used[i] = true;
            curr.push_back(string[i]);
            genPermutation(string, curr, used);
            curr.pop_back();
            used[i] = false;
        }
    }
}

void printPermutation(std::string& string){
    bool used[] = {false};
    // std::vector<bool> used(string.length(), false);
    std::string curr = "";
    genPermutation(const_cast<std::string&> (string), curr, used); 
}

int main(){
    std::string input = "ABC";
    printPermutation(input);
    return 0;
}
