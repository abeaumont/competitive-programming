// https://abc087.contest.atcoder.jp/tasks/arc090_a
#include <iostream>

using namespace std;

int value[3][101];
int sum[3][101];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> value[1][i];
	for (int i = 1; i <= n; i++) cin >> value[2][i];
	for (int i = 0; i <= 2; i++) sum[i][0] = 0;
	for (int i = 0; i <= n; i++) sum[0][i] = 0;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = max(sum[i][j - 1], sum[i - 1][j]) + value[i][j];
	cout << sum[2][n] << endl;
}
