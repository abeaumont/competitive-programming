// https://codeforces.com/contest/1304/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    reverse(b[i].begin(), b[i].end());
  }
  vector<tuple<int, int>> ps;
  string p;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) p = a[i];
    for (int j = i + 1; j < n; j++) {
      if (a[i] == b[j]) {
        ps.push_back({i, j});
        break;
      }
    }
  }
  int k = ps.size();
  cout << (k * m * 2) + p.size() << '\n';
  for (int i = 0; i < k; i++)
    cout << a[get<0>(ps[i])];
  cout << p;
  for (int i = k-1; i >= 0; i--)
    cout << a[get<1>(ps[i])];
  cout << '\n';
}
