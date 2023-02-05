// https://codingcompetitions.withgoogle.com/codejam/round/00000000004330f6/0000000000432f33
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll> &a, vector<ll> &b) {
  ll p = 0;
  for (int i = 0; i < a.size(); i++) p += a[i] * b[i];
  return p;
}

int main() {
  int t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    printf("Case #%d: %lld\n", T, solve(a, b));
  }
}
