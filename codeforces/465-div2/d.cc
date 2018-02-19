// http://codeforces.com/contest/935/problem/D
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef vector<ll> vi;

const ll P = 1000000007;

ll modinv(ll a, ll b) {
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

ii s(const vi &a, const vi &b, ll m, int i);

ii r(const vi &a, const vi &b, ll m, int i, ll p, ll q) {
	ll p2, q2;
	tie (p2, q2) = s(a, b, m, i + 1);
	q2 = (q2 * m) % P;
	p = ((p * q2) % P + (p2 * q) % P) % P;
	q = (q * q2) % P;
	return make_tuple(p, q);
}

ii s(const vi &a, const vi &b, ll m, int i) {
	if (i == a.size()) return make_tuple(0, 1);
	if (a[i] > 0 && b[i] > 0) {
		if (a[i] > b[i]) return make_tuple(1, 1);
		if (a[i] < b[i]) return make_tuple(0, 1);
		return s(a, b, m, i + 1);
	}
	if (a[i] == 0 && b[i] == 0) {
		ll p = m * (m - 1) / 2 % P;
		ll q = m * m % P;
		return r(a, b, m, i, p, q);
	}
	if (a[i] == 0) {
		ll p = m - b[i];
		ll q = m;
		return r(a, b, m, i, p, q);
	}
	ll p = a[i] - 1;
	ll q = m;
	return r(a, b, m, i, p, q);
}

int main() {
	ll n, m;
	cin >> n >> m;
	vi a(n);
	vi b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	ll p, q;
	tie(p, q) = s(a, b, m, 0);
	ll r = (modinv(q, P) * p) % P;
	if (r < 0) r += P;
	cout << r << endl;
}
