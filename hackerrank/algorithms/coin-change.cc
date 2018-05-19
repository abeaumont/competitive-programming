// https://www.hackerrank.com/challenges/coin-change
#include <iostream>

using namespace std;

typedef long long ll;

int a[51];
int n, m;
ll c[251][51];

ll f(int n, int i) {
	if (n == 0) return 1;
	if (c[n][i] != -1) return c[n][i];
	ll b = 0;
	for (int k = i; k < m; k++)
		if (a[k] <= n)
				b += f(n - a[k], k);
	c[n][i] = b;
	return b;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			c[i][j] = -1;
	for (int i = 0; i < m; i++) cin >> a[i];
	cout << f(n, 0) << endl;
}
