// https://open.kattis.com/problems/supercomputer
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi t;
int n;

void add(int k, int x) {
  while (k <= n) {
    t[k] += x;
    k += k & -k;
  }
}

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += t[k];
    k -= k & -k;
  }
  return s;
}

int sum(int i, int j) {
  return sum(j) - sum(i - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> n >> k;
  vi a(n + 1);
  t = vi(n + 1);
  for (int i = 0; i < k; i++) {
    char x;
    int l, r;
    cin >> x >> l;
    if (x == 'F') {
      int d = a[l] ? -1 : 1;
      a[l] += d;
      add(l, d);
    } else {
      cin >> r;
      cout << sum(l, r) << '\n';
    }
  }
}
