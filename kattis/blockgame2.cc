// https://open.kattis.com/problems/blockgame2
#include <iostream>

using namespace std;

typedef long long ll;

bool c(ll n, ll m) {
	if (n == m) return true;
	if (n < m) swap(n, m);
	if (n % m == 0) return true;
	if (n / m >= 2) return true;
	return !c(m, n - m);
}

int main() {
	ll n, m;
	cin >> n >> m;
	cout << (c(n, m) ? "win\n" : "lose\n");
}
