// https://www.hackerrank.com/challenges/maximum-element
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> q;
	int n, t, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		switch (t) {
		case 1:
			cin >> x;
			if (q.empty()) q.push(x);
			else q.push(max(x, q.top()));
			break;
		case 2:
			q.pop();
			break;
		case 3:
			cout << q.top() << endl;
			break;
		}
	}
}
