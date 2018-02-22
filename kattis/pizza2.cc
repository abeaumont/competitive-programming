// https://open.kattis.com/problems/pizza2
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	double a = M_PI * r * r;
	double b = M_PI * (r - c) * (r - c);
	cout << setprecision(20) << fixed << b * 100.0 / a << endl;
}
