// https://www.codechef.com/NOV17/problems/SEGPROD/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll pow(int a, int b, int p)
{
	ll x=1;
	ll y=a;
	while (b > 0) {
		if (b % 2) {
			x = (x * y) % p;
		}
		y = (y * y) % p;
		b /= 2;
	}
	return x;
}

ll modinv(int a, int p) {
	return pow(a, p - 2, p);
}

int main () {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, p, q;
		cin >> n >> p >> q;
		vl v(n);
		vl z(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			if (j > 0) {
				v[j] = (v[j] * v[j - 1]) % p;
			}
			z[j] = modinv(v[j], p);
		}
		int b = q / 64 + 2;
		vi w(b);
		for (int j = 0; j < b; j++) {
			cin >> w[j];
		}
		ll x = 0;
		int l = 0;
		int r = 0;
		for (int j = 0; j < q; j++) {
			if (!(j % 64)) {
				l = (w[j / 64] + x) % n;
				r = (w[j / 64 + 1] + x) % n;
			} else {
				l = (l + x) % n;
				r = (r + x) % n;
			}
			if (l > r) swap(l, r);
			x = l > 0 ? (v[r] * z[l - 1]) % p : v[r];
			x++;
			x %= p;
		}
		cout << x << endl;
	}
}
