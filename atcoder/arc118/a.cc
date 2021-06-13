// https://atcoder.jp/contests/arc118/tasks/arc118_a
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n;
  cin >> t >> n;
  ll m = (n * 100 - 1) / t + 1;
  cout << m + n - 1 << '\n';
}
