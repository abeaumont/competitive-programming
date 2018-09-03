// https://abc054.contest.atcoder.jp/tasks/abc054_d
#include <iostream>

using namespace std;

const int N=40, INF=1000000000;
int a[N], b[N], c[N], d[N*10+1][N*10+1][N+1];

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
  for (int i = 0; i <= N*10; i++)
    for (int j = 0; j <= N*10; j++)
      for (int k = 0; k <= n; k++)
        d[i][j][k] = INF;
  for (int k = 0; k <= n; k++)
    d[0][0][k] = 0;
  for (int i = 1; i <= N*10; i++)
    for (int j = 1; j <= N*10; j++)
      for (int k = 1; k <= n; k++) {
        d[i][j][k] = d[i][j][k-1];
        if (a[k-1] <= i && b[k-1] <= j)
          d[i][j][k] = min(d[i][j][k], d[i-a[k-1]][j-b[k-1]][k-1]+c[k-1]);
      }
  int M = INF;
  for (int i = 1; i*ma<=N*10&&i*mb<=N*10; i++) M = min(M, d[ma*i][mb*i][n]);
  cout << (M == INF ? -1 : M) << endl;
}
