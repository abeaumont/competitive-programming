// https://open.kattis.com/problems/busyschedule
#include <algorithm>
#include <iostream>

using namespace std;

string x[101];

int main() {
	bool f = true;
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		getline(cin, x[0]);
		for (int i = 0; i < n; i++) getline(cin, x[i]);
		sort(x, x + n, [](string& a, string& b) -> bool {
				int ha, ma, hb, mb;
				char za, zb;
				sscanf(a.c_str(), "%d:%d %c.m.", &ha, &ma, &za);
				sscanf(b.c_str(), "%d:%d %c.m.", &hb, &mb, &zb);
				if (za == zb) {
					if (ha == hb)
						return ma < mb;
					if (ha == 12) return true;
					if (hb == 12) return false;
					return ha < hb;
				}
				return za < zb;
		});
		if (f) f = !f;
		else cout << endl;
		for (int i = 0; i < n; i++) cout << x[i] << endl;
	}
}
