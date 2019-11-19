// https://codeforces.com/contest/2/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_map<string, int> m;
  vector<tuple<string, int>> b(n);
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    m[s] += x;
    b[i] = {s, x};
  }
  int M = -1;
  unordered_set<string> s;
  for (auto x : m)
    if (x.second > M) {
      s.clear();
      M = x.second;
      s.insert(x.first);
    } else if (x.second == M) s.insert(x.first);
  m.clear();
  for (auto x : b) {
    string t;
    int k;
    tie(t, k) = x;
    m[t] += k;
    if (m[t] >= M && s.count(t)) {
      cout << t << '\n';
      break;
    }
  }
}
