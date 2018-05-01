#include <iostream>

using namespace std;

typedef long long ll;

const ll M = 1000000007;

ll a[10001][10001];
bool b[10001][10001];

ll s(int i, int j) {
	if (j <= i) return 0;
	if (!((j - i) % 2)) return 0;
	if (i + 1 == j) return !b[i][j];
	if (a[i][j] != -1) return a[i][j];
	ll c = 0;
	if (!b[i][i + 1]) c = (c + s(i + 2, j)) % M;
	if (!b[i][j]) c = (c + s(i + 1, j - 1)) % M;
	for (int k = 2; k < j - i - 1; k += 2)
		if (!b[i][i + k + 1])
			c = (c + (s(i + 1, i + k) * s(i + k + 2, j)) % M) % M;
	a[i][j] = c;
	return c;
}

int main() {
	int c;
	cin >> c;
	for (int t = 1; t <= c; t++) {
		int p, g;
		cin >> p >> g;
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++) {
				a[i][j] = -1;
				b[i][j] = false;
			}
		for (int i = 0; i < g; i++) {
			int x, y;
			cin >> x >> y;
			b[x][y] = true;
			b[y][x] = true;
		}
		ll c = s(0, p - 1);
		if (c < 0) c += M;
		cout << "Case #" << t << ": " << c << endl;
	}
}
