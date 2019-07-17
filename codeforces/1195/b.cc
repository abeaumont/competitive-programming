// https://codeforces.com/contest/1195/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  ll s = 0, c = 1;
  while (1) {
    s += c;
    if (s >= k && c + (s - k) == n) break;
    c++;
  }
  cout << s - k << "\n";
}
