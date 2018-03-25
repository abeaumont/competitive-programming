// https://www.hackerrank.com/challenges/and-xor-or
#include <iostream>
#include <stack>

using namespace std;

typedef stack<int> s;

int main() {
	int n;
	cin >> n;
	s s;
	int m = 0;
	while (n--) {
		int x;
		cin >> x;
		while (!s.empty()) {
			int y = s.top();
			m = max(m, ((x & y) ^ (x | y)) & (x ^ y));
			if (x > y) break;
			s.pop();
		}
		s.push(x);
	}
	cout << m << endl;
}
