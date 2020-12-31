// https://open.kattis.com/problems/candydivision
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<ll, int>;
using vi = vector<ll>;
using vii = vector<ii>;

vii f;
vi ds;

void d(int i, ll x) {
  if (i == f.size()) {
    ds.push_back(x);
    return;
  }
  int c;
  ll k, y = 1;
  tie(k, c) = f[i];
  for (int j = 0; j <= c; j++) d(i + 1, x * y), y *= k;
}

int main() {
  ll n;
  cin >> n;
  for (ll i = 2; i * i <= n; i++) {
    int c = 0;
    while (!(n % i)) {
      c++;
      n /= i;
    }
    if (c) f.push_back({i, c});
  }
  if (n > 1) f.push_back({n, 1});
  d(0, 1);
  sort(ds.begin(), ds.end());
  for (int i = 0; i < ds.size(); i++)
    cout << ds[i] - 1 << " \n"[i == ds.size() - 1];
}
