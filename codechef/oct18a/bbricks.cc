// https://www.codechef.com/OCT18A/problems/BBRICKS
#include <iostream>

using namespace std;

typedef long long ll;

const ll M = 1000000007;

ll modinv(ll a, ll b) {
	ll t, q, x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b; b = a % b; a = t;
		t = x0; x0 = x1 - q * x0; x1 = t;
	}
	return x1;
}

ll binomial(ll n, ll k, ll m) {
  if (k < 0) return 0;
  ll l = min(k, n - k);
  ll a = 1, b = 1;
  for (ll i = 0; i < l; i++) {
    a = a*(n-i)%m;
    b = b*(l-i)%m;
  }
  return a*modinv(b, m)%m;
}

ll f(ll n, ll k, ll m) {
  ll s = 0, t = 1;
  for (ll i = 0; i <= min(n-k, k); i++) {
    s = (s+binomial(k-1,i-1,m)*binomial(n-k,i,m)%m*t%m)%m;
    t = t*2%m;
  }
  return s;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    ll r = f(n+1, k, M);
    if (r < 0) r+=M;
    cout << r << endl;
  }
}
