// https://abc086.contest.atcoder.jp/tasks/arc089_b
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;

int main() {
  int n, k;
  cin >> n >> k;
  vi x(n);
  vi y(n);
  vc c(n);
  vvi v(k * 2);
  for (int i = 0; i < k * 2; i++) v[i] = vi(k * 2, 0);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
  for (int i = 0; i < n; i++) {
    if (c[i] == 'W') y[i] += k;
    x[i] %= 2 * k;
    y[i] %= 2 * k;
    v[y[i]][x[i]]++;
  }
  for (int i = 1; i < 2 * k; i++) {
    v[0][i] += v[0][i - 1];
  }
  for (int i = 1; i < 2 * k; i++) {
    v[i][0] += v[i - 1][0];
  }
  for (int i = 1; i < 2 * k; i++) {
    for (int j = 1; j < 2 * k; j++) {
      v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
    }
  }
  int m = 0;
  for (int i = - k; i < k; i++)
    for (int j = - k; j < k; j++) {
      int s = 0;
      for (int a = i, d = 0; a <= 2 * k; a += k, d++) {
        for (int b = j - (d%2) * k; b <= 2 * k; b += 2 *k) {
          if (a <= -k) continue;
          if (b <= -k) continue;
          int yi = min(a + k - 1, 2 * k - 1);
          int xi = min(b + k - 1, 2 * k - 1);
          s += v[yi][xi];
          if (a > 0) {
            s -= v[a - 1][xi];
          }
          if (b > 0) {
            s -= v[yi][b - 1];
          }
          if (a > 0 && b > 0) {
            s += v[a - 1][b - 1];
          }
        }
      }
      m = max(m, s);
    }
  cout << m << endl;
}
