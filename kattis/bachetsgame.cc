// https://open.kattis.com/problems/bachetsgame
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	while (true) {
		getline(cin, s);
		if (s.empty()) break;
		stringstream in(s);
		int n, m;
		in >> n >> m;
		vi a(n + 1, 0), b(m);
		for (int i = 0; i < m; i++) in >> b[i];
		for (int i = 1; i <= n; i++) {
			int c = 0;
			for (int j = 0; j < m; j++)
				if (i >= b[j]) c |= (1 << a[i - b[j]]);
			for (int j = 0; j <= m; j++) {
				if ((c & (1 << j)) == 0) {
					a[i] = j;
					break;
				}
			}
		}
		cout << (a[n] ? "Stan wins\n" : "Ollie wins\n");
	}
}
