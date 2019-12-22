// https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

ll M = 998244353;

ll pow(ll a, ll b, int m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) r = (r * e) % m;
    e = (e * e) % m;
    b >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[0] != 0) {
    cout << "0\n";
    return 0;
  }
  if (a.size() == 1) {
    cout << "1\n";
    return 0;
  }
  sort(a.begin(), a.end());
  if (a[1] != 1) {
    cout << "0\n";
    return 0;
  }
  ll r = 1;
  int p = 1, c = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) c++;
    else if (a[i] != a[i - 1] + 1) {
      cout << "0\n";
      return 0;
    } else {
      (r *= pow(p, c, M)) %= M;
      p = c;
      c = 1;
    }
  }
  (r *= pow(p, c, M)) %= M;
  if (r < 0) r += M;
  cout << r << "\n";
}
