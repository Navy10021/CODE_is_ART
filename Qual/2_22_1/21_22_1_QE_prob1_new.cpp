#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool palindrome(const std::string& s) {
    return s == std::string(s.rbegin(), s.rend());
}

bool substring(const std::string& s, const std::string& t) {
    return s.find(t) != std::string::npos;
}

std::vector<std::string> max_palindromes(const std::string& s) {
    int n = s.length();
    std::vector<std::string> pdlist;
    std::vector<std::string> removestr;

    for (int st = 0; st < n; ++st) {
        std::string pd = s.substr(st, 1);
        for (int en = st+1; en <= n; ++en) {
            if (palindrome(s.substr(st, en-st))) {
                pd = s.substr(st, en-st);
            }
        }
        for (const std::string& s : pdlist) {
            if (substring(s, pd)) {
                pd = "";
                break;
            }
            if (substring(pd, s)) {
                removestr.push_back(s);
            }
        }
        if (!pd.empty()) {
            pdlist.push_back(pd);
        }
    }

    for (const std::string& rs : removestr) {
        pdlist.erase(std::remove(pdlist.begin(), pdlist.end(), rs), pdlist.end());
    }
    
    return pdlist;
}

int main() {
    std::string s1 = "kabccbadzdefgfeda";
    std::string s2 = "kabccba dzabccbaza";
    std::string s3 = "asdsa azazza";
    std::string s4 = "kkak";

    std::vector<std::string> result1 = max_palindromes(s1);
    for (const auto& s : result1) std::cout << s << " ";
    std::cout << std::endl;

    std::vector<std::string> result2 = max_palindromes(s2);
    for (const auto& s : result2) std::cout << s << " ";
    std::cout << std::endl;

    std::vector<std::string> result3 = max_palindromes(s3);
    for (const auto& s : result3) std::cout << s << " ";
    std::cout << std::endl;

    std::vector<std::string> result4 = max_palindromes(s4);
    for (const auto& s : result4) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
