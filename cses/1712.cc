// https://cses.fi/problemset/task/1712/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 1000000007;

ll pow(ll a, ll b, ll m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) (r *= e) %= m;
    (e *= e) %= m;
    b >>= 1;
  }
  return r;
}

int main() {
  ll n, a, b, c;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    ll x = pow(b, c, M - 1);
    cout << pow(a, x, M) << endl;
  }
}
