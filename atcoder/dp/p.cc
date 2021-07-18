// https://atcoder.jp/contests/dp/tasks/dp_p
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
const int N = 1e5;
ll dp[N][2];
vector<int> g[N];
int n;

void dfs(int u, int p) {
  for (int v : g[u])
    if (v != p) dfs(v, u);
  dp[u][0] = dp[u][1] = 1;
  for (int v : g[u])
    if (v != p) {
      (dp[u][0] *= (dp[v][0] + dp[v][1]) % M) %= M;
      (dp[u][1] *= dp[v][0]) %= M;
    }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  cout << (dp[0][0] + dp[0][1]) % M << '\n';
}
