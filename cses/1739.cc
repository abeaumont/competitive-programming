// https://cses.fi/problemset/task/1739
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int k;
vvi t;

void build() {
  for (int i = k-1; i > 0; i--)
    for (int j = k; j < 2*k; j++)
      t[i][j] = t[i*2][j] + t[i*2+1][j];
  for (int i = 0; i < 2*k; i++)
    for (int j = k-1; j > 0; j--)
      t[i][j] = t[i][j*2] + t[i][j*2+1];
}

void toggle(int y, int x) {
  y += k-1, x += k-1;
  t[y][x] = !t[y][x];
  for (int j = x/2; j > 0; j /= 2)
    t[y][j] = t[y][j*2] + t[y][j*2+1];
  for (int i = y/2; i > 0; i /= 2) {
    t[i][x] = t[i*2][x] + t[i*2+1][x];
    for (int j = x/2; j > 0; j /= 2)
      t[i][j] = t[i][j*2] + t[i][j*2+1];
  }
}

int countx(int y, int l, int r) {
  int c = 0;
  l += k-1, r += k-1;
  while (l <= r) {
    if (l%2 == 1) c += t[y][l++];
    if (r%2 == 0) c += t[y][r--];
    l /= 2, r /= 2;
  }
  return c;
}

int count(int ly, int ry, int lx, int rx) {
  ly += k-1, ry += k-1;
  int c = 0;
  while (ly <= ry) {
    if (ly % 2 == 1) c += countx(ly++, lx, rx);
    if (ry % 2 == 0) c += countx(ry--, lx, rx);
    ly /= 2, ry /= 2;
  }
  return c;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  k = 1;
  while (k < n) k *= 2;
  t = vvi(2*k, vi(2*k));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      if (s[j] == '*') t[i+k][j+k] = 1;
  }
  build();
  while (q--) {
    int t, y1, x1, y2, x2;
    cin >> t >> y1 >> x1;
    if (t == 1) toggle(y1, x1);
    else cin >> y2 >> x2, cout << count(y1, y2, x1, x2) << '\n';;
  }
}
