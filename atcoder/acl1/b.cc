// https://atcoder.jp/contests/acl1/tasks/acl1_b
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
using ll = long long;

vector<ll> factors(ll n) {
  vector<ll> f;
  for (ll x = 2; x * x <= n; x++) {
    ll p = 1;
    while (n % x == 0) {
      p *= x;
      n /= x;
    }
    if (p > 1) f.push_back(p);
  }
  if (n > 1) f.push_back(n);
  return f;
}

ll f(vector<ll> &fs, vector<ll> &rs, int i) {
  if (i == fs.size()) {
    bool ok = 0;
    for (ll r : rs)
      if (r) {
        ok = 1;
        break;
      }
    return ok ? crt(rs, fs).first : 1000000000000000000LL;
  }
  ll mn = f(fs, rs, i + 1);
  rs[i] = fs[i] - 1;
  mn = min(mn, f(fs, rs, i + 1));
  rs[i] = 0;
  return mn;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  vector<ll> fs = factors(n);
  if (fs[0] % 2 == 0) fs[0] *= 2;
  vector<ll> rs(fs.size());
  cout << f(fs, rs, 0) << endl;
}
