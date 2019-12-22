// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll M = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vi a(n), b(2001);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 1; i <= 2000; i++)
    b[i] += b[i - 1];
  ll s = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      s += a[i] > a[j];
  ll c = 0;
  for (int i = 0; i < n; i++)
    c += b[a[i] - 1];
  ll m = k * (k - 1) / 2 % M;
  s = (s * k + c * m) % M;
  cout << s << "\n";
}
