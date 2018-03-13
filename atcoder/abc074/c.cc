// https://abc074.contest.atcoder.jp/tasks/arc083_a
#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int sugar_water = 0;
	int sugar = 0;
	double density = 0;
	for (int i = 0; i * a * 100 <= f; i++) {
		for (int j = 0; (i * a + j * b) * 100 <= f; j++) {
			for (int k = 0; (i * a + j * b) * 100 + k * c <= f; k++) {
				for (int l = 0; (i * a + j * b) * 100 + k * c + l * d <= f; l++) {
					int w = (i * a + j * b) * 100;
					int need = e * (i * a + j * b);
					int s = k * c + l * d;
					if (s > need) break;
					if (s + w == 0) continue;
					double den = double(100.0 * s) / double(s + w);
					if (den >= density) {
						density = den;
						sugar = s;
						sugar_water = s + w;
					}
				}
			}
		}
	}
	cout << sugar_water << " " << sugar << endl;
}
