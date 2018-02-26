// https://open.kattis.com/problems/problemclassification
#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

typedef tuple<int, string> is;
typedef vector<is> vis;
typedef vector<string> vs;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, vs> msvs;

int main() {
	int n, w;
	cin >> n;
	msvs m;
	vs k(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i] >> w;
		while (w--) {
			string a;
			cin >> a;
			if (m.find(a) == m.end()) {
				m[k[i]] = vs();
			}
			m[a].push_back(k[i]);
		}
	}
	msi c;
	while (true) {
		string a;
		cin >> a;
		if (a.empty()) break;
		for (auto z : m[a]) c[z]++;
	}
	vis v;
	for (auto z : c) v.push_back({z.second, z.first});
	if (v.empty()) {
		sort(k.begin(), k.end());
		for (auto z : k) cout << z << endl;
		return 0;
	}
	sort(v.begin(), v.end(), [](is a, is b) {
			int a1, b1;
			string a2, b2;
			tie(a1, a2) = a;
			tie(b1, b2) = b;
			if (a1 == b1) return a2 < b2;
			return a1 > b1;
	});
	int f = get<0>(v[0]);
	for (auto z : v) {
		string a;
		int b;
		tie(b, a) = z;
		if (b < f) break;
		cout << a << endl;
	}
}
