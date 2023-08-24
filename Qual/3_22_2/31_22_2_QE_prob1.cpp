#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string s, int k, vector<string>& result) {
    static vector<bool> isused(10, false);
    static char Res[10];
    if (s[k] == '\0') {
        Res[k] = '\0';
        result.push_back(string(Res)); // Add the permutation to the result
    } else {
        for (int i = 0; s[i] != '\0'; i++) {
            if (!isused[i]) {
                Res[k] = s[i];
                isused[i] = true;
                backtrack(s, k + 1, result);
                isused[i] = false;
            }
        }
    }
}

int main() {
    string s = "ABCD";
    vector<string> result;
    cout << "string is \"" << s << "\"\n";
    cout << "Permutations are: \n";
    backtrack(s, 0, result);
    for (const auto& str : result) {
        cout << str << '\n';
    }
    return 0;
}
