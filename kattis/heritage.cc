// https://open.kattis.com/problems/heritage
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using msi = unordered_map<string, ll>;

ll M = 1000000007;

int main() {
  int n, k, l;
  string w, s;
  cin >> n >> w;
  l = w.size();
  msi m;
  for (int i = 0; i < n; i++) {
    cin >> s >> k;
    m[s] = k;
  }
  vi dp(l + 1);
  dp[0] = 1;
  for (int i = 0; i < l; i++) {
    for (auto it : m) {
      s = it.first;
      int j = s.size();
      if (i + j <= l && w.substr(i, j) == s)
        (dp[i+j] += dp[i] * it.second % M) %= M;
    }
  }
  cout << dp[l] << '\n';
}
