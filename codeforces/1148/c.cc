// https://codeforces.com/contest/1148/problem/C
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = tuple<int, int>;
using vii = vector<ii>;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vii p;
  int i = 0;
  while (i < n) {
    if (a[i] == i + 1) {
      i++; continue;
    }
    if (a[i] - (i + 1) >= n / 2) {
      p.push_back({i + 1, a[i]});
      int x = a[i] - 1;
      swap(a[i], a[x]);
      continue;
    }
    if (n - a[i] >= n / 2) {
      p.push_back({i + 1, n});
      p.push_back({n, a[i]});
      int x = a[i] - 1;
      swap(a[i], a[n - 1]);
      swap(a[n - 1], a[x]);
      continue;
    }
    if (i >= n / 2) {
      p.push_back({1, i + 1});
      p.push_back({1, a[i]});
      p.push_back({1, i + 1});
      int x = a[i] - 1;
      swap(a[0], a[i]);
      swap(a[0], a[x]);
      swap(a[0], a[i]);
      continue;
    }
    p.push_back({n, i + 1});
    p.push_back({1, n});
    p.push_back({1, a[i]});
    p.push_back({1, n});
    int x = a[i] - 1;
    swap(a[n - 1], a[i]);
    swap(a[0], a[n - 1]);
    swap(a[0], a[x]);
    swap(a[0], a[n - 1]);
  }
  cout << p.size() << "\n";
  for (ii x : p) {
    int u, v;
    tie(u, v) = x;
    cout << u << " " << v << "\n";
  }
}
