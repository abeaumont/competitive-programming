// https://open.kattis.com/problems/almostperfect
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> si;
typedef vector<int> vi;
typedef vector<si> vsi;

void primes(vi &p) {
	p.push_back(2);
	for (int i = 3; i <= 31623; i++) {
		bool a = true;
		for (auto x : p) {
			if (x * x > i) break;
			if (!(i % x)) {
				a = false;
				break;
			}
		}
		if (a) p.push_back(i);
	}
}

void factors(const vi& p, vi &f, int n) {
	int i = 2;
	for (auto x : p) {
		while (!(n % x)) {
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1) f.push_back(n);
}

void divisors(vsi &c, const vi &f, si &d, int n, int i, int k) {
	if (i == f.size()) {
		if (k < n) d.insert(k);
		return;
	}
	if (c[i].count(k)) return;
	c[i].insert(k);
	divisors(c, f, d, n, i + 1, k);
	divisors(c, f, d, n, i + 1, k * f[i]);
}

int main() {
	vi p;
	string l;
	primes(p);
	while (getline(cin, l)) {
		stringstream in(l);
		int n;
		in >> n;
		vi f;
		factors(p, f, n);
		si d;
		vsi c(f.size());
		divisors(c, f, d, n, 0, 1);
		int s = 0;
		for (auto k : d) s += k;
		if (s == n) cout << n << " perfect\n";
		else if (abs(s - n) <= 2) cout << n << " almost perfect\n";
		else cout << n << " not perfect\n";
	}
}
