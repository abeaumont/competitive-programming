// https://open.kattis.com/problems/secretchamber
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> si;
typedef vector<int> vi;

bool s(const vi a[], si &v, char x, char y) {
	if (x == y) return true;
	for (auto c : a[x - 'a']) {
		if (v.count(c)) continue;
		v.insert(c);
		if (s(a, v, c + 'a', y)) return true;
	}
	return false;
}

int main() {
	int m, n;
	cin >> m >> n;
	vi a[26];
	for (int i = 0; i < 26; i++) a[i] = vi();
	for (int i = 0; i < m; i++) {
		char x, y;
		cin >> x >> y;
		if (x == y) continue;
		a[x - 'a'].push_back(y - 'a');
	}
	for (int i = 0; i < n; i++) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) cout << "no\n";
		else {
			bool ok = true;
			for (int j = 0; j < x.size(); j++) {
				si v;
				ok = s(a, v, x[j], y[j]);
				if (!ok) break;
			}
			cout << (ok ? "yes\n" : "no\n");
		}
	}
}
