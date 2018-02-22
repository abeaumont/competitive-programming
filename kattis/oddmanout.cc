// https://open.kattis.com/problems/oddmanout
#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		set<int> s;
		int g;
		cin >> g;
		for (int j = 0; j < g; j++) {
			int x;
			cin >> x;
			if (s.count(x)) {
				s.erase(x);
			} else {
				s.insert(x);
			}
		}
		cout << "Case #" << i + 1 << ": " << *s.begin() << endl;
	}
}
