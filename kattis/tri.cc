// https://open.kattis.com/problems/tri
#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c) {
		cout << a << "+" << b << "=" << c << endl;
	} else if (a - b == c) {
		cout << a << "-" << b << "=" << c << endl;
	} else if (a * b == c) {
		cout << a << "*" << b << "=" << c << endl;
	} else if (a / b == c && a % b == 0) {
		cout << a << "/" << b << "=" << c << endl;
	} else if (a == b + c) {
		cout << a << "=" << b << "+" << c << endl;
	} else if (a == b - c) {
		cout << a << "=" << b << "-" << c << endl;
	} else if (a == b * c) {
		cout << a << "=" << b << "*" << c << endl;
	} else {
		cout << a << "=" << b << "/" << c << endl;
	}
}
