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
    int w = n;
    std::vector<std::string> pallist;

    while (w) {
        for (int i = 0; i < n - w + 1; ++i) {
            int flag = 0;
            if (palindrome(s.substr(i, w))) {
                flag = 1;
                for (const std::string& p : pallist) {
                    if (substring(p, s.substr(i, w))) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1) {
                pallist.push_back(s.substr(i, w));
            }
        }
        w -= 1;
    }

    // Sorting the output
    std::vector<std::string> out;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            std::string sub = s.substr(i, j - i);
            if (std::find(pallist.begin(), pallist.end(), sub) != pallist.end()) {
                out.push_back(sub);
            }
        }
    }

    return out;
}

int main() {
    std::string s1 = "kabccbadzdefgfeda";
    std::string s2 = "kabccba dzabccbaza";
    std::string s3 = "asdsa azazza";

    auto print_result = [](const std::string& s) {
        std::vector<std::string> result = max_palindromes(s);
        for (const auto& str : result) std::cout << str << " ";
        std::cout << std::endl;
    };

    print_result(s1);
    print_result(s2);
    print_result(s3);

    return 0;
}
