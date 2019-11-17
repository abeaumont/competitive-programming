// https://codeforces.com/contest/1148/problem/E
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = tuple<ll, ll>;
using iii = tuple<ll, ll, ll>;
using vii = vector<ii>;
using viii = vector<iii>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  ll n, x = 0, y = 0, z, a = 0, b = 0;
  cin >> n;
  vii s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> z;
    s[i] = {z, i + 1};
    a += z;
  }
  for (int i = 0; i < n; i++) {
    cin >> z;
    t[i] = {z, i + 1};
    b += z;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (a != b) {
    cout << "NO\n";
    return 0;
  }
  while (get<0>(s[x]) >= get<0>(t[x])) x++;
  while (get<0>(s[y]) <= get<0>(t[y])) y++;
  viii r;
  while (x < n && y < n) {
    if (x > y) {
      cout << "NO\n";
      return 0;
    }
    z = min(get<0>(t[x]) - get<0>(s[x]), get<0>(s[y]) - get<0>(t[y]));
    if (get<0>(s[x]) > get<0>(s[y])) r.push_back({get<1>(s[y]), get<1>(s[x]), z});
    else r.push_back({get<1>(s[x]), get<1>(s[y]), z});
    get<0>(s[x]) += z;
    get<0>(s[y]) -= z;
    while (x < n && y < n && get<0>(s[y]) <= get<0>(t[y])) y++;
    while (x < n && y < n && get<0>(s[x]) >= get<0>(t[x])) x++;
  }
  cout << "YES\n" << r.size() << "\n";
  for (iii q : r) {
    tie(x, y, z) = q;
    cout << x << " " << y << " " << z << endl;
  }
}
