// https://open.kattis.com/problems/ballotboxes
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> ii;
typedef priority_queue<ii> pq;

int main() {
	while (true) {
		int n, b;
		cin >> n >> b;
		if (n == -1) break;
		vi a(n);
		vi c(n, 1);
		for (int i = 0; i < n; i++) cin >> a[i];
		pq q;
		for (int i = 0; i < n; i++) q.push(make_tuple((a[i] - 1) / c[i] + 1, i));
		b -= n;
		while (b--) {
			int i = get<1>(q.top());
			q.pop();
			c[i]++;
			q.push(make_tuple((a[i] - 1) / c[i] + 1, i));
		}
		cout << get<0>(q.top()) << endl;
	}
}
