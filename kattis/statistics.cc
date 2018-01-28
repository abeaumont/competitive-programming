// https://open.kattis.com/problems/statistics
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	for (int k = 1;; k++) {
		string s;
		getline(cin, s);
		if (s.empty()) break;
		istringstream in(s);
		int n, x;
		in >> n >> x;
		int m = x;
		int M = x;
		for (int i = 1; i < n; i++) {
			in >> x;
			m = min(x, m);
			M = max(x, M);
		}
		cout << "Case " << k << ": " << m << " " << M << " " << M - m << endl;
	}
}
