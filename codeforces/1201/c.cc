// https://codeforces.com/contest/1201/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int i = n / 2;
  ll x = a[i++];
  while (true) {
    while (i < n && a[i] == x) i++;
    if (i < n) {
      ll p = a[i] - x;
      ll q = i - n / 2;
      if (p * q <= k) {
        x = a[i];
        k -= p * q;
      } else {
        x += k / q;
        break;
      }
    } else {
      x += k / (n - n / 2);
      break;
    }
  }
  cout << x << "\n";
}
