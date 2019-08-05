// https://codeforces.com/contest/1201/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, m = 0;
  ll s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m = max(m, x);
    s += x;
  }
  cout << (s % 2 || m * 2 > s ? "NO\n" : "YES\n");
}
