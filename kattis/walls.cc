// https://open.kattis.com/problems/walls
#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<int> si;

int best = 5;

void search(si s, si::const_iterator it, int c, int acc) {
	if (it == s.end()) {
		if (acc == 15 && c < best) {
			best = c;
		}
		return;
	}
	int val = *it;
	it++;
	search(s, it, c + 1, acc | val);
	search(s, it, c, acc);
}

int main() {
	int l, w, n, r;
	cin >> l >> w >> n >> r;
	si s;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		int match = 0;
		double px = 0;
		double py = double(-w)/2.0;
		double dx = px - x;
		double dy = py - y;
		if (r * r >= dx * dx + dy * dy) {
			match |= 1;
		}
		px = 0;
		py = double(w)/2.0;
		dx = px - x;
		dy = py - y;
		if (r * r >= dx * dx + dy * dy) {
			match |= 2;
		}
		px = double(-l)/2.0;
		py = 0;
		dx = px - x;
		dy = py - y;
		if (r * r >= dx * dx + dy * dy) {
			match |= 4;
		}
		px = double(l)/2.0;
		py = 0;
		dx = px - x;
		dy = py - y;
		if (r * r >= dx * dx + dy * dy) {
			match |= 8;
		}
		if (match) s.insert(match);
	}
	search(s, s.begin(), 0, 0);
	if (best == 5) {
		cout << "Impossible\n";
	} else {
		cout << best << endl;
	}
}
