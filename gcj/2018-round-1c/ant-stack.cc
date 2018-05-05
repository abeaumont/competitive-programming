// https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e0a8
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unordered_map<ll, ll> m;

ll a[101];
int n;
m dp;

int s(int i, ll w) {
	if (i < 0) return 0;
	ll k = ll(i * 100000001) + w;
	if (dp.count(k)) return dp[k];
	int m = s(i - 1, w);
	if (a[i] <= w) m = max(m, 1 + s(i - 1, min(w - a[i], a[i] * 6)));
	dp[k] = m;
	return m;
}

int main() {
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		dp.clear();
		int m = s(n - 1, 100000000);
		cout << "Case #" << T << ": " << m << endl;
	}
}
