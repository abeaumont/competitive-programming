// https://open.kattis.com/problems/abandonedanimal
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_map<string, int> msi;
typedef unordered_map<int, int> mii;
typedef vector<vi> vvi;
typedef vector<mii> vmi;

vmi cache;

int s(const vvi &a, const vi& p, int i, int j) {
	if (i == p.size()) return 1;
	if (cache[i].count(j)) return cache[i][j];
	int c = 0;
	for (auto k : a[p[i]])
		if (k >= j) c += s(a, p, i + 1, k);
	cache[i][j] = c;
	return c;
}

int main() {
	int n, k, q;
	cin >> n >> k;
	vvi a;
	vs mi;
	msi m;
	for (int i = 0; i < k; i++) {
		int x;
		string s;
		cin >> x >> s;
		if (!m.count(s)) {
			m[s] = mi.size();
			mi.push_back(s);
			a.push_back(vi());
		}
		a[m[s]].push_back(x);
	}
	cin >> q;
	cache = vmi(q);
	vi p(q);
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		p[i] = m[s];
	}
	switch (s(a, p, 0, 0)) {
	case 0:
		cout << "impossible\n";
		break;
	case 1:
		cout << "unique\n";
		break;
	default:
		cout << "ambiguous\n";
		break;
	}
}
