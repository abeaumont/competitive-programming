// https://open.kattis.com/problems/numberfun
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b == c || a - b == c || b - a == c || a * b == c || c * b == a || c * a == b) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}
