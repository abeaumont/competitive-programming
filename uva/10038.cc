// https://uva.onlinejudge.org/external/100/10038.pdf
#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (cin.eof()) break;
		vector<bool> v(n - 1, false);
		int a;
		cin >> a;
		for (int i = 1; i < n; i++) {
			int b;
			cin >> b;
			int d = abs(a - b) - 1;
			a = b;
			if (d < 0 || d > n - 2) continue;
			v[d] = true;
		}
		bool ok = true;
		for (int i = 0; i < n - 1; i++)
			if (!v[i]) {
				ok = false;
				break;
			}
		cout << (ok ? "Jolly" : "Not jolly") << endl;
	}
}
