// https://open.kattis.com/problems/pickupsticks
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;
vector<int> g[N];
int c[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    c[b]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (!c[i]) ans.push_back(i);
  for (int i = 0; i < ans.size(); i++)
    for (int v : g[ans[i]]) {
      c[v]--;
      if (!c[v]) ans.push_back(v);
    }
  if (ans.size() != n) cout << "IMPOSSIBLE\n";
  else
    for (int x : ans) cout << x + 1 << '\n';
}
