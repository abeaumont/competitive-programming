// https://codeforces.com/contest/1208/problem/C
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi a;

void f(int xo, int yo, int ko, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      a[yo + i][xo + j] = ko + i * n + j;
  }
}

int main() {
  int n;
  cin >> n;
  a = vvi(n, vi(n));
  int x = 2;
  while (x * 2 <= n) x *= 2;
  f(0, 0, 0, x);
  int xo = x, ko = x * x;
  for (x /= 2; xo < n; x /= 2) {
    if (xo + x > n) continue;
    for (int i = 0; i < xo; i += x) {
      f(xo, i, ko, x);
      ko += x * x;
    }
    for (int i = 0; i < xo; i += x) {
      f(i, xo, ko, x);
      ko += x * x;
    }
    f(xo, xo, ko, x);
    ko += x * x;
    xo += x;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << a[i][j] << " \n"[j == n - 1];
}
