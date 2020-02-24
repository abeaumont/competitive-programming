// https://codeforces.com/contest/1313/problem/C2
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvii = vector<vii>;

int n;
vi a;
vvii t;

void build() {
  t.push_back(vii(n));
  for (int i=0; i < n; i++) t[0][i] = {a[i],i};
  for (int i=1, k=2; k <= n; i++, k *= 2) {
    t.push_back(vii(n-k+1));
    for (int j = 0; j <= n-k; j++)
      t[i][j] = min(t[i-1][j], t[i-1][j+k/2]);
  }
}

int m(int a, int b) {
  int d = b-a+1;
  int i = 0, k = 1;
  for (; k*2 <= d; i++, k *= 2);
  return get<1>(min(t[i][a], t[i][b-k+1]));
}

ii f (int i, int j) {
  if (i > j) return {0, -1};
  if (i == j) return {a[i], i};
  int l = m(i, j);
  ll lsum, li, rsum, ri;
  tie(lsum, li) = f(i, l-1);
  lsum += (j-l)*a[l];
  tie(rsum, ri) = f(l+1, j);
  rsum += (l-i)*a[l];
  if (lsum > rsum) return {a[l]+lsum, li};
  return {a[l]+rsum, ri};
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  a = vi(n);
  vi b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  int k = get<1>(f(0, n-1));
  b[k] = a[k];
  ll ml = b[k], mr = b[k];
  for (int j = k - 1; j >= 0; j--)
    ml = min(a[j], ml), b[j] = ml;
  for (int j = k + 1; j < n; j++)
    mr = min(a[j], mr), b[j] = mr;
  for (int i = 0; i < n; i++) cout << b[i] << " \n"[i==n-1];
}
