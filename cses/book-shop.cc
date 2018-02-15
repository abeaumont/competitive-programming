// https://cses.fi/problemset/task/1158/
#include <iostream>

using namespace std;

int h[1001];
int s[1001];
int a[100002][1001];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 1; i <= x; i++)
		for (int j = 0; j < n; j++) {
			if (h[j] <= i) a[i][j] = max(a[i][j - 1], a[i - h[j]][j - 1] + s[j]);
			else a[i][j] = a[i][j - 1];
		}
	cout << a[x][n - 1] << endl;
}
