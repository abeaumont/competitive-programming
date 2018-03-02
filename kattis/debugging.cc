// https://open.kattis.com/problems/debugging
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll cache;

ll d(ll n, ll r, ll p) {
	if (n == 1) return 0;
	if (n == 2) return p + r;
	if (cache[n] != -1) return cache[n];
	ll c = ll(n - 1) * p + r;
	ll b = 0;
	for (ll i = 1; i < n - 1; i++) {
		ll a = (n + (i - 1)) / i - 1;
		if (a == b) continue;
		b = a;
		c = min(c, d(i, r, p) + a * p + r);
	}
	cache[n] = c;
	return c;
}

int main() {
	ll n, r, p;
	cin >> n >> r >> p;
	cache = vll(n + 1, -1);
	cout << d(n, r, p) << endl;
}
