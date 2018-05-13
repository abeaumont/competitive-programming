// https://uva.onlinejudge.org/external/116/11679.pdf
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int main() {
	while (true) {
		int b, n;
		cin >> b >> n;
		if (!n && !b) break;
		vl r(b);
		for (int i = 0; i < b; i++) cin >> r[i];
		for (int i = 0; i < n; i++) {
			int d, c, v;
			cin >> d >> c >> v;
			d--;
			c--;
			r[d] -= v;
			r[c] += v;
		}
		bool ok = true;
		for (int i = 0; i < b; i++) if (r[i] < 0) ok = false;
		cout << (ok ? "S" : "N") << endl;
	}
}
