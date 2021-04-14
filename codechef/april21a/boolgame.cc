// https://www.codechef.com/APRIL21A/problems/BOOLGAME
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using si = set<ll>;
using vsi = vector<si>;
using vvsi = vector<vsi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vi g(n), u(m), v(m), d(m);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> d[i], u[i]--, v[i]--;
    vvsi dp(n + 1, vsi(n + 1));
    dp[0][0].insert(0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++)
        for (ll x : dp[i][j]) {
          x += g[i];
          for (int o = 0; o < m; o++)
            if (u[o] >= j && v[o] == i) x += d[o];
          dp[i + 1][j].insert(x);
        }
      dp[i + 1][i + 1].insert(0);
      for (int j = 0; j <= i; j++)
        for (auto it = dp[i][j].rbegin(); it != dp[i][j].rend(); it++) {
          if (dp[i + 1][i + 1].size() == k && *it <= *dp[i + 1][i + 1].begin())
            break;
          dp[i + 1][i + 1].insert(*it);
          if (dp[i + 1][i + 1].size() > k)
            dp[i + 1][i + 1].erase(dp[i + 1][i + 1].begin());
        }
    }
    vector<ll> ans;
    for (int i = 0; i <= n; i++)
      for (ll x : dp[n][i]) ans.push_back(x);
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < k; i++) cout << ans[i] << " \n"[i == k - 1];
  }
}
