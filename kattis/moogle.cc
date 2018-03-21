// https://open.kattis.com/problems/moogle
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<int> vi;

double MAX = 210000000;

double cache[201][201][201];

double error(const vi &a, int i, int j) {
	double r = 0;
	for (int k = i + 1; k < j; k++) {
		double x = a[i] + (a[j] - a[i]) * double(k - i) / double (j - i);
		r += abs(x - a[k]);
	}
	return r;
}

double s(const vi &a, int c, int i, int j, int k) {
	if (j == a.size() - 1) return error(a, i, j);
	if (cache[i][j][k] >= 0) return cache[i][j][k];
	double e = MAX;
	if (k < c - 1) e = min(e, error(a, i, j) + s(a, c, j, j + 1, k + 1));
	if (a.size() - j > c - k) e = min(e, s(a, c, i, j + 1, k));
	cache[i][j][k] = e;
	return e;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 201; i++)
			for (int j = 0; j < 201; j++)
				for (int k = 0; k < 201; k++)
					cache[i][j][k] = -1;
		int h, c;
		cin >> h >> c;
		vi a(h);
		for (int i = 0; i < h; i++) cin >> a[i];
		cout << s(a, c, 0, 1, 1) / h << endl;
	}
}
