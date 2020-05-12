// https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/00000000000004c0
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef priority_queue<ii> q;
typedef vector<string> vs;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, c = 0;
		cin >> n;
		q q;
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			c += p;
			q.push(make_tuple(p, j));
		}
		vs v;
		while (!q.empty()) {
			int p, j;
			tie(p, j) = q.top();
			q.pop();
			c--;
			p--;
			if (p) q.push(make_tuple(p, j));
			if (!q.empty() && get<0>(q.top()) * 2 > c) {
				int j2;
				tie(p, j2) = q.top();
				q.pop();
				c--;
				p--;
				if (p) q.push(make_tuple(p, j2));
				v.push_back(string(1, char(j + 'A')) + string(1, char(j2 + 'A')));
			} else {
				v.push_back(string(1, char(j + 'A')));
			}
		}
		cout << "Case #" << i << ":";
		for (auto s : v) cout << " " << s;
		cout << endl;
	}
}
