// https://codingcompetitions.withgoogle.com/codejam/round/0000000000432bd2/0000000000432a7e
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    ll n, A, B, C, D, x0, y0, M;
    cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
    vector<ll> ps(9);
    ll x = x0, y = y0;
    for (int i = 0; i < n; i++) {
      ps[(x % 3) * 3 + (y % 3)]++;
      x = (A * x + B) % M;
      y = (C * y + D) % M;
    }
    vector<bool> xs(729);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++)
          for (int l = 0; l < 3; l++)
            for (int m = 0; m < 3; m++)
              for (int n = 0; n < 3; n++)
                if ((i + k + m) % 3 == 0 && (j + l + n) % 3 == 0) {
                  int a = (i * 3 + j), b = (k * 3 + l), c = (m * 3 + n);
                  if (a <= b && b <= c) { xs[a * 81 + b * 9 + c] = 1; }
                }
    ll sum = 0;
    for (int i = 0; i < 729; i++)
      if (xs[i]) {
        int a = i / 81, b = i % 81 / 9, c = i % 9;
        if (a == b) sum += ps[a] * (ps[a] - 1) * (ps[a] - 2) / 6;
        else
          sum += ps[a] * ps[b] * ps[c];
      }
    cout << "Case #" << t << ": " << sum << '\n';
  }
}
