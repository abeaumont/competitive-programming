// https://codeforces.com/contest/1536/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 500000;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    map<ll, int> m;
    int d = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'D') d++;
      else
        k++;
      ll g = gcd(d, k);
      ll r = d / g * N + k / g;
      m[r]++;
      cout << m[r] << " \n"[i == n - 1];
    }
  }
}
