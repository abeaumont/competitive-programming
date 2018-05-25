// https://open.kattis.com/problems/opensource
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef unordered_map<string, int> msi;

int main() {
	while (true) {
		msi a, n2i;
		vi b;
		vs i2n;
		string s, t;
		int k = -1;
		while (true) {
			getline(cin, s);
			if (s == "0" || s == "1") break;
			if (isupper(s[0])) {
				n2i[s] = ++k;
				i2n.push_back(s);
				b.push_back(0);
			} else {
				if (a.count(s)) {
					if (a[s] != k && a[s] >= 0) {
						b[a[s]]--;
						a[s] = -1;
					}
				} else {
					a[s] = k;
					b[k]++;
				}
			}
		}
		vii c;
		for (int i = 0; i < b.size(); i++) c.push_back({i, b[i]});
		sort(c.begin(), c.end(), [&i2n](ii a, ii b) {
				int a1, a2, b1, b2;
				tie(a1, a2) = a;
				tie(b1, b2) = b;
				if (a2 > b2 || a2 == b2 && i2n[a1] < i2n[b1]) return true;
				return false;
		});
		for (ii z:c) {
			int a1, a2;
			tie(a1, a2) = z;
			cout << i2n[a1] << " " << a2 << endl;
		}
		if (s == "0") break;
	}
}
