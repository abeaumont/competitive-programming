// http://codeforces.com/contest/984/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) { return __gcd(a, b); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	while (n--) {
		ll p, q, b;
		cin >> p >> q >> b;
		q /= gcd(q, p);
		for (b = gcd(q, b); b != 1; b = gcd(q, b)) {
			while (!(q % b)) q /= b;
		}
		cout << (q == 1 ? "Finite\n" : "Infinite\n");
	}
}
