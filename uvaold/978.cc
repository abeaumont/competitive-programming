// http://uva.onlinejudge.org/external/9/978.pdf
#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> pqi;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int b, sg, sb;
		cin >> b >> sg >> sb;
		pqi x;
		for (int j = 0; j < sg; j++) {
			int a;
			cin >> a;
			x.push(a);
		}
		pqi y;
		for (int j = 0; j < sb; j++) {
			int a;
			cin >> a;
			y.push(a);
		}
		vector<int> v(b);
		while (!x.empty() && !y.empty()) {
			int l = min((long unsigned)b, min(x.size(), y.size()));
			for (int j = 0; j < l; j++) {
				int a = x.top();
				x.pop();
				int b = y.top();
				y.pop();
				v[j] = a - b;
			}
			for (int j = 0; j < l; j++) {
				if (v[j] > 0) x.push(v[j]);
				else if (v[j] < 0) y.push(-v[j]);
			}
		}
		if (x.empty() && y.empty()) cout << "green and blue died\n";
		else if (y.empty()) {
			cout << "green wins\n";
			while (!x.empty()) {
				cout << x.top() << endl;
				x.pop();
			}
		} else {
			cout << "blue wins\n";
			while (!y.empty()) {
				cout << y.top() << endl;
				y.pop();
			}
		}
		if (i < t - 1) cout << endl;
	}
}
