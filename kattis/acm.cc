// https://open.kattis.com/problems/acm
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
	vector<tuple<int, char, string>> v;
	while (true) {
		int m;
		char p;
		string r;
		cin >> m;
		if (m == -1) break;
		cin >> p >> r;
		v.push_back(make_tuple(m, p, r));
	}
	bool solved[26];
	for (int i = 0; i < 26; i++) solved[i] = false;
	int s = 0;
	int t = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		int m;
		char p;
		string r;
		tie(m, p, r) = v[i];
		if (r == "right") {
			s++;
			t += m;
			solved[p - 'A'] = true;
		} else {
			if (solved[p - 'A']) t += 20;
		}
	}
	cout << s << " " << t << endl;
}
