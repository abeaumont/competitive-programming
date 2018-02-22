// https://open.kattis.com/problems/artichoke
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	double M = p * (sin(a * 1 + b) + cos(c * 1 + d) + 2);
	double m = M;
	double best = 0.0;
	for (int k = 2; k <= n; k++) {
		double x = p * (sin(a * k + b) + cos(c * k + d) + 2);
		if (x > M) {
			M = x;
			m = x;
		} else {
			m = min(x, m);
		}
		best = max(best, M - m);
	}
	cout << setprecision(10) << fixed << best << endl;
}
