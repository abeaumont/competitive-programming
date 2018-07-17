// https://www.codechef.com/JULY18A/problems/NMNMX
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int M = 1000000007, N = 5000;

ll b[N+1][N+1];
int t, n, k, a[N+1];

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % M, e >> 1);
	return e & 1 ? x * a % M : x;
}

int main() {
	for (int i = 0; i <= N; i++) b[i][0] = 1;
	for (int i = 1; i <= N; i++) {
		b[i][i] = 1;
		for (int j = 1; j < i; j++) {
			b[i][j] = (b[i - 1][j - 1] + b[i - 1][j]) % (M - 1);
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll c = b[n - 1][k - 1];
		ll x = 1;
		for (int i = 1; i < n - 1; i++) {
			ll d = c;
			if (i >= k - 1) d = (d - b[i][k - 1]) % (M - 1);
			if (i + k <= n) d = (d - b[n - i - 1][k - 1]) % (M - 1);
			if (d < 0) d += (M - 1);
			x = x * modpow(a[i], d) % M;
		}
		if (x < 0) x += M;
		cout << x << endl;
	}
}
