// https://open.kattis.com/problems/dicecup
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int main() {
	int m, n;
	cin >> m >> n;
	vi v(m + n + 2, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			v[i + j]++;
		}
	}
	int M = 0;
	for (int i = 0; i < m + n + 2; i++) {
		M = max(M, v[i]);
	}
	si s;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (M == v[i + j]) {
				s.insert(i + j);
			}
		}
	}
	for (int c : s) cout << c << endl;
}
