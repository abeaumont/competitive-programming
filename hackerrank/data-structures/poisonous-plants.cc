// https://www.hackerrank.com/challenges/poisonous-plants/problem
#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;
typedef stack<ii> sii;

int main() {
	int n, x;
	cin >> n;
	sii s;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (s.empty()) {
			s.push({x, 0});
		} else {
			int a, b;
			tie(a, b) = s.top();
			if (x > a) {
				s.push({x, 1});
				m = max(m, 1);
			} else if (x <= a) {
				int c = 0;
				do {
					s.pop();
					c = max(c, b);
					if (s.empty()) break;
					tie(a, b) = s.top();
				} while (x <= a);
				if (s.empty()) {
					s.push({x, 0});
				} else {
					s.push({x, c + 1});
					m = max(m, c + 1);
				}
			}
		}
	}
	cout << m << endl;
}
