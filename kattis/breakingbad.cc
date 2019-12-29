// https://open.kattis.com/problems/breakingbad
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi s;
bool ok = 1;

void dfs(int u, int k) {
  s[u] = k;
  for (int v : g[u])
    if (!s[v]) dfs(v, k % 2 + 1);
    else if (s[v] == k) ok = 0;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n;
  map<string, int> map;
  vector<string> items(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    items[i] = s;
    map[s] = i;
  }
  g = vvi(n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s, t;
    cin >> s >> t;
    int u = map[s], v = map[t];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  s = vi(n);
  for (int i = 0; i < n; i++)
    if (!s[i]) dfs(i, 1);
  if (!ok) cout << "impossible\n";
  else
    for (int i = 1; i <= 2; i++) {
      vector<string> r;
      for (int j = 0; j < n; j++)
        if (s[j] == i)
          r.push_back(items[j]);
      for (int j = 0; j < r.size(); j++)
        cout << r[j] << " \n"[j == r.size() - 1];
    }
}
