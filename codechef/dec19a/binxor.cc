// https://www.codechef.com/DEC19A/problems/BINXOR/
#include <iostream>

using namespace std;

typedef long long ll;

ll p = 1000000007;

int modinv(ll a, ll b) {
  ll t, q, x0 = 0, x1 = 1;
  if (b == 1) return 1;
  while (a > 1) {
    q = a / b;
    t = b; b = a % b; a = t;
    t = x0; x0 = x1 - q * x0; x1 = t;
  }
  return x1;
}

const int N = 1e5;
ll c[N+1];

int main() {
  ll r = 1;
  c[0] = 1;
  for (int i = 1; i <= N; i++) {
    r = r * i % p;
    c[i] = r;
  }
  int n, t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> n >> x >> y;
    int a = 0, b = 0;
    for (char z : x) a += z == '1';
    for (char z : y) b += z == '1';
    ll s = 0;
    for (int i = abs(a-b), j = 0; j <= n - max(a,b) && i <= min(n, a+b); j++, i += 2) {
      ll r = c[n];
      ll rr = c[i] * c[n - i] % p;
      r = modinv(rr, p) * r % p;
      if (r < 0) r += p;
      s += r;
      if (s >= p) s -= p;
    }
    cout << s << '\n';
  }
}
