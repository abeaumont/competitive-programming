// https://atcoder.jp/contests/abc139/tasks/abc139_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, c = 0, m = 0, p, x;
  cin >> n >> p;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x <= p) c++;
    else m = max(m, c), c = 0;
    p = x;
  }
  cout << max(m, c) << "\n";
}
