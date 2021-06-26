// https://cses.fi/problemset/task/1692
#include <bits/stdc++.h>

using namespace std;
const int N = 15, K = (1 << N);
int g[K][2], n, k;
vector<vector<int>> cc, ci;
vector<bool> s;
string ans;

void dfs(int c) {
  s[c] = 1;
  int u = cc[c][0];
  for (int i = 1; i < cc[c].size(); i++) {
    int v = cc[c][i];
    if (!ci[v].empty() && !s[ci[v][0]]) dfs(ci[v][0]);
    ans.push_back("10"[((u << 1) & (k - 1)) == v]);
    u = v;
  }
}

int main() {
  cin >> n;
  if (n == 1) {
    cout << "01" << endl;
    return 0;
  }
  k = (1 << (n - 1));
  s = vector<bool>(k);
  queue<int> q;
  q.push(0);
  s[0] = 1;
  ci = vector<vector<int>>(k);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 2; i++) {
      if (g[u][i]) continue;
      ci[u].push_back(cc.size());
      cc.push_back(vector<int>(1, u));
      do
        for (int j = 0; j < 2; j++) {
          if (g[u][j]) continue;
          g[u][j] = 1;
          int v = (u << 1) & (k - 1) | j;
          if (!s[v]) s[v] = 1, q.push(v);
          cc.back().push_back(v);
          u = v;
        }
      while (u != cc.back()[0]);
    }
  }
  s = vector<bool>(cc.size());
  ans = string(n - 1, '0');
  for (int x : ci[0]) dfs(x);
  cout << ans << '\n';
}
