// http://uva.onlinejudge.org/external/112/11286.pdf
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef map<vi, int> mvii;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		mvii m;
		int M = 0;
		for (int i = 0; i < n; i++) {
			vi x(5);
			for (int j = 0; j < 5; j++) cin >> x[j];
			sort(x.begin(), x.end());
			int c = m.count(x);
			if (c) m[x]++;
			else m[x] = 1;
			M = max(M, m[x]);
		}
		int c = 0;
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second == M) c += M;
		}
		cout << c << endl;
	}
}
