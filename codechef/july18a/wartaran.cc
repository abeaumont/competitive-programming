// https://www.codechef.com/JULY18A/problems/WARTARAN
// Naive implementation based on a simple greedy
#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <tuple>
 
using namespace std;
 
typedef tuple<int, int> ii;
 
const int N = 1000;
int m[N][N], t, n, a, b, c[N], d[N], e, f, h;
ii p[N], q[N];
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		h = a + b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> m[i][j];
		for (int i = 0; i < n; i++) {
			int s = 0;
			for (int j = 0; j < n; j++)
				if (m[i][j]) s++;
			p[i] = {s, i};
			q[i] = {s, i};
		}
		sort(p, p + n);
		sort(q, q + n, greater<ii>());
 
		for (int i = 0; i < n; i++) c[i] = 1;
 
		for (int i = 0; i < n; i++) {
			cout << c[i];
			if (i != n - 1) cout << " ";
		}
		cout << endl;
 
		for (int i = 0; i < n; i++) cin >> d[i];
 
		for (int i = 0; i < n / h; i++) {
			int k = 0, l = 0;
			for (int j = 0; j < a; j++) {
				while (k < n) {
					int kk = get<1>(p[k]), ll = get<1>(q[l]);
					if (!c[kk]) {
						k++;
						continue;
					}
					if (!d[ll]) {
						l++;
						if (l == n) {
							l = 0;
							k++;
						}
						continue;
					}
					if (m[kk][ll]) {
						cout << kk + 1 << " " << ll + 1 << endl;
						c[kk]--;
						d[ll]--;
						break;
					}
					l++;
					if (l == n) {
						l = 0;
						k++;
					}
				}
				if (k == n) {
					k = 0;
					l = 0;
					while (!c[k]) k++;
					while (!d[l]) l++;
					cout << k + 1 << " " << l + 1 << endl;
					c[k]--;
					d[l]--;
				}
			}
 
			for (int i = 0; i < b; i++) {
				cin >> e >> f;
				c[e - 1]--;
				d[f - 1]--;
			}
		}
	}
}
