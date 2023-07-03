// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/0fd334ddb06d417689cd6c944d5a0585
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.X > b.X;     // compare count 
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> arr; // pair : {cnt, num}
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bool is_seen = false;
    for (auto &a : arr) {
      if (a.Y == x) {
        is_seen = true;
        a.X++;
        break;
      }
    }
    if (!is_seen) arr.push_back({1, x});
  }
  stable_sort(arr.begin(), arr.end(), cmp);

  for (auto b : arr)
    while (b.X--) cout << b.Y << ' ';
}
