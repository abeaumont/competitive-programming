// https://open.kattis.com/problems/10kindsofpeople
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int find(vi &l, int x) {
	while (x != l[x]) x = l[x];
	return x;
}

void unite(vi &l, vi &s, int a, int b) {
	a = find(l, a);
	b = find(l, b);
	if (a == b) return;
	if (s[a] < s[b]) swap(a, b);
	s[a] += s[b];
	l[b] = a;
}

int main() {
	int r, c;
	cin >> r >> c;
	vi l(r * c), s(r * c, 1);
	vvb a(r);
	for (int i = 0; i < r; i++) {
		a[i] = vb(c, false);
		for (int j = 0; j < c; j++) {
			l[i * c + j] = i * c + j;
			char b;
			cin >> b;
			if (b == '1') a[i][j] = true;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j < c - 1 && a[i][j] == a[i][j + 1])
				unite(l, s, i * c + j, i * c + j + 1);
			if (i < r - 1 && a[i][j] == a[i + 1][j])
				unite(l, s, i * c + j, (i + 1) * c + j);
		}
	}
	int n;
	cin >> n;
	while (n--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		if (find(l, r1 * c + c1) == find(l, r2 * c + c2))
			cout << (a[r1][c1] ? "decimal\n" : "binary\n");
		else cout << "neither\n";
	}
}

