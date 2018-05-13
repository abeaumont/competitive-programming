// https://uva.onlinejudge.org/external/1/108.pdf
#include <iostream>

using namespace std;

int a[101][101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i) a[i][j] += a[i - 1][j];
			if (j) a[i][j] += a[i][j - 1];
			if (i && j) a[i][j] -= a[i - 1][j - 1];
		}
	int m = - 127 * 101 * 101;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			for (int k = i + 1; k < n; k++)
				for (int l = j + 1; l < n; l++) {
					int r = a[k][l];
					if (i) r -= a[i - 1][l];
					if (j) r -= a[k][j - 1];
					if (i && j) r += a[i - 1][j - 1];
					m = max(m, r);
				}
	cout << m << endl;
}
