// https://www.codechef.com/MARCH18A/problems/CHEFKNN
#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 163577857;

ll cache[2501][2501];

ll t(ll n, ll k) {
	if (!n || !k) return 1;
	if (n == 1) return k + 1;
	if (n <= 2500 && k <= 2500 && cache[n][k]) return cache[n][k];
	ll c = t(n, k - 1);
	for (int i = 1; i <= n; i++)
		c = (c + ((n - i + 1) * t(n - i, k - 1) % MOD)) % MOD;
	if (n <= 2500 && k <= 2500) cache[n][k] = c;
	return c;
}

ll s(ll n, ll k) {
	ll c = 0;
	for (int i = 1; i <= n; i++)
		c = (c + (n - i + 1) * t(n - i, k - 1) % MOD) % MOD;
	return c;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i <= 2500; i++)
		for (int j = 0; j <= 2500; j++)
			cache[i][j] = 0;
	while (t--) {
		int n, k;
		cin >> n >> k;
		ll c = s(n, k);
		if (c < 0) c += MOD;
		cout << c << endl;
	}
}
