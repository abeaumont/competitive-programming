// https://www.codechef.com/JULY18A/problems/EQUILIBR
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1000000007;

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % M, e >> 1);
	return e & 1 ? x * a % M : x;
}

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

int main() {
	int n, k;
	cin >> n >> k;
	ll x = n * modinv(modpow(2, n - 1), M) % M;
	x = (1 - x) % M;
	if (x < 0) x += M;
	cout << x << endl;
}
