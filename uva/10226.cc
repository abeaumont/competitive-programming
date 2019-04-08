// http://uva.onlinejudge.org/external/102/10226.pdf
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < t; i++) {
		map<string, int> m;
		int c = 0;
		while (true) {
			getline(cin, s);
			if (s.empty()) break;
			if (m.count(s)) m[s]++;
			else m[s] = 1;
			c++;
		}
		for (auto it = m.begin(); it != m.end(); it++)
			cout << it->first << " " << setprecision(4) << fixed << double(100 * it->second) / double(c) << endl;
		if (i < t - 1) cout << endl;
	}
}
