// https://atcoder.jp/contests/dp/tasks/dp_m
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
const int K = 1e5;
ll dp[K + 1];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k, x;
  cin >> n >> k;
  vector<ll> ans(k + 1), tmp(k + 1);
  ans[0] = 1;
  while (n--) {
    cin >> x;
    x++;
    ll sum = 0;
    for (int i = 0; i <= k; i++) {
      sum += ans[i];
      if (sum >= M) sum -= M;
      if (i >= x) {
        sum -= ans[i - x];
        if (sum < 0) sum += M;
      }
      tmp[i] = sum;
    }
    swap(ans, tmp);
  }
  cout << ans[k] << '\n';
}
