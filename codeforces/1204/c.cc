// https://codeforces.com/contest/1204/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  vvi d(n, vi(n, 1000000000));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      if (s[j] == '1') d[i][j] = 1;
  }
  cin >> m;
  vi p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  vi r;
  r.push_back(p[0] + 1);
  int c = p[0];
  for (int i = 0; i < m - 2; i++) {
    if (d[c][p[i+2]] < d[c][p[i+1]] + d[p[i+1]][p[i+2]]) {
      if (r.back() == p[i + 1] + 1) {
        r.push_back(p[i] + 1);
        c = p[i];
        i--;
        continue;
      }
      r.push_back(p[i + 1] + 1);
      c = p[i + 1];
    }
  }
  if (r.back() == p[m - 1] + 1) r.push_back(p[m - 2] + 1);
  r.push_back(p[m - 1] + 1);
  cout << r.size() << "\n";
  for (int i = 0; i < r.size(); i++)
    cout << r[i] << " \n"[i == r.size() - 1];
}
