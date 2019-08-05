// https://codeforces.com/contest/1201/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi=vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi a(m, vi(5));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++)
      a[j][s[j] - 'A'] ++;
  }
  vi b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  ll s = 0;
  for (int i = 0; i < m; i++) {
    int M = a[i][0];
    for (int j = 1; j < 5; j++) M = max(M, a[i][j]);
    s += (M * b[i]);
  }
  cout << s << "\n";
}
