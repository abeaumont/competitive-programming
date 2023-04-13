// https://open.kattis.com/problems/joinstrings
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int> g[N];
string xs[N];
bool s[N];

void dfs(int u) {
  cout << xs[u];
  for (int v : g[u]) dfs(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, u, v;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> xs[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    s[v] = 1;
  }
  for (int i = 0; i < n; i++)
    if (!s[i]) {
      dfs(i);
      break;
    }
  cout << '\n';
}
