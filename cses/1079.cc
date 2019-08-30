// https://cses.fi/problemset/task/1079/
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

ll c[1000001];

int main() {
  ll r = 1;
  for (int i = 1; i <= 1000001; i++) {
    r = r * i % p;
    c[i] = r;
  }
  int n;
  cin >> n;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    ll r = c[a];
    ll rr = c[b] * c[a - b] % p;
    r = modinv(rr, p) * r % p;
    if (r < 0) r += p;
    cout << r << endl;
  }
}
