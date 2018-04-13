// https://open.kattis.com/problems/arbitrage
#include <cstdio>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> msi;
double v[201][201];

int main() {
	while (true) {
		int n, q;
		scanf("%d\n", &n);
		if (!n) break;
		msi m;
		for (int i = 0; i < n; i++) {
			char s[4];
			scanf("%s\n", s);
			m[s] = i;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				v[i][j] = 0;
		scanf("%d\n", &q);
		for (int i = 0; i < q; i++) {
			char s[4], t[4];
			double a, b;
			scanf("%s %s %lf:%lf", s, t, &a, &b);
			int x = m[s];
			int y = m[t];
			v[x][y] = max(v[x][y], b / a);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					v[i][j] = max(v[i][j], v[i][k] * v[k][j]);
		bool ok = true;
		for (int i = 0; i < n; i++)
			if (v[i][i] > 1 + 0.00001) {
				ok = false;
				break;
			}
		if (ok) printf("Ok\n");
		else printf("Arbitrage\n");
	}
}
