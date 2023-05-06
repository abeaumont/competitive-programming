// https://www.aceptaelreto.com/problem/statement.php?id=104
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll check() {
  ll pi, di, pd, dd;
  cin >> pi >> di >> pd >> dd;
  if (!pi && !di && !pd && !dd) return -2;
  if (!pi) pi = check();
  if (!pd) pd = check();
  if (pi < 0 || pd < 0) return -1;
  if (pi * di != pd * dd) return -1;
  return pi + pd;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    ll c = check();
    if (c < -1) break;
    cout << (c < 0 ? "NO\n" : "SI\n");
  }
}
