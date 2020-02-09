// https://codeforces.com/contest/1300/problem/E
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, x;
  cin >> n;
  vector<tuple<ll, ll>> a;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ll s = x, c = 1, t, d;
    while (!a.empty()) {
      tie(t, d) = a.back();
      if (double(t)/d < double(s)/c) break;
      s += t;
      c += d;
      a.pop_back();
    }
    a.push_back({s, c});
  }
  cout << setprecision(20);
  for (int i = 0; i < a.size(); i++) {
    ll s, c;
    tie(s, c) = a[i];
    double r = double(s)/c;
    for (int j = 0; j < c; j++)
      cout << r << '\n';
  }
}
