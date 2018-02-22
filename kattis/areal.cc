// https://open.kattis.com/problems/areal
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	long long a;
	cin >> a;
	double l = sqrt(a);
	cout << setprecision(20) << fixed << l * 4 << endl;
}
