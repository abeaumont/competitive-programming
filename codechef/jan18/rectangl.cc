// https://www.codechef.com/JAN18/problems/RECTANGL
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x[4];
		for (int j = 0; j < 4; j++) cin >> x[j];
		sort(x, x+4);
		cout << (x[0] == x[1] && x[2] == x[3] ? "YES\n" : "NO\n");
	}
}
