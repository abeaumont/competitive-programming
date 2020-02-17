// https://open.kattis.com/problems/batmanacci
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k, n--, k--;
  vector<ll> f(2, 1);
  string r = "NA";
  if (n < 2) {
    cout << r[n] << '\n';
    return 0;
  }
  int i = 1;
  while (i < n && f[i-1] <= k) {
    f.push_back(f[i-1] + f[i]);
    i++;
  }
  if (n % 2 != i % 2) i--;
  while (i > 1) {
    if (k >= f[i-2]) {
      k -= f[i-2];
      i--;
    } else i -= 2;
  }
  cout << r[i] << '\n';
}
