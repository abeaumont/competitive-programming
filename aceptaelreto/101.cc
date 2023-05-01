// https://www.aceptaelreto.com/problem/statement.php?id=101
#include <bits/stdc++.h>

using namespace std;
const int N = 1024;
int x[N * N], n, cm;

bool d() {
  cm = 0;
  for (int i = 0; i < n; i++) cm += x[i];
  for (int i = 1; i < n; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) s += x[i * n + j];
    if (s != cm) return 0;
  }
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) s += x[j * n + i];
    if (s != cm) return 0;
  }
  int s = 0;
  for (int i = 0; i < n; i++) s += x[i * n + i];
  if (s != cm) return 0;
  s = 0;
  for (int i = 0; i < n; i++) s += x[i * n + n - i - 1];
  if (s != cm) return 0;
  return 1;
}

bool e() {
  int cm2 = x[0] + x[n - 1] + x[n * n - n] + x[n * n - 1];
  if (cm2 * n != cm * 4) return 0;
  if (n % 2 == 0) {
    int s = x[n / 2 - 1] + x[n / 2] + x[n / 2 * n] + x[(n / 2 - 1) * n] +
            x[n / 2 * n + n - 1] + x[(n / 2 - 1) * n + n - 1] +
            x[n * n - n / 2 - 1] + x[n * n - n / 2];
    if (s != cm2 * 2) return 0;
    s = x[n / 2 * (n + 1)] + x[n / 2 * (n + 1) - 1] + x[(n / 2 - 1) * (n + 1)] +
        x[(n / 2 - 1) * (n + 1) + 1];
    if (s != cm2) return 0;
  } else {
    int s =
        x[n / 2] + x[n * n - n / 2 - 1] + x[n / 2 * n] + x[n / 2 * n + n - 1];
    if (s != cm2) return 0;
    if (x[n * n / 2] * 4 != cm2) return 0;
  }
  vector<bool> used(n * n + 1);
  for (int i = 0; i < n * n; i++) {
    if (x[i] < 1 || x[i] > n * n) return 0;
    if (used[x[i]]) return 0;
    used[x[i]] = 1;
  }
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    cin >> n;
    if (!n) break;
    for (int i = 0; i < n * n; i++) cin >> x[i];
    if (d()) {
      if (e()) cout << "ESOTERICO\n";
      else
        cout << "DIABOLICO\n";
    } else
      cout << "NO\n";
  }
}
