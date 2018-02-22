// https://open.kattis.com/problems/grassseed
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double c;
	int l;
	cin >> c >> l;
	double s = 0.0;
	for (int i = 0; i < l; i++) {
		double w, l;
		cin >> w >> l;
		s += w * l * c;
	}
	cout << setprecision(10) << fixed << s << endl;
}
