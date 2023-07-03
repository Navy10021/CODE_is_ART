#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ABC";
    sort(s.begin(), s.end());
    do {
        cout << s << ' ';
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}
