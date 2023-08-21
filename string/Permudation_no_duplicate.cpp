#include <iostream>
#include <string>
#include <vector>

void generatorPerumtation(std::string& str, int idx, std::vector<std::string>& res){
    if (idx == str.size()){
        res.push_back(str); // Store the permutation 
        return;
    }

    for (int i = idx; i < str.size(); ++i){
        // add to skip duplicate
        if (i != idx && str[i] == str[idx]){
            continue;
        }

        std::swap(str[idx], str[i]);
        generatorPerumtation(str, idx+1, res);
        std::swap(str[idx], str[i]);    // Backtrack by swapping back
    }
}

int main(){
    std::string input = "AAB";
    std::vector<std::string> ans;
    generatorPerumtation(input, 0, ans);

    for(const std::string& perm : ans){
        std::cout << perm << "\n";
    }
}
