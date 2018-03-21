// https://www.codechef.com/JAN18/problems/STRMRG
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;

const int M = 5001;
int c1[M * M];
int c2[M * M];

ii f(const string& a, const string& b, int i, int j) {
	int c, d, k, key;
	if (i == a.size() && j == b.size()) return {0, 0};
	key = i * M + j;
	if (c1[key] != -1) return {c1[key], c2[key]};
	if (i == a.size()) {
		tie(c, k) = f(a, b, i, j + 1);
		if (j < b.size() - 1 && b[j] != b[j + 1]) c++;
		c1[key] = c;
		c2[key] = b[j];
		return {c, b[j]};
	}
	if (j == b.size()) {
		tie(c, k) = f(a, b, i + 1, j);
		if (i < a.size() - 1 && a[i] != a[i + 1]) c++;
		c1[key] = c;
		c2[key] = a[i];
		return {c, a[i]};
	}
	tie(c, k) = f(a, b, i + 1, j);
	if (a[i] != k) c++;
	tie(d, k) = f(a, b, i, j + 1);
	if (b[j] != k) d++;
	if (c < d) {
		c1[key] = c;
		c2[key] = a[i];
		return {c, a[i]};
	}
	c1[key] = d;
	c2[key] = b[j];
	return {d, b[j]};
}

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		memset(c1, -1, M * M);
		memset(c2, -1, M * M);
		string a, b;
		cin >> n >> m >> a >> b;
		int x, y;
		tie(x, y) = f(a, b, 0, 0);
		cout << x + 1 << endl;
	}
}
