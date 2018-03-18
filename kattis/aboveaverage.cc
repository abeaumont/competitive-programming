// https://open.kattis.com/problems/aboveaverage
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<double> vd;

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vd a(n);
		double s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		sort(a.begin(), a.end());
		double c = a.end() - upper_bound(a.begin(), a.end(), s/n);
		cout << fixed << setprecision(3) << double(c * 100) / n << "%\n";
	}
}
