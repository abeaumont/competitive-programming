// https://www.hackerrank.com/challenges/crush
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
	ll n, m;
	cin >> n >> m;
	vll v(n + 2, 0);
	while (m--) {
		int a, b, k;
		cin >> a >> b >> k;
		v[a] += k;
		v[b + 1] -= k;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += v[i];
		m = max(m, sum);
	}
	cout << m << endl;
}
