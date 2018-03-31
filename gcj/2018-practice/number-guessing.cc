// https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, n;
		cin >> a >> b >> n;
		a++;
		for (int i = 0; i < n; i++) {
			int t = (a + b) / 2;
			cout << t << endl;
			string s;
			cin >> s;
			if (s == "CORRECT") break;
			else if (s == "TOO_BIG") b = t - 1;
			else if (s == "TOO_SMALL") a = t + 1;
			else break;
		}
	}
}
