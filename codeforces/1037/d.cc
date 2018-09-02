// https://codeforces.com/contest/1037/problem/D
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> si;
typedef vector<si> vsi;

int main() {
  int n;
  cin >> n;
  vsi g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  vi v(n, 0);
  vi e(n);
  for (int i = 0; i < n; i++) {
    cin >> e[i];
    e[i]--;
  }
  if (e[0]) {
    cout << "No\n";
    return 0;
  }
  if (n == 1) {
    cout << "Yes\n";
    return 0;
  }
  deque<int> q;
  q.push_back(0);
  v[0] = 1;
  int i = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop_front();
    auto it = g[u].find(e[i]);
    while (it != g[u].end()) {
      if (v[*it]) {
        cout << "No\n";
        return 0;
      }
      v[*it] = 1;
      q.push_back(*it);
      g[u].erase(it);
      i++;
      if (i == n) {
        cout << "Yes\n";
        return 0;
      }
      it = g[u].find(e[i]);
    }
    for (auto z:g[u])
      if (!v[z]) {
        cout << "No\n";
        return 0;
      }
  }
  cout << "Yes\n";
  return 0;
}
