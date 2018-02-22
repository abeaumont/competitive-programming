// https://open.kattis.com/problems/cd
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int d = 0;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (s.count(x)) d++;
		}
		cout << d << endl;
	}
}
