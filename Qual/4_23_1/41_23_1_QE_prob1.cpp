#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void backtrack(int k, string tmp, vector<string> &out, vector<bool> &isused, const string &s) {
    int n = s.size();
    if (k == n) {
        out.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            isused[i] = true;
            tmp += s[i];
            backtrack(k + 1, tmp, out, isused, s);
            isused[i] = false;
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }
}

vector<string> str_perm(const string &s) {
    int n = s.size();
    vector<bool> isused(n, false);
    vector<string> out;
    backtrack(0, "", out, isused, s);
    return out;
}

unordered_map<char, unordered_set<char>> make_dict(const string &s) {
    unordered_map<char, unordered_set<char>> d;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            d[s[i]].insert(s[i + 1]);
        } else if (i == s.size() - 1) {
            d[s[i]].insert(s[i - 1]);
        } else {
            d[s[i]].insert(s[i + 1]);
            d[s[i]].insert(s[i - 1]);
        }
    }
    return d;
}

vector<string> check(const vector<string> &l, const unordered_map<char, unordered_set<char>> &d) {
    vector<string> out;
    for (const string &st : l) {
        bool valid = true;
        for (int i = 0; i < st.size(); i++) {
            if (i == 0) {
                if (d.at(st[i]).find(st[i + 1]) != d.at(st[i]).end()) {
                    valid = false;
                    break;
                }
            } else if (i == st.size() - 1) {
                if (d.at(st[i]).find(st[i - 1]) != d.at(st[i]).end()) {
                    valid = false;
                    break;
                }
            } else {
                if (d.at(st[i]).find(st[i + 1]) != d.at(st[i]).end() || d.at(st[i]).find(st[i - 1]) != d.at(st[i]).end()) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            out.push_back(st);
        }
    }
    return out;
}

string foo(const string &s) {
    auto d = make_dict(s);
    auto l = str_perm(s);
    auto res = check(l, d);
    return res.empty() ? "" : res[0];
}

string dedupl(const string &s) {
    string out;
    for (char c : s) {
        if (out.find(c) == string::npos) {
            out += c;
        }
    }
    return out;
}

string bar(const string &s) {
    auto d = make_dict(s);
    auto s_dedupl = dedupl(s);
    auto l = str_perm(s_dedupl);
    auto res = check(l, d);
    return res.empty() ? "" : res[0];
}

int main() {
    vector<string> slist = {"abccde", "abc", "", "abcdec"};
    for (int i = 0; i < slist.size(); i++) {
        cout << i << " " << foo(slist[i]) << endl;
    }
    for (int i = 0; i < slist.size(); i++) {
        cout << i << " " << bar(slist[i]) << endl;
    }
    return 0;
}
