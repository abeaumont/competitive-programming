// https://open.kattis.com/problems/statisticians
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int H = 140, W = 120, F = 1e3, S = 1e4;
int c[F * S + 1], s[H + 1][W + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  ll cnt = 0;
  for (int i = (a - 1) / w + 1; i <= min(h, b); i++)
    for (int j = (a - 1) / i + 1; j <= min(w, b / i); j++) {
      cnt += (h - i + 1) * (w - j + 1);
      for (int y = 0; y + i <= h; y++)
        for (int x = 0; x + j <= w; x++)
          c[ll(s[y + i][x + j] - s[y + i][x] - s[y][x + j] + s[y][x]) * F /
            (i * j)]++;
    }

  ll sum = 0;
  ll m = (cnt / 2) + 1;
  a = -1;
  for (int i = 0; i <= F * S; i++) {
    sum += c[i];
    if (sum >= m - 1 && a < 0) a = i;
    if (sum >= m) {
      b = i;
      break;
    }
  }
  cout << fixed;
  if (cnt & 1) cout << double(b + 0.5) / F << '\n';
  else
    cout << double(a + b + 0.5) / (2 * F) << '\n';
}
