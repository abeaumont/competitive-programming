// https://open.kattis.com/problems/compass
#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int d = b - a;
	if (abs(d) == 180) cout << 180 << endl;
	else if (abs(d) < 180) cout << d << endl;
	else if (d < 0) cout << 360 + d << endl;
	else cout << d - 360 << endl;
}
