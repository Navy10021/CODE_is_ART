#include <iostream>
#include <set>
using namespace std;

void generateSubstrings(const string& str, set<string>& uniqueSubstrings) {
    int n = str.length();

    for (int len = 1; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            string substr = str.substr(start, len);
            uniqueSubstrings.insert(substr);
        }
    }
}

int main() {
    string input;
    cin >> input;

    set<string> uniqueSubstrings;

    generateSubstrings(input, uniqueSubstrings);

    for (const string& substr : uniqueSubstrings) {
        cout << substr << "\n";
    }
    cout << uniqueSubstrings.size() << "\n";

    return 0;
}
