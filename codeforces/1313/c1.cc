// https://codeforces.com/contest/1313/problem/C1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll best = 0, k = 0;
  for (int i = 0; i < n; i++) {
    ll ml = a[i], mr = a[i], sum = a[i];
    for (int j = i - 1; j >= 0; j--)
      ml = min(a[j], ml), sum += ml;
    for (int j = i + 1; j < n; j++)
      mr = min(a[j], mr), sum += mr;
    if (sum > best) best = sum, k = i;
  }
  vi b(n);
  b[k] = a[k];
  ll ml = b[k], mr = b[k];
  for (int j = k - 1; j >= 0; j--)
    ml = min(a[j], ml), b[j] = ml;
  for (int j = k + 1; j < n; j++)
    mr = min(a[j], mr), b[j] = mr;
  for (int i = 0; i < n; i++) cout << b[i] << " \n"[i==n-1];
}


