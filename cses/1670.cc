// https://cses.fi/problemset/task/1670
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;

int n = 9*8*7*6*5*4*3*2;

int index(vi &v) {
  int m = 1, r = 0, k = n / 9;
  for (int i = 0; i < 8; i++) {
    int d = v[i];
    int e = (d - __builtin_popcount(m & ((1 << d) - 1)));
    r += e * k;
    k /= 8 - i;
    m |= (1 << d);
  }
  return r;
}

vi permutation(int r) {
  vi v(9);
  int m = 1, k = n / 9;
  for (int i = 0; i <= 8; i++) {
    int d = r / k;
    int j = 0, l = 1;
    while (j <= d) {
      if (!(m & (1 << l))) j++;
      if (j > d) break;
      l++;
    }
    v[i] = l;
    if (i == 8) break;
    r %= k;
    k /= 8 - i;
    m |= (1 << l);
  }
  return v;
}

int main() {
  int x, a, b;
  vi v(9, 0);
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> x, v[i*3+j] = x;
  int t = index(v);
  vi d(n);
  d[0] = 1;
  queue<int> q;
  q.push(0);
  while (1) {
    tie(x) = q.front();
    q.pop();
    if (t == x) {
      cout << d[x] - 1 << "\n";
      break;
    }
    ii z[] = {{0,1},{1,2},{3,4},{4,5},{6,7},{7,8},{0,3},{1,4},{2,5},{3,6},{4,7},{5,8}};
    vi v = permutation(x);
    for (ii y : z) {
      tie(a, b) = y;
      swap(v[a], v[b]);
      int i = index(v);
      if (!d[i]) {
        d[i] = d[x] + 1;
        q.push(i);
      }
      swap(v[a], v[b]);
    }
  }
}
