// https://cses.fi/problemset/task/1086/
#include <iostream>

using namespace std;

typedef long long ll;

ll s(ll n, int k) {
  if (n < k) return -1;
  if (n < 2 * k + 1) return 0;
  if (n <= k * 10) {
    ll a = 2 * k + 1;
    ll r = 1;
    while (a + k <= n) {
      a += k;
      r += 1;
    }
    return r;
  }
  ll a = k * 10 + 1;
  ll r = 1;
  ll next = (a + r) * 10;
  while (next + k <= n) {
    a = (a + r) * 10;
    r *= 10;
    next = (a + r) * 10;
  }
  r *= 10;
  ll d1 = next - a * 9;
  ll d = a;
  ll i = 1;
  ll r2 = r;
  if (a + d1 + k <= n) {
    i++;
    a += d1;
    r2 += r;
    while (a + d + k <= n) {
      i++;
      a += d;
      r2 += r;
    }
  }
  return r2 + s(n - a, k + (i == 1));
}

int main () {
    ll n;
    cin >> n;
    cout << s(n, 0) << endl;
}
