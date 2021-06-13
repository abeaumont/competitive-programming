// https://atcoder.jp/contests/abc199/tasks/abc199_a
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio();
  ll a, b, c;
  cin >> a >> b >> c;
  if (a * a + b * b < c * c) cout << "Yes\n";
  else
    cout << "No\n";
}
