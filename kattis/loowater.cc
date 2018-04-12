// https://open.kattis.com/problems/loowater
#include <algorithm>
#include <iostream>

using namespace std;

int a[20001];
int b[20001];

int main() {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + m);
		long long s = 0;
		int i = 0;
		int j = 0;
		while (i < n && j < m) {
			if (a[i] <= b[j]) {
				s += b[j++];
				i++;
			} else j++;
		}
		if (i < n) cout << "Loowater is doomed!\n";
		else cout << s << endl;
	}
}
