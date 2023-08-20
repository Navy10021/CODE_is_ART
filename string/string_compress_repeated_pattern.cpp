#include <iostream>
#include <string>

std::string compressRepeatedPattern(const std::string &input) {
    size_t len = input.length();
    std::string compressed;

    for (size_t patternLen = 1; patternLen <= len / 2; ++patternLen) {
        std::string pattern = input.substr(0, patternLen);
        size_t i = patternLen;

        while (i + patternLen <= len) {
            if (input.substr(i, patternLen) == pattern) {
                i += patternLen;
            } else {
                break;
            }
        }

        if (i >= len) {
            return std::to_string(len / patternLen) + "[" + pattern + "]";
        }
    }

    return input;
}

int main() {
    std::string input = "ABABAB";
    //std::cout << "Enter a string: ";
    //std::cin >> input;

    std::string compressed = compressRepeatedPattern(input);
    std::cout << "Compressed string: " << compressed << std::endl;

    return 0;
}
