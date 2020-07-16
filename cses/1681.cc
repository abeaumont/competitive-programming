// https://cses.fi/problemset/task/1681
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using qi = queue<int>;

const ll M = 1000000007;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  vvi g(n);
  vi a(n), dp(n, 0);
  for(int i = 0;i < m; i++){
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    a[v]++;
  }
  qi q;
  for (int i = 0; i < n; i++)
    if (!a[i]) {
      q.push(i);
    }
  dp[0] = 1;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v:g[u]) {
      (dp[v] += dp[u]) %= M;
      a[v]--;
      if(!a[v])
        q.push(v);
    }
  }
  cout << dp[n-1] << '\n';
}
