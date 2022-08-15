// https://atcoder.jp/contests/agc053/tasks/agc053_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  multiset<ll, std::greater<ll>> s;
  int n;
  cin >> n;
  vector<ll> a(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
    s.insert(a[2 * n - i - 1]);
    auto it = s.begin();
    sum += *it;
    s.erase(it);
  }
  cout << sum << '\n';
}
