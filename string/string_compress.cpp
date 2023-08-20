#include<iostream>
#include<string>

std::string compressString(const std::string& input){
    if (input.empty()){
        return "";
    }

    std::string compressed;
    char curr_char = input[0];
    int cnt = 1;

    for (size_t i = 1; i < input.size(); ++i){
        if (input[i] == curr_char) cnt ++;
        else {
            compressed += curr_char + std::to_string(cnt);
            curr_char = input[i];
            cnt = 1;
        }
    }
    compressed += curr_char + std::to_string(cnt);

    return (compressed.size() < input.size()) ? compressed : input;
}

int main(){
    std::string input;
    std::cin >> input;

    std::string res = compressString(input);
    std::cout << "Compressed string : " << res << "\n";

    return 0;
}
