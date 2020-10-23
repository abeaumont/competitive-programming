// https://open.kattis.com/problems/froshweek
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

vi a;

ll f(int i, int j) {
  if (i == j) return 0;
  int m = (i + j) / 2;
  ll c = 0;
  c += f(i, m);
  c += f(m + 1, j);
  vi t(j - i + 1);
  int k = i, l = m + 1, b = 0;
  while (k <= m && l <= j)
    if (a[k] < a[l]) t[b++] = a[k++];
    else t[b++] = a[l++], c += (m - k + 1);
  while (k <= m) t[b++] = a[k++];
  while (l <= j) t[b++] = a[l++];
  for (int k = 0; k < b; k++) a[i + k] = t[k];
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  a = vi(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << f(0, n - 1) << '\n';
}
