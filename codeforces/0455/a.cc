// https://codeforces.com/contest/455/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100000;
ll a[N+1], dp[N+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= N; i++) a[i] *= i;
  dp[0] = 0, dp[1] = a[1], dp[2] = a[2];
  for (int i = 3; i <= N; i++)
    dp[i] = a[i] + max(dp[i-2], dp[i-3]);
  ll r = max(dp[N-1], dp[N]);
  cout << r << '\n';
}
