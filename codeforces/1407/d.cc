// https://codeforces.com/contest/1407/problem/D
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vvi g(n);
  vi s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.back()] > a[i]) {
      g[s.back()].push_back(i);
      s.pop_back();
    }
    if (!s.empty()) {
      g[s.back()].push_back(i);
      if (a[s.back()] == a[i]) s.pop_back();
    }
    s.push_back(i);
  }
  s.clear();
  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.back()] < a[i]) {
      if (a[s.back()] < a[i]) g[s.back()].push_back(i);
      s.pop_back();
    }
    if (!s.empty()) {
      g[s.back()].push_back(i);
      if (a[s.back()] == a[i]) s.pop_back();
    }
    s.push_back(i);
  }
  qi q;
  vi d(n);
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == n - 1) break;
    for (int v : g[u]) {
      if (v && !d[v]) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  cout << d[n - 1] << '\n';
}
