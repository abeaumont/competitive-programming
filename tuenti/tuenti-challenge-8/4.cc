#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;
typedef queue<iii> q;

int n, m;
char a[1001][1001];
bool v[1001][1001];

int s(int sy, int sx, int py, int px) {
	q q;
	q.push({sy, sx, 0});
	v[sy][sx] = true;
	int c = 0;
	while (!q.empty()) {
		int y, x, k;
		tie(y, x, k) = q.front();
		q.pop();
		if (y == py && x == px) {
			c = k;
			break;
		}
		v[y][x] = true;
		if (a[y][x] == '*') {
			int r[] = {2, 2, -2, -2, 4, 4, -4, -4};
			int s[] = {4, -4, 4, -4, 2, -2, 2, -2};
			for (int i = 0; i < 8; i++) {
				int dy = y + r[i];
				int dx = x + s[i];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && a[dy][dx] != '#' && !v[dy][dx]) {
					v[dy][dx] = true;
					q.push({dy, dx, k + 1});
				}
			}
		} else {
			int r[] = {1, 1, -1, -1, 2, 2, -2, -2};
			int s[] = {2, -2, 2, -2, 1, -1, 1, -1};
			for (int i = 0; i < 8; i++) {
				int dy = y + r[i];
				int dx = x + s[i];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && a[dy][dx] != '#' && !v[dy][dx]) {
					v[dy][dx] = true;
					q.push({dy, dx, k + 1});
				}
			}
		}
	}
	return c;
}

int main() {
	int c;
	cin >> c;
	for (int t = 1; t <= c; t++) {
		int px, py, sx, sy, dx, dy;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				v[i][j] = false;
				if (a[i][j] == 'P') {
					py = i; px = j;
				} else if (a[i][j] == 'S') {
					sy = i; sx = j;
				} else if (a[i][j] == 'D') {
					dy = i; dx = j;
				}
			}
		int c1 = s(sy, sx, py, px);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) v[i][j] = false;
		int c2 = s(py, px, dy, dx);
		cout << "Case #" << t << ": ";
		if (!c1 || !c2) cout << "IMPOSSIBLE\n";
		else cout << c1 + c2 << endl;
	}
}
