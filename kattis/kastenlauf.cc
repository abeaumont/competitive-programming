// https://open.kattis.com/problems/kastenlauf
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<bool> vb;
typedef vector<ii> vii;

bool s(const vii &a, vb &v, int i) {
	if (i == a.size() - 1) return true;
	v[i] = true;
	for (int j = 0; j < a.size(); j++) {
		if (v[j]) continue;
		int x1, y1, x2, y2;
		tie(x1, y1) = a[i];
		tie(x2, y2) = a[j];
		if (abs(x1 - x2) + abs(y1 - y2) <= 1000) {
			bool ok = s(a, v, j);
			if (ok) return ok;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n;
		vii a(n + 2);
		for (int i = 0; i <= n + 1; i++) {
			cin >> x >> y;
			a[i] = make_tuple(x, y);
		}
		vb v(n + 2);
		if (s(a, v, 0)) cout << "happy\n";
		else cout << "sad\n";
	}
}
