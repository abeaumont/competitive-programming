// https://codeforces.com/contest/1208/problem/D
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;

int n;
vi t;

ll sum(ll k) {
  ll s = 0;
  while (k >= 1) s += t[k], k -= k & -k;
  return s;
}

void init(int x) {
 int k = x + 1;
 while (k <= n) t[k] += x, k += k & -k;
}

void clear(int x) {
  int k = x + 1;
  while (k <= n) t[k] -= x, k += k & -k;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  vi a(m), b(m);
  n = 1;
  while (n <= m) n *= 2;
  t = vi(n + 1);
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++) init(i + 1);
  for (int i = m - 1; i >= 0; i--) {
    int x = -1;
    for (int c = m; c >= 1; c /= 2) while (x + c < m && sum(x + c + 1) <= a[i]) x += c;
    int k = x + 1;
    b[i] = k;
    clear(k);
  }
  for (int i = 0; i < m; i++)
    cout << b[i] << " \n"[i == m - 1];
}
