// https://www.codechef.com/FEB18/problems/BROCLK
#include <iostream>

using namespace std;

typedef __int128 ll;

int modinv(ll a, ll b) {
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	return x1;
}

void mult(ll F[2][2], ll M[2][2], ll p) {
  ll a00 = (F[0][0] * M[0][0] % p + F[0][1] * M[1][0] % p) % p;
  ll a01 = (F[0][0] * M[0][1] % p + F[0][1] * M[1][1] % p) % p;
  ll a10 = (F[1][0] * M[0][0] % p + F[1][1] * M[1][0] % p) % p;
  ll a11 = (F[1][0] * M[0][1] % p + F[1][1] * M[1][1] % p) % p;
  F[0][0] = a00;
  F[0][1] = a01;
  F[1][0] = a10;
  F[1][1] = a11;
}

void pow(ll F[2][2], ll n, ll x, ll p) {
  if (n <= 1) return;
  ll M[2][2] = {{2 * x, -1}, {1, 0}};
  pow(F, n / 2, x, p);
  mult(F, F, p);
  if (n % 2) mult(F, M, p);
}

ll chevyshev(ll n, ll x, ll p) {
  if (n == 1) return x;
  ll F[2][2] = {{2 * x, -1}, {1, 0}};
  pow(F, n - 1, x, p);
  return (F[0][0] * x % p + F[0][1]) %p;
}

int main() {
  int T;
  cin >> T;
  const ll mod = 1000000007;
  while (T--) {
    long long l, d, t;
    cin >> l >> d >> t;
    ll x = d * modinv(l, mod);
    ll r = l * chevyshev(t, x, mod) % mod;
    if (r < 0) r += mod;
    cout << (long long)r << endl;
  }
}
