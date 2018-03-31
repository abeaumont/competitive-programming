// https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000524
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int d, n;
		cin >> d >> n;
		double m = -1;
		for (int j = 0; j < n; j++) {
			int k, s;
			cin >> k >> s;
			double l = double(d - k) / double(s);
			if (m < 0) m = l;
			else m = max(m, l);
		}
		cout << "Case #" << i << ": " << setprecision(10) << d / m << endl;
	}
}
