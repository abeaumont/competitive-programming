// https://open.kattis.com/problems/muzicari
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> si;

const int T = 5000;

int inline key(int i, int sa) { return i * (T + 1) + sa; }
si cache;

bool search(const vi &v, vi &a, vi &b, int i, int sa, int sb, int t) {
	if (i == v.size()) return true;
	int k = key(i, sa);
	if (cache.count(k)) return false;
	if (sa + v[i] <= t) {
		a.push_back(i);
		if (search(v, a, b, i + 1, sa + v[i], sb, t)) return true;
		a.pop_back();
	}
	if (sb + v[i] <= t) {
		b.push_back(i);
		if (search(v, a, b, i + 1, sa, sb + v[i], t)) return true;
		b.pop_back();
	}
	cache.insert(k);
	return false;
}

int main() {
	int t, n;
	cin >> t >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vi v(n), a, b;
	for (int i = 0; i < n; i++) cin >> v[i];
	search(v, a, b, 0, 0, 0, t);
	int suma = 0;
	int sumb = 0;
	int j = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (j < a.size() && i == a[j]) {
			cout << suma;
			suma += v[i];
			j++;
		} else {
			cout << sumb;
			sumb += v[i];
			k++;
		}
		if (i < n - 1) cout << " ";
	}
	cout << endl;
}
